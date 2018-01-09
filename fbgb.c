/*****************************************************************************
*	FB-GB
*	by: Alan Haug, email: ajhhja@gmail.com
*
*	I made this as a learning experience. Much of it was trial and error,
*	I got tired of keeping the code neat fairly quickly, please email me
*	if you have any questions about GBDK.
*
*	No copyright infringement intended, this is purely for educational purposes
*
*	Special Thanks:
*		http://sebastianmihai.com/main.php?t=18&
*			sound effects
*		https://archive.org/web/
*			archives of numerous old GB homebrew websites
*		http://gbdk.sourceforge.net/
*
*****************************************************************************/
#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>
#include "background_data.h"
#include "sprite_data.h"
#include "fb_sound.h"

#define MAX_SCORE				32767
#define SCORE_X					0x09
#define SCREEN_TOP_L_VISIBLE_X	8
#define SCREEN_TOP_L_VISIBLE_Y	16
#define TILE_SIZE				8		
#define BIRD_SPR_INDEX			0
#define BIRD_NUM_FRAMES			0x03
#define BIRD_TILES_PER_FRAME	0x04
#define BIRD_ANIM_UP			0x00
#define BIRD_ANIM_DOWN			0x01
#define GROUND_Y				0x80
#define NUM_PIPES				2
#define MAX_PIPE_H				8
#define PIPE_SPRITES_BEGIN		4
#define NUM_TILES_PIPE_ROW		2
#define NUM_SPR_PER_PIPE		(NUM_TILES_PIPE_ROW * (MAX_PIPE_H + 1))
#define PIPE_SPEED				1

#define GS_GAMEPLAY				0
#define	GS_PAUSED				1
#define GS_INTRO				2
#define GS_GAMEOVER				3

#define PROP_OBP1               0x10


typedef struct
{
	UBYTE x;
	UBYTE y;
} point_t;

typedef struct 
{
	UBYTE start_tile;	// the tile pattern this sprite begins at
	UBYTE num_tiles;	// the number of tiles this sprite occupies
	UBYTE width;		// num pixels width
	UBYTE height;		// num pixels height
	point_t pos;		// position of top-left tile of sprite
} sprite_t;

void move_sprite_t_16x16(sprite_t* spr);
void move_bird(BYTE dx, BYTE dy);
void move_pipe_spr(UINT8 index, UINT8 height, UINT8 x, UINT8 y);
void scroll_pipe_spr(UINT8 index, INT8 x, INT8 y);
void animate_bird();
void update_bird(void);
void init_pipes(void);
UBYTE check_collision();
void check_score();
void trans_gameplay_gameover(void);
void trans_gameplay_intro(void);
void draw_score(INT16 val, UBYTE x, UBYTE y);

static UBYTE time;
UBYTE 
	index, 
	bird_cur_frame, 
	bird_anim_state, 
	grav, 
	bPressed_J_A,
	bPressed_J_START,
	bScore_counted,
	bSound_in_progress,	
	game_state;
BYTE bird_vel;
UBYTE ground_index = 0;
UBYTE bOther_numbers = 0;

INT16 pipes_x = MAXWNDPOSX + TILE_SIZE;
INT8 pipe_top_h;
INT8 pipe_bot_h;
INT16 score,hiscore;

point_t bird_pos = {
	SCREEN_TOP_L_VISIBLE_X,
	SCREEN_TOP_L_VISIBLE_Y + (7 * TILE_SIZE)
};
const unsigned char TEST[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,
  0x0C,0x0F,0x10,0x1F,0x78,0x7F,0xFC,0x87,
  0xFE,0x83,0xFE,0x83,0x7C,0x47,0x3F,0x3F,
  0x3F,0x3F,0x1F,0x1F,0x07,0x07,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,
  0x78,0xC8,0xFC,0x84,0xFE,0x8A,0xFE,0x8A,
  0x7E,0xC2,0x3F,0xFF,0x7F,0xC1,0xFF,0xBF,
  0xFF,0xC1,0xFE,0xFE,0xC0,0xC0,0x00,0x00
};


void show_title(sprite_t* bird_spr)
{
	UBYTE i,j, birdX, birdY;
	disable_interrupts();
	wait_vbl_done();
	DISPLAY_OFF;
	LCDC_REG = 0x67;
	HIDE_BKG;
	HIDE_WIN;
	SPRITES_8x8;
	set_bkg_data(0,46, title_main);
	set_bkg_data(117, 16, ground3full_data);
	
	for(i = 0; i < 20; ++i) {
		for(j = 0; j < 18; ++j) {//leave 2 bottom tile rows alone to show ground
			set_bkg_tiles(i,j,1,1, title_main_map + 22);
		}
	}
	
	set_bkg_tiles(3, 4, 9, 3, title_main_map);
	set_bkg_tiles(3, 7, 13, 1, title_main_subs_map+7+9+14);//"(PRESS START)"
	
	set_bkg_tiles(3, 0x0D, 7, 1, title_main_subs_map);			//"ALAN H."
	set_bkg_tiles(3, 0x0E, 9, 1, title_main_subs_map+7);		//"ORIGINAL:"	
	set_bkg_tiles(3, 0x0F, 0x0E, 1, title_main_subs_map+7+9);	//"CGEARS STUDIOS"
		
	set_bkg_tiles(0,0x10,20,2,ground_map_frames[0]);
		
	set_sprite_data(bird_spr->start_tile, 0x0C, flappy_bird_data);
	set_sprite_prop(0,0x00);
	set_sprite_prop(1,0x00);
	set_sprite_prop(2,0x00);
	set_sprite_prop(3,0x00);
	
	set_sprite_tile(0, 0);	//top left of bird
	set_sprite_tile(1, 1);	//bottom left of bird
	set_sprite_tile(2, 2);	//
	set_sprite_tile(3, 3);
	
	birdX = 120;
	birdY = 48;
	move_sprite(0, birdX, birdY); 
	move_sprite(1, birdX,birdY + TILE_SIZE);
	move_sprite(2, birdX + TILE_SIZE, birdY);
	move_sprite(3, birdX + TILE_SIZE, birdY + TILE_SIZE);
	
    /*set_sprite_data(0x10,0x04,TEST);
    set_sprite_tile(0x04, 0x10);
    set_sprite_tile(0x05, 0x11);
    set_sprite_tile(0x06, 0x12);
    set_sprite_tile(0x07, 0x13);
    move_sprite(0x04, 64, 64);
    move_sprite(0x05, 64, 72);
    move_sprite(0x06, 72, 64);
    move_sprite(0x07, 72, 72);*/
    OBP0_REG =  0xD0;
    OBP1_REG =  0xE4;//0xE0;
    
	enable_interrupts();
	SHOW_BKG;
	SHOW_SPRITES;
	DISPLAY_ON;
}


int main(void)
{
	UBYTE input, x, y;
	
	sprite_t bird_spr = {
		BIRD_SPR_INDEX, // bird starts at sprite tile 0
		0x04, // bird sprite contains 4 tiles
		0xF0,
		0xF0,
		{SCREEN_TOP_L_VISIBLE_X, SCREEN_TOP_L_VISIBLE_Y}
	};		
	
	bird_cur_frame = 0;
	bScore_counted = 0x00;
	bird_anim_state = BIRD_ANIM_UP;
	initrand(420);
	
	show_title(&bird_spr);
	sound_init();
	// opening title loop
	while(1) {
		input = joypad();
		if(input & J_START) {
			break;
		}
		else if(input & J_SELECT){ //fun with the palettes
			if(input & J_UP) {
				BGP_REG++;
			} else if(input & J_DOWN) {
				BGP_REG--;
			} else if(input & J_RIGHT) {
				OBP0_REG++;
			} else if(input & J_LEFT) {
				OBP0_REG--;
			} else if(input & J_A) { // change the score font
				sound_you_die();
				bOther_numbers = !bOther_numbers;
				waitpadup();
			}
			
		}
		for(index = 0; index < 1; ++index) wait_vbl_done();				
		time++;
		if(time >= 0xFF) { time = 0x00; }

		animate_bird();
		ground_index = (ground_index + 1) % 8; 
		set_bkg_tiles(0,0x10,20,2,ground_map_frames[ground_index]);
	}
	
	
	disable_interrupts();
	wait_vbl_done();
	DISPLAY_OFF;
	
	LCDC_REG = 0x67;
	SPRITES_8x8;
	HIDE_WIN;
    
	
	set_bkg_data(0,117, full_bg_tiles2);
	if(bOther_numbers) {
		set_bkg_data(0x85, 0x0A, numbers_data2);
	}
	else {
		set_bkg_data(0x85, 0x0A, numbers_data);
	}
	set_bkg_data(0x90, 0x24, title_getready_data);
	set_bkg_data(0xB4, 0x0E, title_tap_data);
	set_bkg_data(0xC2, 7, title_score_data);
	set_bkg_data(0xC9, 36, title_gameover_data);
	set_bkg_tiles(0,0,20,16, full_bg_map2);
	set_bkg_tiles(4, 1, 0x0C, 0x03, title_getready_map);
	set_bkg_tiles(6, 4, 0x08, 0x02, title_tap_map);
	for(x = 0; x < 0x0E; ++x) {
		set_bkg_tiles(3 + x, 0, 0x01, 0x01, numbers_map + 0x0A);
	}
	for(y = 0; y < 5; ++y) {
		set_bkg_tiles(3, 1+y, 0x01, 0x01, numbers_map + 0x0A);
		set_bkg_tiles(0x10, 1+y, 0x01, 0x01, numbers_map + 0x0A);
	}
	set_bkg_tiles(5, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(5, 5, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0E, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0E, 5, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(4, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(4, 5, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0F, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0F, 5, 1, 1, numbers_map + 0x0A);
	
	/* Initialize the window */
	/*set_bkg_data(117, 16, ground3full_data);
	set_bkg_tiles(0,0x10,20,2,ground_map_frames[0]);
	for(x = 0; x < 0x13; ++x) {
		for(y = 0; y < 0x11; ++y) {
			set_win_tiles(x,y,1,1, numbers_map + 0x0A);
		}
	}
	set_win_tiles(0,0,20,2,ground_map_frames[0]);
	set_win_tiles(0,0,0x1F,2,ground_map_scroll);
	WX_REG = 0;
	WY_REG = 0;
	*/
	
	score = 0;
	hiscore = 0;
	
	set_sprite_data(bird_spr.start_tile, 0x0C, flappy_bird_data);	
	set_sprite_prop(0,0x00);//00001000
	set_sprite_prop(1,0x00);
	set_sprite_prop(2,0x00);
	set_sprite_prop(3,0x00);
	
	set_sprite_tile(0, 0);	//top left of bird
	set_sprite_tile(1, 1);	//bottom left of bird
	set_sprite_tile(2, 2);	//
	set_sprite_tile(3, 3);
	
	pipe_bot_h = MAX_PIPE_H;
	pipe_top_h = 1;
	init_pipes();
	move_pipe_spr(
		0, 
		pipe_bot_h,
		pipes_x,
		(GROUND_Y + TILE_SIZE) - (TILE_SIZE * pipe_bot_h)
	);
	move_pipe_spr(
		1, 
		pipe_top_h,
		pipes_x,
		SCREEN_TOP_L_VISIBLE_Y
	);
	
	move_bird(40,0);
	
	enable_interrupts();
	SHOW_BKG;
	SHOW_SPRITES;
	DISPLAY_ON;
	
	grav = 0x01;
	bird_vel = 0x00;
	bPressed_J_A = 0;
	bPressed_J_START = 0;
	bSound_in_progress = 0;
	
	game_state = GS_INTRO;
	//Main game loop
	while(1) {
		input = joypad();
		
		switch(game_state){
			case GS_GAMEPLAY:
				if(input & J_START && (bPressed_J_START == 0)) {
					game_state = GS_PAUSED;
					bPressed_J_START = 1;
					break;
				} else if((input & J_START) == 0) {
					bPressed_J_START = 0;
				}
				
				/*if(input & J_RIGHT) { scroll_win(1,0); }
				if(input & J_LEFT) { scroll_win(-1, 0); }
				if(input & J_UP) { scroll_win(0,-1); }
				if(input & J_DOWN) { scroll_win(0, 1); }*/
				
				if(check_collision()){
					sound_you_die();
					trans_gameplay_gameover();					
					break;
				}
			
				for(index = 0; index < 1; ++index) wait_vbl_done();				
				time++;
				if(time >= 0xFF) { time = 0x00; }

				animate_bird();

				if((input & J_A) && (bPressed_J_A == 0)) {
					bird_vel = -4;
					sound_flap();
					bPressed_J_A = 1;
				} else if((input & J_A) == 0) {
					bPressed_J_A = 0;
				}
				
				pipes_x -= PIPE_SPEED;
				// pipes offscreen, reset them with new heights
				if(pipes_x < -TILE_SIZE) {
					pipes_x = MAXWNDPOSX + TILE_SIZE;
					pipe_bot_h = rand() % MAX_PIPE_H;
					if(pipe_bot_h < 2) { pipe_bot_h = 2; }
					move_pipe_spr(
						0, 
						pipe_bot_h,
						pipes_x,
						(GROUND_Y + TILE_SIZE) - (TILE_SIZE * pipe_bot_h)
					);
					pipe_top_h = 8 - pipe_bot_h;
					move_pipe_spr(
						1, 
						pipe_top_h,
						pipes_x,
						SCREEN_TOP_L_VISIBLE_Y
					);
					bScore_counted = 0x00; //new chance to get a point
				}
				else {
					scroll_pipe_spr(0, -PIPE_SPEED, 0);
					scroll_pipe_spr(1, -PIPE_SPEED, 0);
				}
				ground_index = (ground_index + 1) % 8;
				set_bkg_tiles(0,0x10,20,2,ground_map_frames[ground_index]);					
				
				if((bird_pos.y) < GROUND_Y ) {
					if(time % 5 == 0) {bird_vel += grav;}	
					//hit the ceiling
					if( (bird_pos.y + bird_vel) < 10) {
						//sound_you_die();
						//trans_gameplay_gameover();
						bird_vel = 0; // I just found out the ceiling doesn't kill you in the original
					}
					bird_pos.y += bird_vel;
				}
				else { 
					waitpadup();
					sound_you_die();
					trans_gameplay_gameover();
				}
				
				move_bird(0,0);
				if(bSound_in_progress) {
					bSound_in_progress = sound_pipe(bSound_in_progress);
				}
				check_score();				
				
			break;
			case GS_PAUSED:
				if(input & J_START && (bPressed_J_START == 0)) {
					game_state = GS_GAMEPLAY;
					bPressed_J_START = 1;
					break;
				} else if((input & J_START) == 0) {
					bPressed_J_START = 0;
				}
                if(input & J_UP) {
                    OBP0_REG++;
                    waitpadup();
                }else if(input & J_DOWN) {
                    OBP0_REG--;
                    waitpadup();
                }else if(input & J_LEFT) {
                    OBP1_REG =  0xE4;
                    waitpadup();
                } else if(input & J_RIGHT) {
                    OBP1_REG =  0xE0;
                    waitpadup();
                }
			break;
			case GS_INTRO:
				
				if((input & J_A) && (bPressed_J_A == 0)) {
					game_state = GS_GAMEPLAY;
					bPressed_J_A = 1;
					wait_vbl_done();					
					set_bkg_tiles(3,0,14,6, full_bg_map2);
					draw_score(score, SCORE_X,0x01);
					bird_vel = -4;
				} else {
					bPressed_J_A = 0;
				}
				
				for(index = 0; index < 1; ++index) wait_vbl_done();
				time++;
				if(time >= 0xFF) { time = 0x00; }
				animate_bird();
				ground_index = (ground_index + 1) % 8;
				set_bkg_tiles(0,0x10,20,2,ground_map_frames[ground_index]);
			break;
			case GS_GAMEOVER:
				if((input & J_A) && (bPressed_J_A == 0)) {
					if(bird_pos.y >= GROUND_Y) {
						waitpadup();
						bPressed_J_A = 1;
						trans_gameplay_intro();
					}
				}
				else {
					bPressed_J_A = 0;
				}
				for(index = 0; index < 1; ++index) wait_vbl_done();				
				time++;
				if(time >= 0xFF) { time = 0x00; }
				
				if((bird_pos.y) < GROUND_Y ) {
					if(time % 5 == 0) {bird_vel += grav;}	
					bird_pos.y += bird_vel;
					animate_bird();
				} else {
					set_sprite_prop(0,S_FLIPY);
					set_sprite_prop(1,S_FLIPY);
					set_sprite_prop(2,S_FLIPY);
					set_sprite_prop(3,S_FLIPY);
					
					set_sprite_tile(0, 1);	//top left of bird
					set_sprite_tile(1, 0);	//bottom left of bird
					set_sprite_tile(2, 3);	//
					set_sprite_tile(3, 2);
					
				}
				move_bird(0,0);
				
			break;			
		}		
	}
	return 0;
}

void trans_gameplay_gameover(void)
{	
	UBYTE i,j;
	UBYTE pipe_index,cur_spr_index;
	game_state = GS_GAMEOVER;	
	bird_vel = 0;
	
	wait_vbl_done();

	HIDE_BKG;
	for(i = 0; i < 20; ++i) {
		for(j = 0; j < 16; ++j) {//leave 2 bottom tile rows alone to show ground
			set_bkg_tiles(i,j,1,1, numbers_map + 10);
		}
	}
	
	set_bkg_tiles(4, 1, 0x0C, 0x03, title_gameover_map);
	
	set_bkg_tiles(4, 4, 12, 1, full_bg_map2);
	set_bkg_tiles(4, 6, 12, 1, full_bg_map2);
	set_bkg_tiles(4, 4, 0x05, 0x01, title_score_map);
	set_bkg_tiles(4, 6, 0x04, 0x01, title_hiscore_map);
	
	for(i = PIPE_SPRITES_BEGIN; i < 36; ++i) {
		set_sprite_prop(i, S_PRIORITY | PROP_OBP1);
	}
	
	// create enough prites for each pipe:
	//	1st row of pipe is head 
	//		num_sprites = 1 * NUM_TILES_PIPE_ROW
	//	for 0 to max_pipe_height
	//		num_sprites += NUM_TILES_PIPE_ROW
	for(pipe_index = 0; pipe_index < NUM_PIPES; ++pipe_index) {
		cur_spr_index = PIPE_SPRITES_BEGIN + (pipe_index * NUM_SPR_PER_PIPE);
		//initialize the pipe's head sprite row, flip it for every other pipe
		// so we get ground/ceil/ground/ceil...
		for(i = 0; i < NUM_TILES_PIPE_ROW; ++i) {
			set_sprite_tile(cur_spr_index + i, pipe_g_head_map[i]);			
			if(pipe_index%2 != 0) {
				set_sprite_prop(cur_spr_index + i, S_PRIORITY | S_FLIPY | PROP_OBP1);//set head row upsidedown
			}
			
		}
		cur_spr_index += NUM_TILES_PIPE_ROW;
	}
	
	if(score > hiscore) { hiscore = score; }
	draw_score(score, 0x0F,0x04);
	draw_score(hiscore, 0x0F, 0x06);
	SHOW_BKG;
}

void trans_gameplay_intro(void)
{
	UBYTE x,y;
	UBYTE pipe_index,cur_spr_index,i;
	game_state = GS_INTRO;
	
	pipes_x = MAXWNDPOSX + TILE_SIZE;
	pipe_bot_h = rand() % MAX_PIPE_H;
	if(pipe_bot_h < 2) { pipe_bot_h = 2; }
	wait_vbl_done();
	move_pipe_spr(
		0, 
		pipe_bot_h,
		pipes_x,
		(GROUND_Y + TILE_SIZE) - (TILE_SIZE * pipe_bot_h)
	);
	pipe_top_h = 8 - pipe_bot_h;
	move_pipe_spr(
		1, 
		pipe_top_h,
		pipes_x,
		SCREEN_TOP_L_VISIBLE_Y
	);
	bird_pos.y = SCREEN_TOP_L_VISIBLE_Y + (7 * TILE_SIZE);
	bird_vel = 0x00;
	set_bkg_tiles(0,0,20,16, full_bg_map2);
	set_bkg_tiles(4, 1, 0x0C, 0x03, title_getready_map);
	set_bkg_tiles(6, 4, 0x08, 0x02, title_tap_map);
	for(x = 0; x < 0x0E; ++x) {
		set_bkg_tiles(3 + x, 0, 0x01, 0x01, numbers_map + 0x0A);
	}
	for(y = 0; y < 5; ++y) {
		set_bkg_tiles(3, 1+y, 0x01, 0x01, numbers_map + 0x0A);
		set_bkg_tiles(0x10, 1+y, 0x01, 0x01, numbers_map + 0x0A);
	}
	set_bkg_tiles(5, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(5, 5, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0E, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0E, 5, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(4, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(4, 5, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0F, 4, 1, 1, numbers_map + 0x0A);
	set_bkg_tiles(0x0F, 5, 1, 1, numbers_map + 0x0A);
	score = 0;
	bScore_counted = 0x00;
	
	set_sprite_prop(0,0x00);//00001000
	set_sprite_prop(1,0x00);
	set_sprite_prop(2,0x00);
	set_sprite_prop(3,0x00);
	
	set_sprite_tile(0, 0);	//top left of bird
	set_sprite_tile(1, 1);	//bottom left of bird
	set_sprite_tile(2, 2);	//
	set_sprite_tile(3, 3);
	
	for(i = PIPE_SPRITES_BEGIN; i < 36; ++i) {
		set_sprite_prop(i, PROP_OBP1);//OBP1_REG;
	}
	// create enough prites for each pipe:
	//	1st row of pipe is head 
	//		num_sprites = 1 * NUM_TILES_PIPE_ROW
	//	for 0 to max_pipe_height
	//		num_sprites += NUM_TILES_PIPE_ROW
	for(pipe_index = 0; pipe_index < NUM_PIPES; ++pipe_index) {
		cur_spr_index = PIPE_SPRITES_BEGIN + (pipe_index * NUM_SPR_PER_PIPE);
		//initialize the pipe's head sprite row, flip it for every other pipe
		// so we get ground/ceil/ground/ceil...
		for(i = 0; i < NUM_TILES_PIPE_ROW; ++i) {
			set_sprite_tile(cur_spr_index + i, pipe_g_head_map[i]);			
			if(pipe_index%2 != 0) {
				set_sprite_prop(cur_spr_index + i, S_FLIPY | PROP_OBP1);//set head row upsidedown
			}
			else {
				set_sprite_prop(cur_spr_index + i, PROP_OBP1);
			}
		}
		cur_spr_index += NUM_TILES_PIPE_ROW;
	}
	bSound_in_progress = 0x00;
	sound_stop_all();
}

void draw_score(INT16 val, UBYTE x, UBYTE y)
{
	INT16 score_disp;
	score_disp = val;
	
	if(score_disp == 0) {
		set_bkg_tiles(x,y,1,1, numbers_map);
	}
	else {
		while(score_disp > 1 && x > 0) {
			set_bkg_tiles(x,y,1,1, numbers_map + (score_disp % 10));
			score_disp /= 10;			
			x--;
		}
	}
}

void init_pipes(void)
{
	UBYTE i,pipe_index,cur_spr_index;
	// set pipe tiles
	set_sprite_data(12,PIPE_SPRITES_BEGIN,pipes);	
	
	// create enough prites for each pipe:
	//	1st row of pipe is head 
	//		num_sprites = 1 * NUM_TILES_PIPE_ROW
	//	for 0 to max_pipe_height
	//		num_sprites += NUM_TILES_PIPE_ROW
	for(pipe_index = 0; pipe_index < NUM_PIPES; ++pipe_index) {
		cur_spr_index = PIPE_SPRITES_BEGIN + (pipe_index * NUM_SPR_PER_PIPE);
		//initialize the pipe's head sprite row, flip it for every other pipe
		// so we get ground/ceil/ground/ceil...
		for(i = 0; i < NUM_TILES_PIPE_ROW; ++i) {
			set_sprite_tile(cur_spr_index + i, pipe_g_head_map[i]);
			if(pipe_index%2 != 0) {
				set_sprite_prop(cur_spr_index + i, 0x40 | PROP_OBP1);//set head row upsidedown
			}
            else {
                set_sprite_prop(cur_spr_index + i, PROP_OBP1);
            }
		}
		
		cur_spr_index += NUM_TILES_PIPE_ROW;
		//set tiles for the rest of the rows in the pipe
		for(i = 0; i < MAX_PIPE_H*2; i+=2) {			
			set_sprite_tile(cur_spr_index + i, 
						pipe_g_head_map[2]);
			set_sprite_tile(cur_spr_index + i + 1, 
						pipe_g_head_map[3]);
            set_sprite_prop(cur_spr_index + i, PROP_OBP1);
            set_sprite_prop(cur_spr_index + i + 1, PROP_OBP1);
		}
	}
}

void move_pipe_spr(UINT8 index, UINT8 height, UINT8 x, UINT8 y)
{
	// pipe tiles start at sprite 4, there are 12 tiles/sprites per pipe
	UBYTE pipe_spr_index = PIPE_SPRITES_BEGIN + 
		((NUM_TILES_PIPE_ROW + (NUM_TILES_PIPE_ROW * MAX_PIPE_H)) * index);
	UBYTE i,head_y;
	
	if(index % 2 == 0) {								//right sideup (ground)
		head_y = y;
		move_sprite(pipe_spr_index,	  x, 			head_y);
		move_sprite(pipe_spr_index+1, x+TILE_SIZE,	head_y);
		for(i = 0; i < height; ++i) {
			move_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)),
							x, head_y+((i+1)*TILE_SIZE));
			move_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)) + 1,
							x+TILE_SIZE, head_y+((i+1)*TILE_SIZE));
		}
	}
	else {												//upside down (ceiling)
		head_y = y+(TILE_SIZE*height);
		move_sprite(pipe_spr_index,	  x, 			head_y);
		move_sprite(pipe_spr_index+1, x+TILE_SIZE,	head_y);	
		for(i = 0; i < height; ++i) {
			move_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)),
							x, head_y-((i+1)*TILE_SIZE));
			move_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)) + 1,
							x+TILE_SIZE, head_y-((i+1)*TILE_SIZE));
		}
	}
	//place the remaining pipe sprites off screen
	for(; i < MAX_PIPE_H; ++i) {
		move_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)),
			MAXWNDPOSX + (4 * TILE_SIZE), MAXWNDPOSY + (4 * TILE_SIZE));
		move_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1))+1,
			MAXWNDPOSX + (4 * TILE_SIZE), MAXWNDPOSY + (4 * TILE_SIZE));
	}
}

void scroll_pipe_spr(UINT8 index, INT8 x, INT8 y)
{
	UBYTE pipe_spr_index = PIPE_SPRITES_BEGIN + 
		((NUM_TILES_PIPE_ROW + (NUM_TILES_PIPE_ROW * MAX_PIPE_H)) * index);
	UBYTE i;
	
	if(index % 2 == 0) {								//right sideup (ground)
		scroll_sprite(pipe_spr_index,	  x, 	y);
		scroll_sprite(pipe_spr_index+1,   x,	y);
		for(i = 0; i < MAX_PIPE_H; ++i) {
			scroll_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)),x,y);
			scroll_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)) + 1,x,y);
		}
	}
	else {												//upside down (ceiling)
		scroll_sprite(pipe_spr_index,	  x, 	y);
		scroll_sprite(pipe_spr_index+1,	  x,	y);	
		for(i = 0; i < MAX_PIPE_H; ++i) {
			scroll_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)),x,y);
			scroll_sprite(pipe_spr_index + (NUM_TILES_PIPE_ROW*(i+1)) + 1,x,y);
		}
	}
}

void move_bird(BYTE dx, BYTE dy)
{
	bird_pos.x += dx;
	bird_pos.y += dy;
	move_sprite(0, bird_pos.x, bird_pos.y); 
	move_sprite(1, bird_pos.x, bird_pos.y + TILE_SIZE);
	move_sprite(2, bird_pos.x + TILE_SIZE, bird_pos.y);
	move_sprite(3, bird_pos.x + TILE_SIZE, bird_pos.y + TILE_SIZE);
}
void animate_bird()
{
	if((time & 0x0F) == 0) {
		if(bird_cur_frame >= (BIRD_NUM_FRAMES * BIRD_TILES_PER_FRAME - BIRD_TILES_PER_FRAME)) {//if(bird_cur_frame == (4 * BIRD_NUM_FRAMES)) {
			bird_anim_state = BIRD_ANIM_DOWN;
		} else if(bird_cur_frame == 0) {
			bird_anim_state = BIRD_ANIM_UP;
		}
		
		if(bird_anim_state == BIRD_ANIM_UP) {
			bird_cur_frame += 4;								
		} 
		if(bird_anim_state == BIRD_ANIM_DOWN) {
			bird_cur_frame -= 4;			
		}
		set_sprite_tile(0, flappy_bird_tiles[bird_cur_frame]);
		set_sprite_tile(1, flappy_bird_tiles[bird_cur_frame+1]);
		set_sprite_tile(2, flappy_bird_tiles[bird_cur_frame+2]);
		set_sprite_tile(3, flappy_bird_tiles[bird_cur_frame+3]);
	}
}

void check_score()
{
	if(bScore_counted) {
		return;
	}
	if(bird_pos.x > (pipes_x + TILE_SIZE)) {
		bScore_counted = 0x01;
		++score;
		draw_score(score, SCORE_X,0x01);
		bSound_in_progress = 0x00;
		bSound_in_progress = sound_pipe(bSound_in_progress);
	}
}

UBYTE check_collision()
{
	BYTE bird_x_left = bird_pos.x;
	BYTE bird_x_right = bird_pos.x + (2*TILE_SIZE);
	BYTE pipes_x_left = pipes_x;
	BYTE pipes_x_right = pipes_x + (2*TILE_SIZE);
	BYTE pipes_y_bot = (GROUND_Y + TILE_SIZE) - (TILE_SIZE * pipe_bot_h);
	BYTE pipes_y_top = SCREEN_TOP_L_VISIBLE_Y+(TILE_SIZE*pipe_top_h);
	
	if(bird_x_right >= pipes_x_left && bird_x_left <= pipes_x_right) {
		if(((bird_pos.y+(TILE_SIZE)) >  pipes_y_bot) || (bird_pos.y < pipes_y_top)){
			return 0x01;
		}
	}
	
	return 0x00;
}
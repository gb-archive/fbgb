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
#include "fb_sound.h"

void sound_init(void)
{
	// Initialize sound chip
	NR52_REG = 0xF8U;
	NR51_REG = 0x00U;
	NR50_REG = 0x77U;//0xFFU;
}

void sound_flap(void)
{
	NR10_REG = 0x34U; // 4th bit indicates if freq increases or decreases
			  // bits 5th-7th indicate sweep delay
	NR11_REG = 0x80U;
	NR12_REG = 0xF0U;
	NR13_REG = 0x0AU; //lowest 8 frequency bits
	NR14_REG = 0xC6U; // first 3 bits are the 3 highest bits of freq
	NR51_REG |= 0x11;
}

void sound_you_die (void)
{
    NR41_REG = 0x00;//0x1FU;
    NR42_REG = 0xE1;//0xF7U;
    NR43_REG = 0x22;//0x24U;
    NR44_REG = 0xC3;//0x80U;
    NR51_REG = 0x88U;
}

UBYTE sound_pipe(UBYTE bIn_progress)
{
	//UBYTE i;
	if(NR52_REG & 0x02) { //is sound 2 playing?
		return 0x01;
	}
	else if(bIn_progress) {// sound 2 not playing, but already played first note
		NR21_REG = 0x80U;
		NR22_REG = 0x73U;
		NR23_REG = 0x9EU;
		NR24_REG = 0xC7U;
		NR51_REG |= 0x22;
		return 0x00;
	}
	else {	// play frst note
		NR21_REG = 0xAEU;
		NR22_REG = 0x68U;
		NR23_REG = 0xDBU;
		NR24_REG = 0xC6U;
		NR51_REG |= 0x22;
		return 0x01;
	}

}

/*
	didn't quite work as I expected?
*/
void sound_check_stop(void)
{
	UBYTE s1, s2, s3, s4;
	s1 = (NR52_REG & 0x01);
	s2 = (NR52_REG & 0x02);
	s3 = (NR52_REG & 0x04);
	s4 = (NR52_REG & 0x08);
	if(!s1 && !s2 && !s3 && !s4) {
		sound_stop_all();
		return;
	}
	
	if(!s1) { //sound 1 not playing?
		NR51_REG &= 0xEE;
		NR10_REG = 0x00U;
		NR11_REG = 0x00U;
		NR12_REG = 0x00U;
		NR13_REG = 0x00U;
		NR14_REG = 0x00U;
	}
	if(!s2) { //sound 2 not playing?
		NR51_REG &= 0xDD;
	}
	if(!s3) { //sound 3 not playing?
		NR51_REG &= 0xBB;
		NR30_REG = 0x00U;
		NR31_REG = 0x00U;
		NR32_REG = 0x00U;
		NR33_REG = 0x00U;
		NR34_REG = 0x00U;
	}
	if(!s4) { //sound 4 not playing?
		NR51_REG &= 0x77;
		NR41_REG = 0x00U;
		NR42_REG = 0x00U;
		NR43_REG = 0x00U;
		NR44_REG = 0x00U;
	}
}

void sound_stop_all(void)
{
	NR10_REG = 0x00U;
	NR11_REG = 0x00U;
	NR12_REG = 0x00U;
	NR13_REG = 0x00U;
	NR14_REG = 0x00U;
	NR21_REG = 0x00U;
	NR22_REG = 0x00U;
	NR23_REG = 0x00U;
	NR24_REG = 0x00U;
	NR41_REG = 0x00U;
    NR42_REG = 0x00U;
    NR43_REG = 0x00U;
    NR44_REG = 0x00U;

	NR51_REG = 0x00;
}
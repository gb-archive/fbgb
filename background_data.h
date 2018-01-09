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
const unsigned char ground_data[] =
{
//TOP GROUND LAYER
  0xFF,0xFF,0x00,0x00,0x01,0xFE,0x03,0xFC,0x07,0xF8,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,//0
  0xFF,0xFF,0x00,0x00,0xE0,0x1F,0xC0,0x3F,0x80,0x7F,0x01,0xFE,0x03,0xFC,0x07,0xF8,//1
  0xFF,0xFF,0x00,0x00,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE0,0x1F,0xC0,0x3F,0x80,0x7F,//2
  0xFF,0xFF,0x00,0x00,0x07,0xF8,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,//3
  0xFF,0xFF,0x00,0x00,0x80,0x7F,0x01,0xFE,0x03,0xFC,0x07,0xF8,0x0F,0xF0,0x1E,0xE1,//4
  0xFF,0xFF,0x00,0x00,0xF0,0x0F,0xE0,0x1F,0xC0,0x3F,0x80,0x7F,0x01,0xFE,0x03,0xFC,//5
  0xFF,0xFF,0x00,0x00,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE0,0x1F,0xC0,0x3F,//6
  0xFF,0xFF,0x00,0x00,0x03,0xFC,0x07,0xF8,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,//7
  0xFF,0xFF,0x00,0x00,0xC0,0x3F,0x80,0x7F,0x01,0xFE,0x03,0xFC,0x07,0xF8,0x0F,0xF0,//8
  0xFF,0xFF,0x00,0x00,0x78,0x87,0xF0,0x0F,0xE0,0x1F,0xC0,0x3F,0x80,0x7F,0x01,0xFE,//9
  0xFF,0xFF,0x00,0x00,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE0,0x1F,//10
//BOTTOM GROUND LAYER  
  0x78,0x87,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//11
  0x0F,0xF0,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//12
  0x01,0xFE,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//13
  0xE0,0x1F,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//14
  0x3C,0xC3,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//15
  0x07,0xF8,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//16
  0x80,0x7F,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//17
  0xF0,0x0F,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//18
  0x1E,0xE1,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//19
  0x03,0xFC,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,//20
  0xC0,0x3F,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF//21
  
  //numbred
/*  0xFF,0xFF,0x00,0x00,0x1F,0xFE,0x13,0xFE,0x17,0xFA,0x1F,0xF2,0x1E,0xFF,0x3C,0xC3,
  0xFF,0xFF,0x08,0x08,0xE8,0x1F,0xC8,0x3F,0x88,0x7F,0x09,0xFE,0x0B,0xFC,0x07,0xF8,
  0xFF,0xFF,0x00,0x00,0x3C,0xFF,0x7C,0xE7,0xFC,0x0F,0xF8,0x1F,0xF0,0x7F,0xFE,0x7F,
  0xFF,0xFF,0x3C,0x3C,0x07,0xFC,0x0F,0xF4,0x3E,0xFD,0x3C,0xC7,0x7C,0xFF,0xF0,0x0F,
  0xFF,0xFF,0x24,0x24,0xA4,0x7F,0x25,0xFE,0x3F,0xFC,0x07,0xFC,0x0F,0xF4,0x1E,0xE5,
  0xFF,0xFF,0x00,0x00,0xFC,0x3F,0xE0,0x3F,0xFC,0x3F,0x84,0x7F,0x05,0xFE,0x7F,0xFC,
  0xFF,0xFF,0x18,0x18,0x3E,0xF1,0x7C,0xE3,0x78,0xC7,0xFC,0x7F,0xE4,0x3F,0xFC,0x3F,
  0xFF,0xFF,0x00,0x00,0x3B,0xFC,0x0F,0xF8,0x0F,0xF8,0x1E,0xE9,0x3C,0xCB,0x78,0x87,
  0xFF,0xFF,0x00,0x00,0xF8,0x3F,0xA8,0x7F,0x7D,0xFE,0x47,0xFC,0x67,0xFC,0x3F,0xFC,
  0xFF,0xFF,0x3C,0x3C,0x7C,0xA7,0xFC,0x3F,0xEC,0x1F,0xDC,0x3F,0xB0,0x7F,0x61,0xFE,
  0xFF,0xFF,0x00,0x00,0x3F,0xFC,0x3E,0xE5,0x3C,0xFF,0x74,0xAF,0xF4,0x6F,0xE0,0x1F*/
};

const unsigned char ground_map_scroll[] = {
	117,118,119,120,121,122,123,124,125,126,127,
	117,118,119,120,121,122,123,124,125,126,127,
	117,118,119,120,121,122,123,124,125,
	
	128,129,130,131,132,133,134,135,136,137,138,
	128,129,130,131,132,133,134,135,136,137,138,
	128,129,130,131,132,133,134,135,136
};

const unsigned char* ground_map_frames[] = {
	ground3_frame_0,ground3_frame_1,ground3_frame_2,ground3_frame_3,
	ground3_frame_4,ground3_frame_5,ground3_frame_6,ground3_frame_7
};

const unsigned char ground3_data[] =
{
  0xFF,0xFF,0x00,0x00,0xE1,0x1E,0xC3,0x3C,0x87,0x78,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,
  0xFF,0xFF,0x00,0x00,0xC3,0x3C,0x87,0x78,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,
  0xFF,0xFF,0x00,0x00,0x87,0x78,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,
  0xFF,0xFF,0x00,0x00,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE1,0x1E,
  0xFF,0xFF,0x00,0x00,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,
  0xFF,0xFF,0x00,0x00,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,0x87,0x78,
  0xFF,0xFF,0x00,0x00,0x78,0x87,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,0x87,0x78,0x0F,0xF0,
  0xFF,0xFF,0x00,0x00,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,0x87,0x78,0x0F,0xF0,0x1E,0xE1
};

const unsigned char ground3full_data[] =
{
	0xFF,0xFF,0x00,0x00,0xE1,0x1E,0xC3,0x3C,0x87,0x78,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,
	0xFF,0xFF,0x00,0x00,0xC3,0x3C,0x87,0x78,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,
	0xFF,0xFF,0x00,0x00,0x87,0x78,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,
	0xFF,0xFF,0x00,0x00,0x0F,0xF0,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE1,0x1E,
	0xFF,0xFF,0x00,0x00,0x1E,0xE1,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,
	0xFF,0xFF,0x00,0x00,0x3C,0xC3,0x78,0x87,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,0x87,0x78,
	0xFF,0xFF,0x00,0x00,0x78,0x87,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,0x87,0x78,0x0F,0xF0,
	0xFF,0xFF,0x00,0x00,0xF0,0x0F,0xE1,0x1E,0xC3,0x3C,0x87,0x78,0x0F,0xF0,0x1E,0xE1,
	0x78,0x87,0xF0,0x0F,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0xF0,0x0F,0xE1,0x1E,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0xE1,0x1E,0xC3,0x3C,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0xC3,0x3C,0x87,0x78,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0x87,0x78,0x0F,0xF0,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0x0F,0xF0,0x1E,0xE1,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0x1E,0xE1,0x3C,0xC3,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
	0x3C,0xC3,0x78,0x87,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00
};

const unsigned char ground3_frame_0[] = {
	0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,0X75,
	0X75,0X75,0X75,0X75,
	0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,0x7D,
	0x7D,0x7D,0x7D,0x7D,
};
const unsigned char ground3_frame_1[] = {
	0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,0X76,
	0X76,0X76,0X76,0X76,
	0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,
	0x7E,0x7E,0x7E,0x7E,
};
const unsigned char ground3_frame_2[] = {
	0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,0X77,
	0X77,0X77,0X77,0X77,
	0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
	0x7F,0x7F,0x7F,0x7F,
};
const unsigned char ground3_frame_3[] = {
	0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,0X78,
	0X78,0X78,0X78,0X78,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
	0x80,0x80,0x80,0x80,
};
const unsigned char ground3_frame_4[] = {
	0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,0X79,
	0X79,0X79,0X79,0X79,
	0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,
	0x81,0x81,0x81,0x81,
};const unsigned char ground3_frame_5[] = {
	0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,0X7A,
	0X7A,0X7A,0X7A,0X7A,
	0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,
	0x82,0x82,0x82,0x82,
};
const unsigned char ground3_frame_6[] = {
	0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,0X7B,
	0X7B,0X7B,0X7B,0X7B,
	0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
	0x83,0x83,0x83,0x83,
};
const unsigned char ground3_frame_7[] = {
	0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,
	0X7C,0X7C,0X7C,0X7C,
	0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,
	0x84,0x84,0x84,0x84,
};
const unsigned char ground3_map[] = 
{
	0X75,0X76,0X77,0X78,0X79,0X7A,0X7B,
	0X75,0X76,0X77,0X78,0X79,0X7A,0X7B,0X7C,
	0X75,0X76,0X77,0X78
};

const unsigned char full_bg_map2[] =
{
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
  
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,
  
	 /*8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,
	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,*/
  
	 1, 2, 3, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 0, 0, 0,	 0, 4, 5, 6,
	 7, 8, 8, 9,	10, 0, 0, 0,	 0,11,12,13,	14,15,16,17,	18,19, 8, 8,
	 
	 //1, 2, 3, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 8, 8, 8,	 8, 4, 5, 6,
	 //7, 8, 8, 9,	10, 8, 8, 8,	 8,11,12,13,	14,15,16,17,	18,19, 8, 8,
	
	8, 8, 8, 8,	20,21,22,23,	24,25, 8, 8,	26,27,28, 8,	29,30, 8, 8,
	31, 8, 8, 8,	32,33,34,35,	36,37, 8, 8,	 8,38,39,40,	41,42, 8, 8,
	
	43,44, 8,45,	46,47,48,49,	50,51,52, 8,	53,54,55,56,	57,58,59, 8,
	60,61, 8,62,	63,64,65,66,	67,68,69, 8,	70,71,72,73,	74,75,76, 8,
	77,78,79,80,	81,82,83,84,	85,86,87,88,	89,90,91,92,	93,94,95,96,
	97,98,99,100,	101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116

};



const unsigned char full_bg_tiles2[] =
{
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFE,0x06,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x1F,0xE0,0xE0,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xC0,0x7F,0x70,0x0F,0x0F,0x01,0x01,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x03,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x1F,0xF0,0x70,0x80,0x80,0x80,0x80,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xE0,0x3F,0x3C,0x07,0x07,0x03,0x03,
	0xF8,0x18,0xE0,0x20,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x80,0x7F,0x70,0x0F,0x08,0x07,0x04,0x03,0x02,0x01,0x01,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x80,0x7F,0x40,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFE,0x06,0xF8,0x08,0xF0,0x10,0xE0,0x20,
	0xFF,0x07,0xF8,0x18,0xE0,0x60,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0xE0,0x1F,0x18,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x80,0x7F,0x40,0x3F,0x30,0x0F,0x0C,0x07,0x06,0x03,0x03,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFF,0x07,0xFC,0x0C,0xF8,0x38,0xE0,0x60,
	0xFF,0x00,0xFF,0x00,0xFF,0x7F,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0xE0,0x3F,0x31,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFE,0x0E,0xF8,0x18,0xE0,0x60,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7F,0x40,0x7F,0x40,0x3F,0x20,0x1F,0x10,0x0F,0x08,0x0F,0x08,0x07,0x07,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFE,0x1E,0xE0,0x20,0xC0,0xC0,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x7E,0x81,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xC0,0x3F,0x38,0x07,0x04,0x03,0x03,0x0F,0x00,
	0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFF,0x01,0xFE,0x1E,0xF0,0x10,0xE0,0xE0,0xFC,0x00,
	0xC0,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0xC0,0x7F,0x63,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x03,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x0C,0x00,0x0C,0x00,0x0C,0xC0,
	0x0F,0x00,0x0C,0x00,0x0C,0x00,0xFC,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,
	0xFC,0x00,0x0C,0x00,0x0C,0x00,0xCC,0x00,0xCC,0x00,0x0C,0x00,0x0C,0x00,0xCC,0x03,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x3C,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,
	0xFF,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,
	0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xCF,0x30,
	0xFC,0x00,0x00,0xFC,0x00,0xFC,0xFF,0x00,0xFF,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0xFC,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
	0x0F,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,
	0xFC,0x03,0x00,0x03,0x00,0x03,0xC0,0x03,0xC0,0x03,0xFC,0x03,0xFC,0x03,0x0C,0x03,
	0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xCC,0x03,0xCC,0x03,0xCC,0x03,0x0C,0x03,0x0C,0x03,0xCC,0x03,0xCC,0x03,0xCC,0x03,
	0xF0,0x00,0x00,0xF0,0x00,0xF0,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0xF0,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x3F,0x00,0x30,0x00,
	0xFF,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,
	0xC0,0x3C,0x00,0x3C,0x00,0x3C,0x00,0x3C,0x00,0x3C,0xC0,0x3C,0xC0,0x3C,0xC0,0x3C,
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xCF,0x30,0xC0,0x3F,0xC0,0x3F,0xCF,0x30,0xCF,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
	0xC0,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,
	0x0C,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x0C,0x00,0x0C,0x00,0xCC,0x00,
	0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
	0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,
	0x0C,0x03,0xCC,0x03,0xCC,0x03,0xCC,0x03,0xCC,0x03,0x3F,0x00,0x3F,0x00,0xF0,0x00,
	0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x00,0xFC,0x00,0xFC,0xF0,0x0C,0xF0,0x0C,0x30,0x0C,
	0xCC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xCC,0x03,0x0C,0x03,0x0C,0x03,0x0C,0x03,0x0C,0x03,0xCC,0x03,0xCC,0x03,0xCC,0x03,
	0x00,0x00,0x33,0x00,0x33,0x00,0x33,0x00,0x33,0x00,0x00,0x00,0x00,0x00,0x33,0x00,
	0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
	0x30,0x00,0x3C,0x00,0x3C,0x00,0x3C,0x00,0x3C,0x00,0x30,0x00,0x30,0x00,0x3C,0x00,
	0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x03,0x00,0x03,0x00,0xCF,0x00,
	0xC0,0x3C,0xC0,0x3C,0xC0,0x3C,0xC0,0x3F,0xC0,0x3F,0xFC,0x03,0xFC,0x03,0x00,0x03,
	0xCC,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xCC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xC0,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC0,0x30,0xC0,0x30,0xC3,0x30,
	0x03,0x00,0x33,0x00,0x33,0x00,0x33,0x00,0x33,0x00,0x03,0x00,0x03,0x00,0x33,0x00,
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0x0C,0x00,0x0C,0x00,0xCC,0x00,0xCC,0x00,0xC8,0x07,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x1F,0x20,0x3F,0xC0,
	0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0xC0,0x83,0x40,0xC1,0x3E,
	0xCC,0x00,0xCC,0x00,0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,
	0xF0,0x00,0xF3,0x00,0xF3,0x00,0x33,0x00,0x33,0x00,0xF0,0x00,0xF1,0x00,0xF0,0x0F,
	0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x00,0xFF,0xFF,0x00,0xFF,0x00,
	0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x00,0xF0,
	0xCC,0x03,0x0C,0x03,0x0C,0x03,0xCC,0x03,0xCC,0x03,0xC0,0x0F,0xDF,0x00,0x0F,0xF0,
	0x33,0x00,0x33,0x00,0x33,0x00,0x00,0x00,0x00,0x00,0x03,0xF0,0xFB,0x00,0xF0,0x0F,
	0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
	0x3C,0x00,0x3C,0x00,0x3C,0x00,0x30,0x00,0x30,0x00,0x00,0x3F,0x7F,0x00,0x3F,0xC0,
	0xCF,0x00,0xCF,0x00,0xCF,0x00,0x03,0x00,0x03,0x00,0x0F,0xC0,0xEF,0x00,0xC0,0x3F,
	0x00,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x00,0x3F,0x7F,0x00,0x3F,0xC0,
	0xCC,0x00,0xC0,0x00,0xC0,0x00,0xCC,0x00,0xCC,0x00,0x0C,0xC0,0xEC,0x00,0xC0,0x3C,
	0xCC,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0xCC,0x00,0x00,0x00,
	0xC3,0x30,0xC3,0x30,0xC3,0x30,0xC0,0x30,0xC0,0x30,0xC3,0x30,0xC3,0x30,0xC3,0x30,
	0x33,0x00,0x33,0x00,0x33,0x00,0x03,0x00,0x03,0x00,0x33,0x00,0x33,0x00,0x33,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x00,0x0F,0xF0,
	0xCC,0x00,0xC0,0x00,0xC0,0x00,0x00,0xFC,0xFC,0x02,0xFC,0x03,0xFF,0x00,0xFF,0x00,
	0xCB,0x04,0x03,0x3C,0x7F,0x00,0x3F,0xC0,0x3F,0xC0,0x3F,0xC0,0xC3,0x3C,0xC3,0x3C,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xC0,0x3F,0xC0,0x3F,
	0xFC,0x03,0xFC,0x03,0xFC,0x03,0xFC,0x03,0xFC,0x03,0xFC,0x03,0x33,0xCC,0x33,0xCC,
	0xCC,0x00,0x00,0xC3,0x03,0xC4,0x03,0xFC,0x3F,0xC0,0x3F,0xC0,0xFF,0x00,0xFF,0x00,
	0xF3,0x0C,0x03,0xFC,0xFC,0x03,0xFC,0x03,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
	0xFF,0x00,0xFF,0x00,0x3F,0xC0,0x3F,0xC0,0xC3,0x3C,0xC3,0x3C,0xFC,0x03,0xFC,0x03,
	0xF9,0x00,0xF0,0x0F,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFC,0x03,0xFC,0x03,
	0xFF,0x00,0xFF,0x00,0x3F,0xC0,0x3F,0xC0,0x30,0xCF,0x30,0xCF,0x03,0xFC,0x03,0xFC,
	0xFF,0x00,0xFF,0x00,0x00,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFC,0x03,0xFC,0x03,
	0xB0,0x00,0x0C,0xF0,0x8C,0x71,0xF0,0x0F,0x6F,0x90,0x0F,0xF0,0xFF,0x00,0xFF,0x00,
	0x00,0x03,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
	0xFF,0x00,0xFF,0x00,0x0F,0xF0,0x0F,0xF0,0xF0,0x0F,0xF0,0x0F,0xFF,0x00,0xFF,0x00,
	0xFC,0x03,0xFC,0x03,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x3F,0xC0,0x3F,0xC0,
	0x3F,0xC0,0x3F,0xC0,0xCF,0x30,0xCF,0x30,0xCF,0x30,0xCF,0x30,0xC0,0x3F,0xC0,0x3F,
	0xFE,0x00,0xFC,0x03,0xF0,0x0F,0xF0,0x0F,0x0F,0xF0,0x0F,0xF0,0x3F,0xC0,0x3F,0xC0,
	0x00,0x00,0x0C,0xC3,0x0B,0xC4,0x03,0xFC,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
	0xC3,0x30,0x00,0xF0,0xC0,0x30,0xC0,0x3F,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
	0x32,0x01,0x00,0x0F,0x1F,0x00,0x0F,0x30,0x0F,0xB0,0x0F,0xF0,0xF0,0x0F,0xF0,0x0F,
	0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF0,0x0F,0xF0,0x0F
};

const unsigned char numbers_data2[] =
{
  0x3C,0x3C,0x46,0x46,0x4A,0x4A,0x4A,0x4A,0x52,0x52,0x52,0x52,0x62,0x62,0x3C,0x3C,
  0x18,0x18,0x38,0x38,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x7E,0x7E,
  0x38,0x38,0x44,0x44,0x44,0x44,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x7C,0x7C,
  0x3C,0x3C,0x42,0x42,0x02,0x02,0x04,0x04,0x1C,0x1C,0x02,0x02,0x42,0x42,0x3C,0x3C,
  0x0C,0x0C,0x14,0x14,0x24,0x24,0x44,0x44,0x7E,0x7E,0x04,0x04,0x04,0x04,0x04,0x04,
  0x7E,0x7E,0x40,0x40,0x40,0x40,0x7C,0x7C,0x02,0x02,0x02,0x02,0x42,0x42,0x3C,0x3C,
  0x0C,0x0C,0x10,0x10,0x20,0x20,0x3C,0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x3C,
  0x3E,0x3E,0x02,0x02,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
  0x3C,0x3C,0x42,0x42,0x42,0x42,0x3C,0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x3C,
  0x3C,0x3C,0x42,0x42,0x42,0x42,0x3E,0x3E,0x02,0x02,0x02,0x02,0x42,0x42,0x3C,0x3C,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char numbers_data[] =
{
	0xFF,0x7E,0xC3,0x7E,0xCB,0x7E,0xCB,0x7E,0xCB,0x7E,0xCB,0x7E,0xC3,0x7E,0xFF,0x7E,
	0xFF,0x7C,0xC7,0x7C,0xC7,0x7C,0xE7,0x7C,0xE7,0x3C,0xE7,0x3C,0xE7,0x3C,0xFF,0x3C,
	0xFF,0x7E,0xC3,0x7E,0xFB,0x7E,0xC3,0x7E,0xCF,0x7E,0xC3,0x7E,0xC3,0x7E,0xFF,0x7E,
	0xFF,0x7E,0xC3,0x7E,0xF3,0x7E,0xC3,0x7E,0xC3,0x7E,0xF3,0x7E,0xC3,0x7E,0xFF,0x7E,
	0xFF,0x7E,0xCB,0x7E,0xCB,0x7E,0xC3,0x7E,0xF3,0x7E,0xF3,0x1E,0xF3,0x1E,0xFF,0x1E,
	0xFF,0x7E,0xC3,0x7E,0xC3,0x7E,0xDF,0x7E,0xC3,0x7E,0xFB,0x7E,0xC3,0x7E,0xFF,0x7E,
	0xFF,0x7E,0xC3,0x7E,0xDF,0x7E,0xC3,0x7E,0xDB,0x7E,0xC3,0x7E,0xC3,0x7E,0xFF,0x7E,
	0xFF,0x7E,0xC3,0x7E,0xC3,0x7E,0xF3,0x7E,0xF3,0x1E,0xF3,0x1E,0xF3,0x1E,0xFF,0x1E,
	0xFF,0x7E,0xC3,0x7E,0xDB,0x7E,0xC3,0x7E,0xC3,0x7E,0xDB,0x7E,0xC3,0x7E,0xFF,0x7E,
	0xFF,0x7E,0xC3,0x7E,0xC3,0x7E,0xDB,0x7E,0xC3,0x7E,0xFB,0x7E,0xC3,0x7E,0xFF,0x7E
};

const unsigned char numbers_map[] = {
	0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F
//	0x8B,0x8C,0x8D,0x8E,0x8F,0x90,0x91,0x92,0x93,0x94,0x95
};

const unsigned char title_getready_data[] =
{
	0xFF,0x00,0xFF,0x7F,0xC0,0x7F,0xC0,0x7F,0xC1,0x7E,0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,
	0xFF,0x00,0xFF,0xFF,0x08,0xFF,0x08,0xFF,0xF8,0x0F,0xF8,0xFF,0x08,0xFF,0x08,0xFF,
	0xFF,0x00,0xFF,0xFF,0x01,0xFF,0x01,0xFF,0xF1,0x0F,0xF1,0xFF,0x01,0xFF,0x01,0xFF,
	0xFE,0x00,0xFE,0xFC,0x06,0xFC,0x07,0xFC,0x07,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xE0,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,
	0x1F,0x00,0x1F,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,
	0xFF,0x00,0xFF,0xFF,0x01,0xFF,0x01,0xFF,0x21,0xDF,0x21,0xFF,0x21,0xFF,0x21,0xFF,
	0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x1E,0xE1,0x1E,0xFF,0x00,0xFF,0x00,0xFF,
	0xFF,0x00,0xFF,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,0x3E,0xE1,0xFE,0xFF,0x80,0xFF,
	0xFC,0x00,0xFC,0xF8,0x0C,0xF8,0x0F,0xF8,0x0F,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
	0xFF,0x00,0xFF,0x7E,0xC3,0x7E,0xC3,0x7E,0xCF,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0xFE,0x43,0xFE,0x43,0xFE,0x43,0xFE,
	0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,0xC0,0x7F,0xC0,0x7F,0xC0,0x7F,
	0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
	0x01,0xFF,0x01,0xFF,0x7F,0x81,0x7F,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,
	0x07,0xF8,0x07,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0xE0,0x40,0xE0,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,
	0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,0x18,0x0F,
	0x21,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x07,0xF9,0x07,0xFF,0x21,0xDF,0x21,0xFF,
	0x00,0xFF,0x00,0xFF,0x0F,0xF0,0x0F,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0x80,0xFF,0x80,0xFF,0x87,0xF8,0x87,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,
	0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
	0x48,0xBF,0x48,0xFF,0x48,0xFF,0x48,0xFF,0x48,0xFF,0x08,0xFF,0x0F,0xF8,0x0F,0xFF,
	0x43,0xFE,0x03,0xFE,0x03,0xFE,0x03,0xFE,0x03,0xFE,0x03,0xFE,0xC3,0x3E,0xC3,0xFE,
	0xFF,0x40,0xFF,0x7F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x08,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x01,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE0,0x40,0xE0,0xC0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1F,0x08,0x1F,0x0F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x21,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x80,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x08,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFC,0x07,0xFC,0xFF,0xFC,0x07,0x0F,0x04,0x0F,0x07,0x0F,0x00,0x00,0x00,0x00,0x00,
	0x03,0xFE,0x03,0xFE,0x03,0xFE,0xFF,0x02,0xFF,0xFE,0xFF,0x00,0x00,0x00,0x00,0x00
};

const unsigned char title_getready_map[] =
{
	0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,
	0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,
	0xAF,0xB0,0xB1,0xB2,0xB3
};

const unsigned char title_tap_data[] =
{
	0x0F,0x0F,0x0F,0x0F,0x30,0x3F,0x33,0x3C,0xC3,0xFF,0xCF,0xF3,0xCC,0xFF,0xCF,0xFC,
	0xF0,0xF0,0xF0,0xF0,0x0C,0xFC,0xCC,0x3C,0xC3,0xFF,0xF3,0xCF,0x33,0xFF,0xF3,0x3F,
	0xCF,0xFF,0xCF,0xFF,0xCC,0xFF,0xFC,0xCF,0x30,0x3F,0x3F,0x30,0x0F,0x0F,0x0F,0x0F,
	0xF3,0xFF,0xF3,0xFF,0x33,0xFF,0x3F,0xF3,0x0C,0xFC,0xFC,0x0C,0xF0,0xF0,0xF0,0xF0,
	0x03,0x03,0x04,0x04,0x04,0x04,0x08,0x08,0x08,0x08,0x10,0x10,0x10,0x10,0x20,0x20,
	0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
	0xFF,0xFF,0x00,0x00,0xC7,0xC7,0xC7,0xC7,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
	0xFF,0xFF,0x00,0x00,0x87,0x87,0x87,0x87,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,
	0xFF,0xFF,0x01,0x01,0xC1,0xC1,0xF1,0xF1,0x31,0x31,0x19,0x19,0x19,0x19,0x31,0x31,
	0x20,0x20,0x10,0x10,0x10,0x10,0x08,0x08,0x08,0x08,0x04,0x04,0x04,0x04,0x03,0x03,
	0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x00,0xFF,0xFF,
	0x1F,0x1F,0x1F,0x1F,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xFF,0xFF,
	0xE7,0xE7,0xE7,0xE7,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00,0xFF,0xFF,
	0xF1,0xF1,0xC1,0xC1,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0xFF
};

const unsigned char title_tap_map[] =
{
	0xB4,0xB5,0x8F,0xB8,0xB9,0xBA,0xBB,0xBC,0xB6,0xB7,0x8F,0xBD,0xBE,0xBF,0xC0,0xC1
};

const unsigned char title_score_data[] = 
{
	0xFF,0x3F,0xFF,0x40,0xFF,0x40,0xFF,0x3E,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x7E,
	0xFF,0x3C,0xFF,0x42,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x42,0xFF,0x42,0xFF,0x3C,
	0xFF,0x18,0xFF,0x24,0xFF,0x42,0xFF,0x42,0xFF,0x42,0xFF,0x42,0xFF,0x24,0xFF,0x18,
	0xFF,0x3C,0xFF,0x22,0xFF,0x22,0xFF,0x22,0xFF,0x3C,0xFF,0x28,0xFF,0x24,0xFF,0x22,
	0xFF,0x7E,0xFF,0x40,0xFF,0x40,0xFF,0x78,0xFF,0x40,0xFF,0x40,0xFF,0x40,0xFF,0x7E,
	////
	0xFF,0x78,0xFF,0x44,0xFF,0x44,0xFF,0x78,0xFF,0x44,0xFF,0x42,0xFF,0x42,0xFF,0x7C,
	0xFF,0x7F,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,
	////
};

const unsigned char title_score_map[] =
{
	0x0C2,0x0C3,0x0C4,0x0C5,0x0C6
};

const unsigned char title_hiscore_map[] =
{
	0xC7,0xC6,0xC2,0xC8
};

const unsigned char title_gameover_data[] =
{	
	0xFF,0x00,0xFF,0x7F,0xC0,0x7F,0xC0,0x7F,0xC0,0x7F,0xC1,0x7E,0xC1,0x7F,0xC1,0x7F,
	0xFF,0x00,0xFF,0xFF,0x04,0xFF,0x04,0xFF,0x04,0xFF,0xFF,0x04,0xFF,0xFF,0x08,0xFF,
	0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xE0,0x1F,0xE0,0xFF,0x00,0xFF,
	0xC0,0x00,0xFF,0x80,0xFF,0xFF,0x80,0xFF,0x80,0xFF,0x88,0xF7,0x88,0xFF,0x88,0xFF,
	0x07,0x00,0xFF,0x03,0xFE,0xFF,0x02,0xFF,0x02,0xFF,0x22,0xDF,0x22,0xFF,0x22,0xFF,	
	0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x3C,0xC3,0x3C,0xFF,0x00,0xFF,0x00,0xFF,
	0xC7,0x00,0xC7,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,
	0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x10,0xEF,0x10,0xFF,0x10,0xFF,
	0xC0,0x00,0xFF,0x80,0xFF,0xFF,0x84,0xFF,0x84,0xFF,0x84,0xFF,0x84,0xFF,0x84,0xFF,
	0x7F,0x00,0xFF,0x3F,0xE0,0xFF,0x20,0xFF,0x23,0xFC,0x23,0xFF,0x20,0xFF,0x20,0xFF,
	0xFC,0x00,0xFF,0xF8,0x0F,0xFF,0x08,0xFF,0xC8,0x3F,0xC8,0xFF,0x08,0xFF,0x08,0xFF,
	0x00,0x00,0xFF,0x00,0xFF,0xFE,0x03,0xFE,0x43,0xBE,0x43,0xFE,0x43,0xFE,0x43,0xFE,
	0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,0xC1,0x7F,0xC0,0x7F,0xC0,0x7F,0xC0,0x7F,
	0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
	0x00,0xFF,0x00,0xFF,0x70,0x8F,0x70,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0x88,0xFF,0x88,0xFF,0x88,0xFF,0x88,0xFF,0x88,0xFF,0x88,0xFF,0x88,0xFF,0x88,0xFF,
	0x22,0xFF,0x22,0xFF,0x22,0xFF,0x22,0xFF,0x22,0xFF,0x22,0xFF,0x22,0xFF,0x22,0xFF,
	0x00,0xFF,0x00,0xFF,0x1F,0xE0,0x1F,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,0xC6,0x83,
	0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0x84,0xFF,0x84,0xFF,0x84,0xFF,0x84,0xFF,0x84,0xFF,0x80,0xFF,0x80,0xFF,0xC0,0xBF,
	0x20,0xFF,0x20,0xFF,0x21,0xFE,0x21,0xFF,0x20,0xFF,0x20,0xFF,0x20,0xFF,0x60,0xBF,
	0x08,0xFF,0x08,0xFF,0xF8,0x0F,0xF8,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,0x08,0xFF,
	0x7F,0xC2,0x7F,0xFE,0x7F,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,
	0xFF,0x40,0xFF,0x7F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x08,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x88,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x22,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xC7,0x82,0xC7,0x83,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0xC0,0xFF,0xBF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x60,0xFF,0xBF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x08,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE0,0x40,0xE0,0xC0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char title_gameover_map[] =
{
	0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,
	0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,
	0xE7,0xE8,0xE9,0xEA,0xEB,0xEC
};

const unsigned char title_main_map[] =
{
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,
	0X0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1D,0x1E
};

const unsigned char title_main_subs_map[] =
{
	0x1B,0x1C,0x1B,0x1D,0x16,0x28,0x29,		// "ALAN H."
	0x1E,0x1F,0x20,0x21,0x20,0x1D,0x1B,0x1C,0x2A, // "ORIGINAL:"
	0x27,0x21,0x22,0x1B,0x1F,0x23,0x16,0x23,0x24,0x25,0x26,0x20,0x1E,0x23,// "C GEARS STUDIOS"
	0x2C,0x2B,0x1F,0x22,0x23,0x23,0x16,0x23,0x24,0x1B,0x1F,0x24,0x2D// "(PRESS START)"
};

const unsigned char title_main[] =
{
	0xFF,0x00,0xFF,0x7F,0xC0,0x7F,0xC0,0x7F,0xC7,0x78,0xC7,0x7F,0xC0,0x7F,0xC0,0x7F,
	0xFD,0x00,0xFD,0xF8,0x0D,0xF8,0x0D,0xF8,0xFD,0x08,0xFD,0xF8,0x0D,0xF8,0x0D,0xF8,
	0xFF,0x00,0xFF,0xFF,0x80,0xFF,0x80,0xFF,0x8E,0xF1,0x8E,0xFF,0x80,0xFF,0x80,0xFF,
	0xF0,0x00,0xF0,0xE0,0x30,0xE0,0x30,0xE0,0x31,0xE0,0x31,0xE0,0x31,0xE0,0x31,0xE0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0xFF,0x81,0xFF,0x81,0xFF,
	0x0F,0x00,0x0F,0x07,0x0C,0x07,0x0C,0x07,0x8C,0x07,0x8C,0x07,0x8C,0x07,0x8C,0x07,
	0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x1F,0xE0,0x1F,0xFF,0x10,0xFF,0x10,0xFF,
	0xDF,0x00,0xDF,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,
	0xFF,0x00,0xFF,0xFE,0x03,0xFE,0x03,0xFE,0xE3,0x1E,0xE3,0xFE,0x03,0xFE,0x03,0xFE,
	0xC0,0x7F,0xC3,0x7C,0xC3,0x7F,0xC3,0x7E,0xC3,0x7E,0xC3,0x7E,0xC3,0x7E,0xC3,0x7E,
	0x0D,0xF8,0xFD,0x08,0xFD,0xF8,0xFD,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
	0x80,0xFF,0x80,0xFF,0x80,0xFF,0x8E,0xF1,0x8E,0xFF,0x80,0xFF,0x80,0xFF,0x80,0xFF,
	0xF1,0x20,0xF1,0xE0,0x31,0xE0,0x31,0xE0,0x30,0xE0,0x30,0xE0,0x30,0xE0,0x30,0xE0,
	0x81,0xFF,0xFF,0x81,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x8C,0x07,0x8C,0x07,0x8C,0x07,0x8C,0x07,0x0C,0x07,0x0C,0x07,0x0C,0x07,0x0C,0x07,
	0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x10,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
	0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,0xD8,0x8F,
	0x0F,0xF2,0x0F,0xFE,0x03,0xFE,0xE3,0x1E,0xE3,0xFE,0x03,0xFE,0x03,0xFE,0x03,0xFE,
	0xFF,0x42,0xFF,0x7E,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x80,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xF0,0x20,0xF0,0xE0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0F,0x04,0x0F,0x07,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xDF,0x88,0xDF,0x8F,0xDF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x02,0xFF,0xFE,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3C,0x3C,0x66,0x66,0x66,0x66,0x7E,0x7E,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7C,0x7C,0x00,0x00,
	0x62,0x62,0x72,0x72,0x7A,0x7A,0x5E,0x5E,0x4E,0x4E,0x46,0x46,0x42,0x42,0x00,0x00,
	0x3C,0x3C,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x3C,0x00,0x00,
	0x7C,0x7C,0x66,0x66,0x66,0x66,0x7C,0x7C,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,
	0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,
	0x3C,0x3C,0x62,0x62,0x60,0x60,0x6E,0x6E,0x66,0x66,0x66,0x66,0x3E,0x3E,0x00,0x00,
	0x7E,0x7E,0x60,0x60,0x60,0x60,0x7C,0x7C,0x60,0x60,0x60,0x60,0x7E,0x7E,0x00,0x00,
	0x3C,0x3C,0x62,0x62,0x70,0x70,0x3C,0x3C,0x0E,0x0E,0x46,0x46,0x3C,0x3C,0x00,0x00,
	0x7E,0x7E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,
	0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x3C,0x00,0x00,
	0x7C,0x7C,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7C,0x7C,0x00,0x00,
	0x3C,0x3C,0x42,0x42,0x99,0x99,0xB5,0xB5,0xB1,0xB1,0x9D,0x9D,0x42,0x42,0x3C,0x3C,
	0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x7E,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x00,
	0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x00,
	0x7C,0x7C,0x66,0x66,0x66,0x66,0x7C,0x7C,0x60,0x60,0x60,0x60,0x60,0x60,0x00,0x00,
	0x04,0x04,0x08,0x08,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x08,0x08,0x04,0x04,
	0x20,0x20,0x10,0x10,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x10,0x10,0x20,0x20
};
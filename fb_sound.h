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
#ifndef _FB_SOUND_H
#define _FB_SOUND_H

void sound_flap(void);
void sound_init(void);
void sound_you_die (void);
UBYTE sound_pipe(UBYTE bIn_progress);
void sound_stop_all(void);
void sound_check_stop(void);

#endif
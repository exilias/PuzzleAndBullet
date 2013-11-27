#include "game.h"

#include <math.h>
#include "pad.h"


#define BS(a) ((a) << 2)

void gameInit(void)
{

}


void gameFunc(void)
{

}


void gameDraw(AGDrawBuffer *DBuf)
{
	agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
	agDrawSETDBMODE( DBuf, 0xff, 0, 0, 1 );
	agDrawSPRITE( DBuf, FALSE, BS(250), BS(250), BS(250) + BS(50), BS(250) + BS(25) );
}

#include "fade.h"

#include <amlib.h>
#include "export.h"


#define FADE_DURATION	45

#define FADE_TYPE_IN	0
#define FADE_TYPE_OUT	1


typedef struct fadeData {
	int counter;
	int isDraw;
	int alpha;
	int type;
}FadeData;

FadeData fadeData;


void fadeInit()
{
	fadeData.counter = 0;
	fadeData.isDraw = FALSE;
	fadeData.type = FADE_TYPE_IN;
	fadeData.alpha = 255;
}


void fadeFunc()
{
	if (fadeData.isDraw) {
		if (fadeData.counter >= FADE_DURATION) {
			fadeData.isDraw = FALSE;
		}

		if (fadeData.type == FADE_TYPE_IN) {
			fadeData.alpha = 255 - (int)(255 * ((float)fadeData.counter / FADE_DURATION));
		} else if (fadeData.type == FADE_TYPE_OUT) {
			fadeData.alpha = (int)(255 * ((float)fadeData.counter / FADE_DURATION));
		}

		fadeData.counter++;
	}
}

void fadeDraw(void* DBuf)
{
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	if (!fadeData.isDraw) {
		return;
	}


	agDrawSETFCOLOR( _DBuf, ARGB( fadeData.alpha, 0, 0, 0 ) );

		
	agDrawSETDBMODE( _DBuf, 0xff, 0, 0, 1 );
	agDrawSPRITE( _DBuf, FALSE, 0, 0, x4(AGE_FB_WIDTH), x4(AGE_FB_HEIGHT));
}	

int isFadeDraw()
{
	return fadeData.isDraw;
}


void fadeIn()
{
	fadeData.isDraw = TRUE;
	fadeData.type = FADE_TYPE_IN;
	fadeData.counter = 0;
	fadeData.alpha = 255;
}
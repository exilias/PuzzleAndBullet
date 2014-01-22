
#include "cutin.h"

#include <amlib.h>
#include "math.h"


#define CUTIN_WIDTH			1024
#define CUTIN_HEIGHT		300
#define CUTIN_ORIGIN_X		((1024 - CUTIN_WIDTH) / 2)
#define CUTIN_ORIGIN_Y		((768 - CUTIN_HEIGHT) / 2)

#define CUTIN_STATE_NONE	0
#define CUTIN_STATE_FADEIN	1
#define CUTIN_STATE_SHOW	2
#define CUTIN_STATE_FADEOUT	3

#define CUTIN_FADE_FRAME	6
#define CUTIN_SHOW_FRAME	45	



CutinData cutinData;


void cutinInit()
{
	cutinData.state = CUTIN_STATE_NONE;
}



void createCutin(int imageFile)
{
	cutinData.x = CUTIN_ORIGIN_X;
	cutinData.y = CUTIN_ORIGIN_Y;
	cutinData.width = CUTIN_WIDTH;
	cutinData.height = CUTIN_HEIGHT;
	cutinData.alpha = 255;
	cutinData.imageFile = imageFile;
	cutinData.state = CUTIN_STATE_FADEIN;
	cutinData.counter = 0;
}

void cutinFunc()
{
	switch (cutinData.state) {
		case CUTIN_STATE_NONE:
		default:
			break;

		case CUTIN_STATE_FADEIN:
			cutinData.height = (int)(CUTIN_HEIGHT * (float)(1 - pow(1-((float)cutinData.counter / CUTIN_FADE_FRAME), 3)));
			cutinData.y = (768 - cutinData.height) / 2;
			cutinData.counter++;
			if (cutinData.height >= CUTIN_HEIGHT) {
				cutinData.state = CUTIN_STATE_SHOW;
				cutinData.counter = 0;
			}
			break;

		case CUTIN_STATE_SHOW:
			cutinData.counter++;
			if (cutinData.counter >= CUTIN_SHOW_FRAME) {
				cutinData.state = CUTIN_STATE_FADEOUT;
				cutinData.counter = 0;
			}
			break;

		case CUTIN_STATE_FADEOUT:
			cutinData.height = CUTIN_HEIGHT - (int)(CUTIN_HEIGHT * (float)(1 - pow(1-((float)cutinData.counter / CUTIN_FADE_FRAME), 3)));
			cutinData.y = (768 - cutinData.height) / 2;
			cutinData.counter++;
			if (cutinData.height <= 0) {
				cutinData.state = CUTIN_STATE_NONE;
			}
			break;
	}
}


int isCutinShowing()
{
	if (cutinData.state == CUTIN_STATE_NONE) {
		return FALSE;
	} else {
		return TRUE;
	}
}
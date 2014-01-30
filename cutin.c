
#include "cutin.h"

#include <amlib.h>
#include "export.h"
#include "math.h"


#define CUTIN_WIDTH			1024
#define CUTIN_HEIGHT		300
#define CUTIN_ORIGIN_X		((1024 - CUTIN_WIDTH) / 2)
#define CUTIN_ORIGIN_Y		((768 - CUTIN_HEIGHT) / 2)

#define CUTIN_STATE_NONE	0
#define CUTIN_STATE_FADEIN	1
#define CUTIN_STATE_SHOW	2
#define CUTIN_STATE_FADEOUT	3

#define CUTIN_FADE_FRAME			6
#define CUTIN_SHOW_FRAME_DEFAULT	60	



CutinData cutinData;


void cutinInit()
{
	cutinData.state = CUTIN_STATE_NONE;
	cutinData.duration = CUTIN_SHOW_FRAME_DEFAULT;
}



void createCutin(int imageFile)
{
	createCutinWithDuration(CUTIN_SHOW_FRAME_DEFAULT, imageFile);
}

void createCutinWithDuration(int duration, int imageFile)
{
	createCutinWithDurationAndSize(duration, CUTIN_WIDTH, CUTIN_HEIGHT, imageFile);
}

void createCutinWithDurationAndSize(int duration, int width, int height, int imageFile)
{
	cutinData.x = (AGE_FB_WIDTH - width) / 2;
	cutinData.y = (AGE_FB_HEIGHT - height) / 2;
	cutinData.width = width;
	cutinData.height = height;
	cutinData.orgWidth = width;
	cutinData.orgHeight = height;
	cutinData.alpha = 255;
	cutinData.imageFile = imageFile;
	cutinData.state = CUTIN_STATE_FADEIN;
	cutinData.counter = 0;
	cutinData.duration = duration;
}

void cutinFunc()
{
	switch (cutinData.state) {
		case CUTIN_STATE_NONE:
		default:
			break;

		case CUTIN_STATE_FADEIN:
			cutinData.height = (int)(cutinData.orgHeight * (float)(1 - pow(1-((float)cutinData.counter / CUTIN_FADE_FRAME), 3)));
			cutinData.y = (768 - cutinData.height) / 2;
			cutinData.counter++;
			if (cutinData.height >= cutinData.orgHeight) {
				cutinData.state = CUTIN_STATE_SHOW;
				cutinData.counter = 0;
			}
			break;

		case CUTIN_STATE_SHOW:
			cutinData.counter++;
			if (cutinData.counter >= cutinData.duration) {
				cutinData.state = CUTIN_STATE_FADEOUT;
				cutinData.counter = 0;
			}
			break;

		case CUTIN_STATE_FADEOUT:
			cutinData.height = cutinData.orgHeight - (int)(cutinData.orgHeight * (float)(1 - pow(1-((float)cutinData.counter / CUTIN_FADE_FRAME), 3)));
			cutinData.y = (768 - cutinData.height) / 2;
			cutinData.counter++;
			if (cutinData.height <= 0) {
				cutinData.state = CUTIN_STATE_NONE;
			}
			break;
	}
}

void cutinDraw(void* DBuf)
{
	int i, j, k;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	if (isCutinShowing()) {
		agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( _DBuf, cutinData.imageFile, 0, NULL, NULL );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(cutinData.x), x4(cutinData.y), x4(cutinData.x + cutinData.width), x4(cutinData.y + cutinData.height));
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
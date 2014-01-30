
#include "result.h"

#include <amlib.h>
#include <agesndmgr.h>
#include "export.h"
#include "math.h"

#define RESULT_SHOW_INTERVAL			120
#define RESULT_MARGIN_Y_VALUE			50

#define RESULT_WORD_ORIGIN_Y			80
#define RESULT_CHARACTER_ORIGIN_Y		300	

#define RESULT_STATE_INIT				0
#define RESULT_STATE_START				1
#define RESULT_STATE_SHOW_LOSE_PLAYER	2
#define RESULT_STATE_SHOW_WIN_PLAYER	3
#define RESULT_STATE_COMPLETE			4


typedef struct resultData {
	int state;
	int winPlayerId;
	int counter;
	int marginCounter;
	int marginY;
}ResultData;



ResultData resultData;

const int RESULT_WIN_PLAYER_SOUND_ID[] = {AS_SND_MAKO_WIN, AS_SND_LEMI_WIN};
const int RESULT_LOSE_PLAYER_SOUND_ID[] = {AS_SND_MAKO_LOSE, AS_SND_LEMI_LOSE};


void resultInit()
{
	resultData.state = RESULT_STATE_INIT;
	resultData.counter = 0;
}


void resultFunc()
{
	if (resultData.state == RESULT_STATE_INIT) {
		return;
	}

	switch (resultData.state) {
		case RESULT_STATE_START:
			resultData.state = RESULT_STATE_SHOW_LOSE_PLAYER;
			resultData.marginY = 0;
			resultData.counter = 0;
			resultData.marginCounter = 0;
			ageSndMgrPlayOneshot( RESULT_LOSE_PLAYER_SOUND_ID[resultData.winPlayerId == 0 ? 1 : 0], 0 , 0xf0 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
			break;

		case RESULT_STATE_SHOW_LOSE_PLAYER:
			if (resultData.counter >= RESULT_SHOW_INTERVAL) {
				resultData.state = RESULT_STATE_SHOW_WIN_PLAYER;
				resultData.counter = 0;
				ageSndMgrPlayOneshot( RESULT_WIN_PLAYER_SOUND_ID[resultData.winPlayerId], 0 , 0xf0 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
			}
			break;

		case RESULT_STATE_SHOW_WIN_PLAYER:
			if (resultData.counter >= RESULT_SHOW_INTERVAL) {
				resultData.state = RESULT_STATE_COMPLETE;
				resultData.counter = 0;
			}
			break;
	}


	resultData.marginY = sinf(PI * 2 / 240 * resultData.marginCounter) * RESULT_MARGIN_Y_VALUE;
	resultData.marginCounter++;
	resultData.counter++;
}


void resultDraw(void *DBuf)
{
	int w, h;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	if (resultData.state == RESULT_STATE_INIT) {
		return;
	}


	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );


	if (resultData.state >= RESULT_STATE_SHOW_LOSE_PLAYER) {
		int characterImageId, marginX;

		if (resultData.winPlayerId == 0) {
			characterImageId = AG_CG_LEMI_LOSE;
			marginX = AGE_FB_WIDTH/2;
		} else {
			characterImageId = AG_CG_MAKO_LOSE;
			marginX = 0;
		}

		ageTransferAAC( _DBuf, AG_CG_RESULT_WORD_LOSE, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4((AGE_FB_WIDTH/2 - w) / 2 + marginX), x4(RESULT_WORD_ORIGIN_Y + resultData.marginY), x4((AGE_FB_WIDTH/2 - w) / 2 + marginX + w), x4(RESULT_WORD_ORIGIN_Y + resultData.marginY + h));

		ageTransferAAC( _DBuf, characterImageId, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4((AGE_FB_WIDTH/2 - w) / 2 + marginX), x4(RESULT_CHARACTER_ORIGIN_Y + resultData.marginY), x4((AGE_FB_WIDTH/2 - w) / 2 + marginX + w ), x4(RESULT_CHARACTER_ORIGIN_Y + resultData.marginY + h));
	}

	if (resultData.state >= RESULT_STATE_SHOW_WIN_PLAYER) {
		int characterImageId, marginX;

		if (resultData.winPlayerId == 0) {
			characterImageId = AG_CG_MAKO_WIN;
			marginX = 0;
		} else {
			characterImageId = AG_CG_LEMI_WIN;
			marginX = AGE_FB_WIDTH/2;
		}

		ageTransferAAC( _DBuf, AG_CG_RESULT_WORD_WIN, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4((AGE_FB_WIDTH/2 - w) / 2 + marginX), x4(RESULT_WORD_ORIGIN_Y + resultData.marginY), x4((AGE_FB_WIDTH/2 - w) / 2 + marginX + w), x4(RESULT_WORD_ORIGIN_Y + resultData.marginY + h));

		ageTransferAAC( _DBuf, characterImageId, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4((AGE_FB_WIDTH/2 - w) / 2 + marginX), x4(RESULT_CHARACTER_ORIGIN_Y + resultData.marginY), x4((AGE_FB_WIDTH/2 - w) / 2 + marginX + w ), x4(RESULT_CHARACTER_ORIGIN_Y + resultData.marginY + h));
	}
	



}



void showResult(int winPlayerId)
{
	resultData.state = RESULT_STATE_START;
	resultData.counter = 0;
	resultData.winPlayerId = winPlayerId;
}


int isResultCompleted()
{


}
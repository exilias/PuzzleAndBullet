
#include "title.h"

#include <amlib.h>
#include <agGamePad.h>
#include <agesndmgr.h>
#include "math.h"
#include "export.h"
#include "bgm_manager.h"
#include "game_bg.h"
#include "fade.h"


#define TITLE_LOGO_ORIGIN_Y		100
#define TITLE_PUSH_START_ORIGIN_Y	550
#define TITLE_MARGIN_Y_VALUE	20

#define TITLE_STATE_FADE_IN		0
#define TITLE_STATE_WAIT		1
#define TITLE_STATE_FADE_OUT	2


typedef struct titleData {
	int state;
	int isEnd;
	int marginY;
	int marginCounter;
}TitleData;


TitleData titleData;


void titleInit(void)
{
	titleData.state = TITLE_STATE_FADE_IN;
	titleData.isEnd = FALSE;
	titleData.marginCounter = 0;

	gameBgInit();
	fadeInit();
	fadeIn();

	playBgm(AS_SND_GAME_BGM);
}


void titleFunc(void)
{
	switch(titleData.state) {
		case TITLE_STATE_FADE_IN:
			gameBgFunc();
			fadeFunc();
			if (!isFadeDraw()) {
				titleData.state = TITLE_STATE_WAIT;
				ageSndMgrPlayOneshot( AS_SND_SYSTEM_PUSH_START, 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
			}
			break;

		case TITLE_STATE_WAIT:
		{
			int i;
			int isPushedDoneButton = FALSE;
			u32 pad;

			for (i = 0; i < 2; i++) {
				pad = agGamePadGetData(i);

				if ((pad & GAMEPAD_START) || (pad & GAMEPAD_A)) {
					titleData.state = TITLE_STATE_FADE_OUT;
					ageSndMgrPlayOneshot( AS_SND_SE_PUSHED_START_BUTTON, 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
					fadeOut();
				}
			}
			gameBgFunc();
		}
		break;
		
		case TITLE_STATE_FADE_OUT:
			gameBgFunc();
			fadeFunc();
			if (!isFadeDraw()) {
				titleData.isEnd = TRUE;
			}
			break;	
	}

	titleData.marginY = sinf(PI * 2 / 240 * titleData.marginCounter) * TITLE_MARGIN_Y_VALUE;
	titleData.marginCounter++;
}


void titleDraw(void* DBuf)
{
	int w, h;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	gameBgDraw(DBuf);


	ageTransferAAC( _DBuf, AG_CG_TITLE_LOGO, 0, &w, &h );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4((AGE_FB_WIDTH - w) / 2), x4(TITLE_LOGO_ORIGIN_Y), x4((AGE_FB_WIDTH - w) / 2  + w ), x4(TITLE_LOGO_ORIGIN_Y + h));

	ageTransferAAC( _DBuf, AG_CG_PUSH_START_BUTTON, 0, &w, &h );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4((AGE_FB_WIDTH - w) / 2), x4(TITLE_PUSH_START_ORIGIN_Y + titleData.marginY), x4((AGE_FB_WIDTH - w) / 2  + w ), x4(TITLE_PUSH_START_ORIGIN_Y + titleData.marginY + h));

	fadeDraw(DBuf);
}

int isTitleEnd()
{
	return titleData.isEnd;
}
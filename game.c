#include "game.h"

#include <math.h>
#include <ax51401.h>
#include <agGamePad.h>

#include "export.h"
#include "field.h"
#include "player.h"
#include "cutin.h"
#include "draw_number.h"
#include "score.h"
#include "gauge.h"
#include "effect.h"
#include "bgm_manager.h"
#include "game_bg.h"
#include "fade.h"
#include "count_down.h"
#include "result.h"


#define GAME_STATE_FADE_IN		0
#define GAME_STATE_COUNT_DOWN	1
#define GAME_STATE_GAMING		2
#define GAME_STATE_PLAYER_DEATH	3
#define GAME_STATE_FADE_OUT		4


typedef struct gameData {
	int state;
	int counter;
	int isEnd;
}GameData;

GameData gameData;

extern PlayerData playerData[2];




// 乱数の初期化
void setSrand()
{
	srand(aglGetReg(AG_REG_SYSMNTR));
}

void pushedStartButton(void)
{
	int i;
	u32 pad;


	for (i = 0; i < 2; i++) {
		pad = agGamePadGetData(i);

		if (pad & GAMEPAD_START) {
			gameInit();
		}
	}
	
}


void gameInit(void)
{
	setSrand();

	gameData.state = GAME_STATE_FADE_IN;
	gameData.isEnd = FALSE;

	gameBgInit();
	fieldInit();
	playerInit();
	weaponInit();
	cutinInit();
	scoreInit();
	gaugeInit();
	effectInit();
	resultInit();

	fadeInit();
	fadeIn();

	countDownInit();

	playBgm(AS_SND_GAME_BGM);
}


void gameFunc(void)
{
	switch (gameData.state) {
		case GAME_STATE_FADE_IN:
			gameBgFunc();
			fadeFunc();
			if (!isFadeDraw()) {
				gameData.state = GAME_STATE_COUNT_DOWN;
				fireCountDown();
			}
			break;

		case GAME_STATE_COUNT_DOWN:
			gameBgFunc();
			countDownFunc();
			if (isCountDownCompleted()) {
				gameData.state = GAME_STATE_GAMING;
			}
			break;

		case GAME_STATE_GAMING:
		{
			int i;

			for (i = 0; i < 2; i++) {
				if (playerData[i].isDead) {
					if (getDropFieldCompleted()) {
						gameData.state = GAME_STATE_PLAYER_DEATH;
						gameData.counter = 0;
						showResult(i == 0 ? 1 : 0);
					}
				}
			}

			if (!isCutinShowing()) gameBgFunc();
			if (!isCutinShowing()) fieldFunc();
			if (!isCutinShowing()) playerFunc();
			if (!isCutinShowing()) weaponFunc();
			cutinFunc();
			scoreFunc();
			gaugeFunc();
			effectFunc();
		}
			break;

		case GAME_STATE_PLAYER_DEATH:
			gameBgFunc();
			scoreFunc();
			gaugeFunc();
			effectFunc();
			resultFunc();
			if (isResultCompleted()) {
				gameData.state = GAME_STATE_FADE_OUT;
				fadeOut();
			}
			break;

		case GAME_STATE_FADE_OUT:
			gameBgFunc();
			resultFunc();
			fadeFunc();
			if (!isFadeDraw()) {
				gameData.isEnd = TRUE;
			}
			break;

	}

	pushedStartButton();
}


void gameDraw(AGDrawBuffer *DBuf)
{
	switch (gameData.state) {
		case GAME_STATE_FADE_IN:
			gameBgDraw(DBuf);
			fieldDraw(DBuf);
			gaugeDraw(DBuf);
			scoreDraw(DBuf);
			fadeDraw(DBuf);
			break;

		case GAME_STATE_COUNT_DOWN:
			gameBgDraw(DBuf);
			fieldDraw(DBuf);
			gaugeDraw(DBuf);
			scoreDraw(DBuf);
			countDownDraw(DBuf);
			fadeDraw(DBuf);

		case GAME_STATE_GAMING:
			gameBgDraw(DBuf);
			fieldDraw(DBuf);
			playerDraw(DBuf);
			weaponDraw(DBuf);
			effectDraw(DBuf);
			gaugeDraw(DBuf);
			scoreDraw(DBuf);
			cutinDraw(DBuf);	
			break;

		case GAME_STATE_PLAYER_DEATH:
			gameBgDraw(DBuf);
			fieldDraw(DBuf);
			effectDraw(DBuf);
			gaugeDraw(DBuf);
			scoreDraw(DBuf);
			cutinDraw(DBuf);
			resultDraw(DBuf);	
			fadeDraw(DBuf);
			break;

		case GAME_STATE_FADE_OUT:
			gameBgDraw(DBuf);
			fieldDraw(DBuf);
			gaugeDraw(DBuf);
			scoreDraw(DBuf);
			resultDraw(DBuf);	
			fadeDraw(DBuf);
			break;
	}
}
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



#define GAME_STATE_FADE_IN		0
#define GAME_STATE_COUNT_DOWN	1
#define GAME_STATE_GAMING		2



int gameState;
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

	gameState = GAME_STATE_FADE_IN;

	gameBgInit();
	fieldInit();
	playerInit();
	weaponInit();
	cutinInit();
	scoreInit();
	gaugeInit();
	effectInit();

	fadeInit();
	fadeIn();

	playBgm(AS_SND_GAME_BGM);
}


void gameFunc(void)
{
	switch (gameState) {
		case GAME_STATE_FADE_IN:
			gameBgFunc();
			fadeFunc();
			if (!isFadeDraw()) {
				gameState = GAME_STATE_COUNT_DOWN;
			}
			break;

		case GAME_STATE_COUNT_DOWN:
			gameBgFunc();
			break;

		case GAME_STATE_GAMING:
			if (!isCutinShowing()) fieldFunc();
			if (!isCutinShowing()) playerFunc();
			if (!isCutinShowing()) weaponFunc();
			cutinFunc();
			scoreFunc();
			gaugeFunc();
			effectFunc();
			break;

	}

	pushedStartButton();
}


void gameDraw(AGDrawBuffer *DBuf)
{
	// 背景
	gameBgDraw(DBuf);
	
	// フィールドの描画
	fieldDraw(DBuf);

	// プレイヤー描画
	playerDraw(DBuf);

	// 武器の描画
	weaponDraw(DBuf);

	// エフェクト
	effectDraw(DBuf);

	// GUI
	gaugeDraw(DBuf);
	scoreDraw(DBuf);

	// カットイン
	cutinDraw(DBuf);	

	// フェードイン
	fadeDraw(DBuf);
}
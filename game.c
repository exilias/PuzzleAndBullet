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



#define BS(a) ((a) << 2)

extern PlayerData playerData[2];

int deadCount;




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

	fieldInit();
	playerInit();
	weaponInit();
	cutinInit();
	scoreInit();
	gaugeInit();
	effectInit();

	deadCount = 0;
}


void gameFunc(void)
{
	fieldFunc();
	playerFunc();
	weaponFunc();
	cutinFunc();
	scoreFunc();
	gaugeFunc();
	effectFunc();

	pushedStartButton();
}


void gameDraw(AGDrawBuffer *DBuf)
{
	int i, j, k;

	// 背景
	ageTransferAAC( DBuf, AG_CG_GAME_BG, 0, NULL, NULL );
	agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(DBuf, TRUE, 0, 0, BS(FB_WIDTH), BS(FB_HEIGHT));

	if (playerData[0].isDead) {
		if (deadCount > 60) {
			//return;
		} else {
			deadCount++;
		}
	}
	
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
	
}
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

	deadCount = 0;
}


void gameFunc(void)
{
	fieldFunc();
	playerFunc();
	weaponFunc();
	cutinFunc();
	scoreFunc();

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

	// 武器の描画
	weaponDraw(DBuf);

	// プレイヤー描画
	playerDraw(DBuf);

	// GUI
	gaugeDraw(DBuf);

	for (i = 0; i < 2; i++) {
		// Score
		drawNumberGraph(playerData[0].weaponGauge /*表示させたい数字(int)*/, BS(i == 0 ? 100 : 600) /*表示させたいX座標*/, BS(20) /*表示させたいY座標*/, BS(40)/*1つの文字の幅*/, BS(50)/*1つの文字の高さ*/, 6/*桁数*/, DBuf);
	}

	// カットイン
	cutinDraw(DBuf);
	
}
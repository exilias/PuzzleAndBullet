
#include "gauge.h"

#include <amlib.h>
#include "export.h"
#include "field.h"
#include "player.h"


#define GAUGE_WIDTH 			40
#define GAUGE_HEIGHT 			490
#define GAUGE_BG_WIDTH			80
#define GAUGE_BG_HEIGHT			530
#define GAUGE_BG_MARGIN_X		20
#define GAUGE_BG_MARGIN_Y		16			
#define GAUGE_BG_ORIGIN1_X		432
#define GAUGE_BG_ORIGIN2_X		GAUGE_BG_ORIGIN1_X + GAUGE_BG_WIDTH + 5
#define GAUGE_BG_ORIGIN_Y		(FIELD_ORIGIN_Y - 10)



void gaugeInit()
{

}


void gaugeFunc()
{

}


void gaugeDraw(void* DBuf)
{
	int i;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;
	int weaponCount, weaponGauge;
	int height;


	// ゲージの背景
	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
	ageTransferAAC( _DBuf, AG_CG_GAUGE_BG, 0, NULL, NULL );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4(GAUGE_BG_ORIGIN1_X), x4(GAUGE_BG_ORIGIN_Y), x4(GAUGE_BG_ORIGIN1_X + GAUGE_BG_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_HEIGHT));

	agDrawSPRITE(_DBuf, TRUE, x4(GAUGE_BG_ORIGIN2_X), x4(GAUGE_BG_ORIGIN_Y), x4(GAUGE_BG_ORIGIN2_X + GAUGE_BG_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_HEIGHT));

	// ゲージ
	agDrawSETFCOLOR( _DBuf, ARGB( 255, 254, 204, 22 ) );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 0, 1 );

	for (i = 0; i < 2; i++) {
		int originX;
		if (i == 0) {
			originX = GAUGE_BG_ORIGIN1_X;
		} else {
			originX = GAUGE_BG_ORIGIN2_X;
		}

		weaponCount = (getPlayerWeaponGauge(i) / PLAYER_WEAPON_GAUGE_MAX);
		if (weaponCount == PLAYER_WEAPON_GRADE_MAX) {
			weaponCount = PLAYER_WEAPON_GRADE_MAX - 1;
		}
		weaponGauge = getPlayerWeaponGauge(i) - weaponCount * PLAYER_WEAPON_GAUGE_MAX;
		height = (int)(GAUGE_HEIGHT * ((float)weaponGauge / 100));
		//_dprintf("count:%d, gauge:%d, height:%d \n", weaponCount, weaponGauge, height);
		agDrawSPRITE( _DBuf, FALSE, x4(originX + GAUGE_BG_MARGIN_X), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_MARGIN_Y + GAUGE_HEIGHT - height), x4(originX + GAUGE_BG_MARGIN_X + GAUGE_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_MARGIN_Y + GAUGE_HEIGHT));
	}
}
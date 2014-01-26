
#include "gauge.h"

#include <amlib.h>
#include "export.h"
#include "math.h"
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

#define GAUGE_GRADE_NUMBER_WIDTH	45
#define GAUGE_GRADE_NUMBER_HEIGHT	50
#define GAUGE_GRADE_NUMBER_MARGIN_X	17
#define GAUGE_GRADE_NUMBER_MARGIN_Y	10




int currentGauge[2];

int weaponGradeNumberId[] = {	AG_CG_WEAPON_GRADE_NUMBER_0, 
								AG_CG_WEAPON_GRADE_NUMBER_1, 
								AG_CG_WEAPON_GRADE_NUMBER_2,
								AG_CG_WEAPON_GRADE_NUMBER_3,
								AG_CG_WEAPON_GRADE_NUMBER_4,
								AG_CG_WEAPON_GRADE_NUMBER_5
							};


void gaugeInit()
{
	int i;

	for (i = 0; i < 2; i++) {
		currentGauge[i] = 0;
	}
}


void gaugeFunc()
{
	int i;

	for (i = 0; i < 2; i++) {
		float subScore = getPlayerWeaponGauge(i) - currentGauge[i];
		if (subScore != 0) {
			if (abs(subScore) > 10) {
				currentGauge[i] += (int)(subScore / 10.0f);
			} else {
				if (subScore > 0) {
					currentGauge[i]++;
				} else {
					currentGauge[i]--;
				}
			}
		}
	}
}


void gaugeDraw(void* DBuf)
{
	int i;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;
	int weaponGrade, weaponGauge;
	int height;


	// ゲージの背景
	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
	ageTransferAAC( _DBuf, AG_CG_GAUGE_BG, 0, NULL, NULL );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4(GAUGE_BG_ORIGIN1_X), x4(GAUGE_BG_ORIGIN_Y), x4(GAUGE_BG_ORIGIN1_X + GAUGE_BG_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_HEIGHT));

	agDrawSPRITE(_DBuf, TRUE, x4(GAUGE_BG_ORIGIN2_X), x4(GAUGE_BG_ORIGIN_Y), x4(GAUGE_BG_ORIGIN2_X + GAUGE_BG_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_HEIGHT));

	// ゲージ
	for (i = 0; i < 2; i++) {
		int originX;
		if (i == 0) {
			originX = GAUGE_BG_ORIGIN1_X;
		} else {
			originX = GAUGE_BG_ORIGIN2_X;
		}

		weaponGrade = (currentGauge[i] / PLAYER_WEAPON_GAUGE_MAX);
		if (weaponGrade == PLAYER_WEAPON_GRADE_MAX) {
			weaponGrade = PLAYER_WEAPON_GRADE_MAX - 1;
		}
		weaponGauge = currentGauge[i] - weaponGrade * PLAYER_WEAPON_GAUGE_MAX;
		height = (int)(GAUGE_HEIGHT * ((float)weaponGauge / PLAYER_WEAPON_GAUGE_MAX));

		// ゲージ
		agDrawSETFCOLOR( _DBuf, ARGB( 255, 254, 204, 22 ) );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 0, 1 );
		agDrawSPRITE( _DBuf, FALSE, x4(originX + GAUGE_BG_MARGIN_X), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_MARGIN_Y + GAUGE_HEIGHT - height), x4(originX + GAUGE_BG_MARGIN_X + GAUGE_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_MARGIN_Y + GAUGE_HEIGHT));

		// グレード表示
		agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( _DBuf, weaponGradeNumberId[weaponGrade], 0, NULL, NULL );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(originX + GAUGE_GRADE_NUMBER_MARGIN_X), x4(GAUGE_BG_ORIGIN_Y + GAUGE_HEIGHT - GAUGE_GRADE_NUMBER_HEIGHT + GAUGE_GRADE_NUMBER_MARGIN_Y), x4(originX + GAUGE_GRADE_NUMBER_MARGIN_X + GAUGE_GRADE_NUMBER_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_HEIGHT - GAUGE_GRADE_NUMBER_HEIGHT + GAUGE_GRADE_NUMBER_MARGIN_Y + GAUGE_GRADE_NUMBER_HEIGHT));
	}

}

#include "game_bg.h"

#include <amlib.h>
#include "export.h"
#include "math.h"


#define GAME_BG_CLOUD_OBJECT_MAX	3

typedef struct gameBgCloudObject
{
	int x, y;
	int dx, dy;
	int interval;
	int counter;
	int fileId;
	float scale;
}GameBgCloudObject;


GameBgCloudObject gameBgCloudObject[GAME_BG_CLOUD_OBJECT_MAX];


void gameBgInit()
{
	// 雲（小）
	gameBgCloudObject[0].x = 400;
	gameBgCloudObject[0].y = 200;
	gameBgCloudObject[0].dx = 1;
	gameBgCloudObject[0].dy = 0;
	gameBgCloudObject[0].interval = 15;
	gameBgCloudObject[0].counter = 0;
	gameBgCloudObject[0].scale = 1.0f;
	gameBgCloudObject[0].fileId = AG_CG_GAME_BG_CLOUD_SMALL;

	// 雲（小）
	gameBgCloudObject[1].x = 600;
	gameBgCloudObject[1].y = 150;
	gameBgCloudObject[1].dx = 1;
	gameBgCloudObject[1].dy = 0;
	gameBgCloudObject[1].interval = 10;
	gameBgCloudObject[1].counter = 0;
	gameBgCloudObject[1].scale = 1.3f;
	gameBgCloudObject[1].fileId = AG_CG_GAME_BG_CLOUD_SMALL;

	// 雲（大）
	gameBgCloudObject[2].x = 100;
	gameBgCloudObject[2].y = 20;
	gameBgCloudObject[2].dx = 1;
	gameBgCloudObject[2].dy = 0;
	gameBgCloudObject[2].interval = 3;
	gameBgCloudObject[2].counter = 0;
	gameBgCloudObject[2].scale = 1.0f;
	gameBgCloudObject[2].fileId = AG_CG_GAME_BG_CLOUD_BIG;
}


void gameBgFunc()
{
	int i;

	for (i = 0; i < GAME_BG_CLOUD_OBJECT_MAX; i++) {
		if (gameBgCloudObject[i].counter >= gameBgCloudObject[i].interval) {
			gameBgCloudObject[i].x += gameBgCloudObject[i].dx;
			gameBgCloudObject[i].y += gameBgCloudObject[i].dy;
			gameBgCloudObject[i].counter = 0;
		}
		gameBgCloudObject[i].counter++;
	}
}


void gameBgDraw(void* DBuf)
{
	int i;
	int w, h;

	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;


	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );

	ageTransferAAC( _DBuf, AG_CG_GAME_BG_SKY, 0, &w, &h );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, 0, 0, x4(w), x4(h));

	for (i = 0; i < GAME_BG_CLOUD_OBJECT_MAX; i++) {
		ageTransferAAC( _DBuf, gameBgCloudObject[i].fileId, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(gameBgCloudObject[i].x), x4(gameBgCloudObject[i].y), x4(gameBgCloudObject[i].x + (int)(w * gameBgCloudObject[i].scale)), x4(gameBgCloudObject[i].y + (int)(h * gameBgCloudObject[i].scale)));

		if (gameBgCloudObject[i].x >= 1024) {
				gameBgCloudObject[i].x = -w;
			}
	}
}




#include "game_bg.h"

#include <amlib.h>
#include "export.h"
#include "math.h"


#define GAME_BG_CLOUD_OBJECT_MAX	3


#define GAME_BG_BEACH_WIDTH				1024
#define GAME_BG_BEACH_HEIGHT			120
#define GAME_BG_BEACH_MARGIN_Y			50

#define GAME_BG_BEACH_MOVE_DISTANCE		10
#define GAME_BG_BEACH_REMAIN_TIME		15
#define GAME_BG_BEACH_STATE_UP			0
#define GAME_BG_BEACH_STATE_REMAIN_UP	1
#define GAME_BG_BEACH_STATE_DOWN		2
#define GAME_BG_BEACH_STATE_REMAIN_DOWN	3


typedef struct gameBgCloudObject
{
	int x, y;
	int dx, dy;
	int interval;
	int counter;
	int fileId;
	float scale;
}GameBgCloudObject;

typedef struct gameBgBeachObject
{
	int x, y;
	int interval;
	int timer;
	int counter;
	int state;
	int fileId;
}GameBgBeachObject;


GameBgCloudObject gameBgCloudObject[GAME_BG_CLOUD_OBJECT_MAX];
GameBgBeachObject gameBgBeachObject;


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

	// 砂浜
	gameBgBeachObject.x = 0;
	gameBgBeachObject.y = AGE_FB_HEIGHT - GAME_BG_BEACH_HEIGHT + GAME_BG_BEACH_MOVE_DISTANCE;
	gameBgBeachObject.interval = 15;
	gameBgBeachObject.counter = 0;
	gameBgBeachObject.state = GAME_BG_BEACH_STATE_UP;
	gameBgBeachObject.fileId = AG_CG_GAME_BG_SAND;
}


void gameBgFunc()
{
	int i;

	// 雲
	for (i = 0; i < GAME_BG_CLOUD_OBJECT_MAX; i++) {
		if (gameBgCloudObject[i].counter >= gameBgCloudObject[i].interval) {
			gameBgCloudObject[i].x += gameBgCloudObject[i].dx;
			gameBgCloudObject[i].y += gameBgCloudObject[i].dy;
			gameBgCloudObject[i].counter = 0;
		}
		gameBgCloudObject[i].counter++;
	}

	// 砂浜
	switch (gameBgBeachObject.state) {
		case GAME_BG_BEACH_STATE_UP:
			if (gameBgBeachObject.counter >= gameBgBeachObject.interval){
				gameBgBeachObject.y--;
				gameBgBeachObject.counter = 0;
				if (gameBgBeachObject.y <= AGE_FB_HEIGHT - GAME_BG_BEACH_HEIGHT) {
					gameBgBeachObject.state = GAME_BG_BEACH_STATE_REMAIN_UP;
					gameBgBeachObject.counter = 0;
					gameBgBeachObject.timer = 0;
				}
			}
			break;

		case GAME_BG_BEACH_STATE_REMAIN_UP:
			if (gameBgBeachObject.counter >= gameBgBeachObject.interval){
				gameBgBeachObject.timer++;
				gameBgBeachObject.counter = 0;
				if (gameBgBeachObject.timer >= GAME_BG_BEACH_REMAIN_TIME) {
					gameBgBeachObject.state = GAME_BG_BEACH_STATE_DOWN;
					gameBgBeachObject.counter = 0;
				}
			}
			break;

		case GAME_BG_BEACH_STATE_DOWN:
			if (gameBgBeachObject.counter >= gameBgBeachObject.interval){
				gameBgBeachObject.y++;
				gameBgBeachObject.counter = 0;
				if (gameBgBeachObject.y >= AGE_FB_HEIGHT - GAME_BG_BEACH_HEIGHT + GAME_BG_BEACH_MOVE_DISTANCE) {
					gameBgBeachObject.state = GAME_BG_BEACH_STATE_REMAIN_DOWN;
					gameBgBeachObject.counter = 0;
					gameBgBeachObject.timer = 0;
				}
			}
			break;

		case GAME_BG_BEACH_STATE_REMAIN_DOWN:
			if (gameBgBeachObject.counter >= gameBgBeachObject.interval){
				gameBgBeachObject.timer++;
				gameBgBeachObject.counter = 0;
				if (gameBgBeachObject.timer >= GAME_BG_BEACH_REMAIN_TIME) {
					gameBgBeachObject.state = GAME_BG_BEACH_STATE_UP;
					gameBgBeachObject.counter = 0;
				}
			}
			break;
	}
	gameBgBeachObject.counter++;
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

	ageTransferAAC( _DBuf, gameBgBeachObject.fileId, 0, &w, &h );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4(gameBgBeachObject.x), x4(gameBgBeachObject.y + GAME_BG_BEACH_MARGIN_Y), x4(gameBgBeachObject.x + w), x4(gameBgBeachObject.y + GAME_BG_BEACH_MARGIN_Y + h));

	for (i = 0; i < GAME_BG_CLOUD_OBJECT_MAX; i++) {
		ageTransferAAC( _DBuf, gameBgCloudObject[i].fileId, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(gameBgCloudObject[i].x), x4(gameBgCloudObject[i].y), x4(gameBgCloudObject[i].x + (int)(w * gameBgCloudObject[i].scale)), x4(gameBgCloudObject[i].y + (int)(h * gameBgCloudObject[i].scale)));

		if (gameBgCloudObject[i].x >= AGE_FB_WIDTH) {
				gameBgCloudObject[i].x = -w;
			}
	}
}




#include "effect.h"

#include <amlib.h>
#include "export.h"
#include "math.h"
#include "field.h"


#define EFFECT_MAX		100


typedef struct effectData {
	int centerX, centerY;
	int fileId;
	int fireFlag;
	int currentFrame;
}EffectData;



EffectData effectData[EFFECT_MAX];


void effectInit()
{
	int i;

	for (i = 0; i < EFFECT_MAX; i++) {
		effectData[i].fireFlag = FALSE;
	}
}



void effectFunc()
{
	int i;

	for (i = 0; i < EFFECT_MAX; i++) {
		if (effectData[i].fireFlag) {
			if (ageRM3[effectData[i].fileId].Frames < effectData[i].currentFrame) {
				effectData[i].fireFlag = FALSE;
			}
		}
	}
}

void effectDraw(void* DBuf)
{
	int i;
	int x, y, w, h;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	for (i = 0; i < EFFECT_MAX; i++) {
		if (effectData[i].fireFlag) {
			ageTransferAAC_RM3( _DBuf , effectData[i].fileId , 0 , &w , &h , (effectData[i].currentFrame++) >> 1 );
				agDrawSETDBMODE( _DBuf, 0xff, 8, 2, 1 );

				x = effectData[i].centerX - (w / 2);
				y = effectData[i].centerY - (h / 2);
				agDrawSPRITE( _DBuf, TRUE, x4(x), x4(y), x4(x + w), x4(y + h) );
		}
	}
}


void addEffect(int centerX, int centerY, int fileId)
{
	int i;

	for (i = 0; i < EFFECT_MAX; i++) {
		if (!effectData[i].fireFlag) {
			effectData[i].centerX = centerX;
			effectData[i].centerY = centerY;
			effectData[i].fileId = fileId;
			effectData[i].fireFlag = TRUE;
			effectData[i].currentFrame = 0;
			break;
		}
	}
}



void addEffectInField(int fieldX, int fieldY, int fileId, int playerId)
{
	int x, y;
	int fieldOriginX;

	if (playerId == 0) {
		fieldOriginX = FIELD_ORIGIN1_X;
	} else {
		fieldOriginX = FIELD_ORIGIN2_X;
	}

	x = fieldOriginX + fieldX * FIELD_BLOCK_SIZE;
	y = FIELD_ORIGIN_Y + fieldY * FIELD_BLOCK_SIZE;
	
	addEffect(x + FIELD_BLOCK_SIZE / 2, y + FIELD_BLOCK_SIZE / 2, fileId);
}
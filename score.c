
#include "score.h"

#include <amlib.h>
#include "export.h"
#include "math.h"
#include "draw_number.h"
#include "field.h"


#define SCORE_BG_WIDTH			410
#define SCORE_BG_HEIGHT			90
#define SCORE_BG_ORIGIN1_X		FIELD_ORIGIN1_X
#define	SCORE_BG_ORIGIN2_X		FIELD_ORIGIN2_X
#define SCORE_BG_ORIGIN_Y		(FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * (FIELD_SIZE_HEIGHT + 1) + 30)

#define SCORE_MARGIN_X			50
#define SCORE_MARGIN_Y			8


typedef struct scoreData {
	int score;
	int trueScore;
}ScoreData;

ScoreData scoreData[2];


void scoreInit()
{
	int i;

	for (i = 0; i < 2; i++) {
		scoreData[i].score = 0;
		scoreData[i].trueScore = 0;
	}
}


void scoreFunc()
{
	int i;

	for (i = 0; i < 2; i++) {
		float subScore = scoreData[i].trueScore - scoreData[i].score;
		if (abs(subScore) > 50) {
			scoreData[i].score += (int)(subScore / 20.0f);
		} else {
			scoreData[i].score = scoreData[i].trueScore;
		}
	}
}

void scoreDraw(void* DBuf)
{
	int i;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	// 背景
	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
	ageTransferAAC( _DBuf, AG_CG_SCORE_BG, 0, NULL, NULL );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4(SCORE_BG_ORIGIN1_X), x4(SCORE_BG_ORIGIN_Y), x4(SCORE_BG_ORIGIN1_X + SCORE_BG_WIDTH), x4(SCORE_BG_ORIGIN_Y + SCORE_BG_HEIGHT));

	agDrawSPRITE(_DBuf, TRUE, x4(SCORE_BG_ORIGIN2_X), x4(SCORE_BG_ORIGIN_Y), x4(SCORE_BG_ORIGIN2_X + SCORE_BG_WIDTH), x4(SCORE_BG_ORIGIN_Y + SCORE_BG_HEIGHT));

	// Score
	for (i = 0; i < 2; i++) {
		drawNumberGraph(getScore(i) /*表示させたい数字(int)*/, x4(i == 0 ? (SCORE_BG_ORIGIN1_X + SCORE_MARGIN_X) : (SCORE_BG_ORIGIN2_X + SCORE_MARGIN_X)) /*表示させたいX座標*/, x4(SCORE_BG_ORIGIN_Y + SCORE_MARGIN_Y) /*表示させたいY座標*/, x4(50)/*1つの文字の幅*/, x4(60)/*1つの文字の高さ*/, 6/*桁数*/, _DBuf);
	}
}


int getScore(int playerId)
{
	return scoreData[playerId].score;
}

void addScore(int scoreValue, int playerId)
{
	scoreData[playerId].trueScore += scoreValue;
	if (scoreData[playerId].trueScore < 0) {
		scoreData[playerId].trueScore = 0;
	}
}

#include "score.h"

#include "math.h"


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


#define SCORE_ADD_STANDARD_VALUE	300
#define SCORE_ADD_BONUS_VALUE		50

void scoreInit();
void scoreFunc();
void scoreDraw(void* DBuf);
int getScore(int playerId);
void addScore(int scoreValue, int playerId);
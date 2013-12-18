
#define PLAYER_MODE_WAIT		(0)
#define PLAYER_MODE_RUNSTART	(1)
#define PLAYER_MODE_RUN			(2)
#define PLAYER_MODE_RUNEND		(3)
#define PLAYER_MODE_JUMPSTART	(4)
#define PLAYER_MODE_JUMP		(5)
#define PLAYER_MODE_JUMPEND		(6)
#define PLAYER_MODE_FALL		(7)
#define PLAYER_MODE_ATTACK		(8)

#define PLAYER_RUN_SPEED		(4)

#define PLAYER_WIDTH	40
#define PLAYER_HEIGHT	40


typedef struct playerData {
	int x, y;
	int direction;
	int count;
	int mode;
	int jumpCount;
}PlayerData;

void playerInit();
void playerFunc();
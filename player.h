


#define PLAYER_MODE_WAIT		(0)
#define PLAYER_MODE_RUNSTART	(1)
#define PLAYER_MODE_RUN			(2)
#define PLAYER_MODE_RUNEND		(3)
#define PLAYER_MODE_JUMPSTART	(4)
#define PLAYER_MODE_JUMP		(5)
#define PLAYER_MODE_JUMPEND		(6)
#define PLAYER_MODE_FALL		(7)

#define PLAYER_RUN_SPEED		(4)
#define PLAYER_FALL_SPEED		(8)
#define PLAYER_WEAPON_INTERVAL	(10)
#define PLAYER_WEAPON_GRADE_MAX (3)
#define PLAYER_WEAPON_GAUGE_MAX	(1000)
#define PLAYER_WEAPON_GAUGE_ADD_STANDARD_VALUE	(100)
#define PLAYER_WEAPON_GAUGE_ADD_BONUS_VALUE		(50)


#define PLAYER_WIDTH	40
#define PLAYER_HEIGHT	40


typedef struct playerData {
	int x, y;
	int direction;
	int count;
	int mode;
	int jumpCount;
	int isDead;
	int weaponCount;
	int weaponGauge;
	int characterId;
}PlayerData;

void playerInit();
void playerFunc();
void playerDraw(void* DBuf);
void addWeaponGauge(int value, int playerId);
int getPlayerWeaponGauge(int playerId);
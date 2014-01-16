#define WEAPON_BLOCK_SIZE	12
#define WEAPON_MAX_COUNT	5


typedef struct weaponData
{
	int x, y;
	int direction;
	int type;
	int isActive;
	int attackPoint;
}WeaponData;

void weaponInit();
void weaponFunc();
void addWeapon(void *playerData);
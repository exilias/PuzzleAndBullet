

#define FIELD_SIZE_WIDTH	8
#define FIELD_SIZE_HEIGHT	9

#define FIELD_BLOCK_SIZE	50
#define FIELD_ORIGIN1_X		27
#define FIELD_ORIGIN2_X		(1024 - 450 + 27)
#define FIELD_ORIGIN_Y		200

#define FIELD_DAMAGING_EFFECT_FRAME		5

#define FIELD_KIND_NONE		0
#define FIELD_KIND_RED		1
#define FIELD_KIND_GREEN	2
#define FIELD_KIND_BLUE		3
#define FIELD_KIND_NEEDLE	4
#define FIELD_KIND_NUM		5

typedef struct fieldData
{
	int kind;
	int hp;
	int counter;
	int state;
	int damagingEffectCount;
}FieldData;

void fieldInit();
void fieldFunc();
void fieldDraw(void* DBuf);
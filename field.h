

#define FIELD_SIZE_WIDTH	8
#define FIELD_SIZE_HEIGHT	9

#define FIELD_BLOCK_SIZE	50
#define FIELD_ORIGIN_X		100
#define FIELD_ORIGIN_Y		100


#define FIELD_KIND_NONE		0
#define FIELD_KIND_RED		1
#define FIELD_KIND_GREEN	2
#define FIELD_KIND_BLUE		3

typedef struct fieldData
{
	int kind;
	int hp;
}FieldData;

void fieldInit();
void fieldFunc();
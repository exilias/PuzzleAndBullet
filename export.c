#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_BLUE_1 */
	{        140,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_BLOCK_BLUE_2 */
	{        340,          0,   50,   50,   32,  8,       1888, NULL },		/* AG_CG_BLOCK_BLUE_3 */
	{        576,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_GREEN_1 */
	{        716,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_BLOCK_GREEN_2 */
	{        916,          0,   50,   50,   32,  8,       1856, NULL },		/* AG_CG_BLOCK_GREEN_3 */
	{       1148,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_RED_1 */
	{       1288,          0,   50,   50,   32,  8,       1664, NULL },		/* AG_CG_BLOCK_RED_2 */
	{       1496,          0,   50,   50,   32,  8,       1920, NULL },		/* AG_CG_BLOCK_RED_3 */
	{       1736,          0,   50,   50,   32,  8,       2240, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{       2016,          0,  450,  550,  232,  8,      19680, NULL },		/* AG_CG_GAME_BG_STAGE_BACK */
	{       4476,          0,  350,  150,  176,  8,       5376, NULL },		/* AG_CG_GAME_BG_CLOUD_BIG */
	{       5148,          0,  200,   80,  104,  8,       2656, NULL },		/* AG_CG_GAME_BG_CLOUD_SMALL */
	{       5480,          0,  300,  350,  152,  8,      10720, NULL },		/* AG_CG_GAME_BG_SUN */
	{       6820,          0,  300,  350,  152,  8,      13344, NULL },		/* AG_CG_GAME_BG_SUN_SHINE */
	{       8488,          0, 1024,  120,  512,  8,       6624, NULL },		/* AG_CG_GAME_BG_SAND */
	{       9316,          0, 1024,  768,  512,  8,      19520, NULL },		/* AG_CG_GAME_BG_SKY */
	{      11756,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{      12532,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      19238,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET */
	{      19310,          0,   12,   12,   12,  3,        256, NULL },		/* AG_CG_LEMI_BULLET */
	{      19342,          0, 1024,  300,  512,  8,      78272, NULL },		/* AG_CG_CUTIN_LEMI */
	{      29126,          0, 1024,  300,  512,  8,      82624, NULL },		/* AG_CG_CUTIN_MAKO */
	{      39454,          0,  410,   90,  208,  8,       1664, NULL },		/* AG_CG_SCORE_BG */
	{      39662,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      39810,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      39902,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      40046,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      40194,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      40322,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      40462,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      40702,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      40862,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      41102,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      41342,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      41570,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      41806,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      42046,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      42262,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      42514,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
	{      42758,          0,  300,  300,  152,  8,       8160, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_1 */
	{      43778,          0,  300,  300,  152,  8,      19328, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_2 */
	{      46194,          0,  300,  300,  152,  8,      20352, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_3 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     13640,     13824,     14008,     14192,     14380,     14568,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_JUMP */
	     14777,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_RUN */
	     14978,     15158,     15342,     15526,     15714,     15898,     16078,     16266,
	     16450,     16646,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     16855,     16983,     17111,     17239,     17375,     17511,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     17668,     17804,     17944,     18084,     18224,     18364,     18500,     18640,
	     18780,     18920,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     19085,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_EFFECT_BOMB */
	     48758,     48918,     49094,     49286,     49526,     49782,     50058,     50342,
	     50634,     50910,     51166,     51398,     51590,     51750,     51894,     51990,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     52055,     52315,     52615,     52959,     53335,     53819,     54303,     54783,
	     55247,     55703,     56147,     56559,     56963,     57319,     57503,     57659,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     57796,     57996,     58240,     58500,     58780,     59096,     59428,     59768,
	     60108,     60404,     60608,     60796,     60960,     61140,     61296,     61444,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     61569,     61713,     61841,     61949,     62049,     62145,     62233,     62313,
	     62389,     62465,     62537,     62601,     62665,     62729,     62793,     62857,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      13620,   50,   50,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      14757,   50,   50,   7680,      1, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_JUMP */
	{      14958,   50,   50,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_RUN */
	{      16835,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      17648,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      19065,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      48738,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      52035,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      57776,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      61549,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
};

/***************************************************************/
/*                     Reserve Member Lists                    */
/***************************************************************/
const u32 ageReserve[1] = { 0 }; /* No Reserve Member */

/***************************************************************/
/*                      User Member Lists                      */
/***************************************************************/
const u32 ageUser[1] = { 0 }; /* No User Member */

/***************************************************************/
/*                      Vram Group Lists                       */
/***************************************************************/
const AGEVramGroup ageVG[] = { { 0, NULL } };
const s16 ageVGCnt = 0;

const u8* ageMotCommon[] = { NULL };
const AGEMotion ageMot[] = {
	{ 0, 0, 0, NULL, },
};
/***************************************************************/
/*                   Sound Rom Member Lists                    */
/***************************************************************/
const AGESoundRomMember ageSRM[] = {
	/* Ch, Length */
	{ 1,      857 },		/* AS_SND_MAKO_GRADE_MAX */
	{ 1,      347 },		/* AS_SND_MAKO_JUMP */
	{ 1,     1526 },		/* AS_SND_MAKO_LEVEL_UP */
	{ 1,     1678 },		/* AS_SND_MAKO_LOSE */
	{ 1,     1221 },		/* AS_SND_MAKO_SELECTED_CHARACTER */
	{ 1,     2409 },		/* AS_SND_MAKO_SKILL_1 */
	{ 1,     1873 },		/* AS_SND_MAKO_SKILL_2 */
	{ 1,     1736 },		/* AS_SND_MAKO_WIN */
	{ 1,     1417 },		/* AS_SND_LEMI_GRADE_MAX */
	{ 1,      277 },		/* AS_SND_LEMI_JUMP */
	{ 1,     1741 },		/* AS_SND_LEMI_LEVEL_UP */
	{ 1,     1246 },		/* AS_SND_LEMI_LOSE */
	{ 1,     1718 },		/* AS_SND_LEMI_SELECTED_CHARACTER */
	{ 1,     1607 },		/* AS_SND_LEMI_SKILL_1 */
	{ 1,      937 },		/* AS_SND_LEMI_SKILL_2 */
	{ 1,     1720 },		/* AS_SND_LEMI_WIN */
	{ 2,    51850 },		/* AS_SND_GAME_BGM */
	{ 2,     1282 },		/* AS_SND_SE_MAKO_WEAPON */
	{ 1,      855 },		/* AS_SND_SE_USE_SKILL */
	{ 2,      391 },		/* AS_SND_SE_LEMI_WEAPON */
	{ 2,      208 },		/* AS_SND_SE_JUMP */
	{ 1,     1529 },		/* AS_SND_SE_BLOCK_CRASH */
	{ 2,     4048 },		/* AS_SND_SE_LEVEL_MAX */
	{ 2,     4336 },		/* AS_SND_SE_LEMI_SKILL */
	{ 2,      835 },		/* AS_SND_SE_TOUCH_NEEDLE */
	{ 2,      653 },		/* AS_SND_SE_LEVEL_UP */
	{ 2,     1619 },		/* AS_SND_SE_MAKO_SKILL */
	{ 1,     2413 },		/* AS_SND_SYSTEM_COUNT_DOWN */
	{ 1,      934 },		/* AS_SND_SYSTEM_GAME_START */
	{ 1,     1718 },		/* AS_SND_LEMI_INTRODUCE */
	{ 1,     1221 },		/* AS_SND_MAKO_INTRODUCE */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };

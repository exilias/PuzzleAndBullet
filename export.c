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
	{      39662,          0,  500,  300,  256,  8,      21760, NULL },		/* AG_CG_RESULT_WORD_WIN */
	{      42382,          0,  500,  300,  256,  8,      28832, NULL },		/* AG_CG_RESULT_WORD_LOSE */
	{      45986,          0,  500,  500,  256,  8,      58144, NULL },		/* AG_CG_LEMI_WIN */
	{      53254,          0,  500,  500,  256,  8,      60032, NULL },		/* AG_CG_LEMI_LOSE */
	{      60758,          0,  590,  500,  296,  8,      56704, NULL },		/* AG_CG_MAKO_WIN */
	{      67846,          0,  550,  500,  280,  8,      55040, NULL },		/* AG_CG_MAKO_LOSE */
	{      74726,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      74874,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      74966,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      75110,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      75258,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      75386,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      75526,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      75766,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      75926,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      76166,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      76406,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      76634,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      76870,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      77110,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      77326,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      77578,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
	{      77822,          0,  300,  300,  152,  8,       8160, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_1 */
	{      78842,          0,  300,  300,  152,  8,      19328, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_2 */
	{      81258,          0,  300,  300,  152,  8,      20352, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_3 */
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
	     83822,     83982,     84158,     84350,     84590,     84846,     85122,     85406,
	     85698,     85974,     86230,     86462,     86654,     86814,     86958,     87054,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     87119,     87379,     87679,     88023,     88399,     88883,     89367,     89847,
	     90311,     90767,     91211,     91623,     92027,     92383,     92567,     92723,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     92860,     93060,     93304,     93564,     93844,     94160,     94492,     94832,
	     95172,     95468,     95672,     95860,     96024,     96204,     96360,     96508,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     96633,     96777,     96905,     97013,     97113,     97209,     97297,     97377,
	     97453,     97529,     97601,     97665,     97729,     97793,     97857,     97921,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_EFFECT_DEATH */
	     98010,     98162,     98342,     98550,     98798,     99074,     99338,     99606,
	     99874,    100150,    100430,    100694,    100946,    101174,    101374,    101522,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      13620,   50,   50,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      14757,   50,   50,   7680,      1, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_JUMP */
	{      14958,   50,   50,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_RUN */
	{      16835,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      17648,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      19065,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      83802,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      87099,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      92840,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      96613,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
	{      97990,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_EFFECT_DEATH */
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

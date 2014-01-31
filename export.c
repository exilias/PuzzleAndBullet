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
	{      11756,          0,  750,  293,  376,  8,      67680, NULL },		/* AG_CG_TITLE_LOGO */
	{      20216,          0,  700,  100,  352,  8,      24416, NULL },		/* AG_CG_PUSH_START_BUTTON */
	{      23268,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{      24044,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      30750,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET */
	{      30822,          0,   12,   12,   12,  3,        256, NULL },		/* AG_CG_LEMI_BULLET */
	{      30854,          0, 1024,  300,  512,  8,      78272, NULL },		/* AG_CG_CUTIN_LEMI */
	{      40638,          0, 1024,  300,  512,  8,      82624, NULL },		/* AG_CG_CUTIN_MAKO */
	{      50966,          0,  410,   90,  208,  8,       1664, NULL },		/* AG_CG_SCORE_BG */
	{      51174,          0,  400,  240,  200,  8,      26016, NULL },		/* AG_CG_RESULT_WORD_LOSE */
	{      54426,          0,  400,  240,  200,  8,      18656, NULL },		/* AG_CG_RESULT_WORD_WIN */
	{      56758,          0,  300,  300,  152,  8,      34816, NULL },		/* AG_CG_LEMI_LOSE */
	{      61110,          0,  300,  300,  152,  8,      34080, NULL },		/* AG_CG_LEMI_WIN */
	{      65370,          0,  300,  273,  152,  8,      31552, NULL },		/* AG_CG_MAKO_LOSE */
	{      69314,          0,  300,  273,  152,  8,      31872, NULL },		/* AG_CG_MAKO_WIN */
	{      73298,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      73446,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      73538,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      73682,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      73830,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      73958,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      74098,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      74338,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      74498,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      74738,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      74978,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      75206,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      75442,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      75682,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      75898,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      76150,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
	{      76394,          0,  300,  300,  152,  8,       8160, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_1 */
	{      77414,          0,  300,  300,  152,  8,      19328, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_2 */
	{      79830,          0,  300,  300,  152,  8,      20352, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_3 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     25152,     25336,     25520,     25704,     25892,     26080,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_JUMP */
	     26289,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_RUN */
	     26490,     26670,     26854,     27038,     27226,     27410,     27590,     27778,
	     27962,     28158,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     28367,     28495,     28623,     28751,     28887,     29023,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     29180,     29316,     29456,     29596,     29736,     29876,     30012,     30152,
	     30292,     30432,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     30597,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_EFFECT_BOMB */
	     82394,     82554,     82730,     82922,     83162,     83418,     83694,     83978,
	     84270,     84546,     84802,     85034,     85226,     85386,     85530,     85626,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     85691,     85951,     86251,     86595,     86971,     87455,     87939,     88419,
	     88883,     89339,     89783,     90195,     90599,     90955,     91139,     91295,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     91432,     91632,     91876,     92136,     92416,     92732,     93064,     93404,
	     93744,     94040,     94244,     94432,     94596,     94776,     94932,     95080,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     95205,     95349,     95477,     95585,     95685,     95781,     95869,     95949,
	     96025,     96101,     96173,     96237,     96301,     96365,     96429,     96493,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_EFFECT_DEATH */
	     96582,     96734,     96914,     97122,     97370,     97646,     97910,     98178,
	     98446,     98722,     99002,     99266,     99518,     99746,     99946,    100094,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      25132,   50,   50,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      26269,   50,   50,   7680,      1, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_JUMP */
	{      26470,   50,   50,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_RUN */
	{      28347,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      29160,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      30577,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      82374,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      85671,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      91412,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      95185,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
	{      96562,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_EFFECT_DEATH */
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
	{ 1,     1669 },		/* AS_SND_SYSTEM_PUSH_START */
	{ 2,     2612 },		/* AS_SND_SE_PUSHED_START_BUTTON */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };

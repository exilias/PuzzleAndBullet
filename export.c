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
	{      11756,          0,  700,  100,  352,  8,      24416, NULL },		/* AG_CG_PUSH_START_BUTTON */
	{      14808,          0, 1024,  400,  512,  8,      85344, NULL },		/* AG_CG_TITLE_LOGO */
	{      25476,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{      26252,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      32958,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET */
	{      33030,          0,   12,   12,   12,  3,        256, NULL },		/* AG_CG_LEMI_BULLET */
	{      33062,          0, 1024,  300,  512,  8,      78272, NULL },		/* AG_CG_CUTIN_LEMI */
	{      42846,          0, 1024,  300,  512,  8,      82624, NULL },		/* AG_CG_CUTIN_MAKO */
	{      53174,          0,  410,   90,  208,  8,       1664, NULL },		/* AG_CG_SCORE_BG */
	{      53382,          0,  400,  240,  200,  8,      26016, NULL },		/* AG_CG_RESULT_WORD_LOSE */
	{      56634,          0,  400,  240,  200,  8,      18656, NULL },		/* AG_CG_RESULT_WORD_WIN */
	{      58966,          0,  300,  300,  152,  8,      34816, NULL },		/* AG_CG_LEMI_LOSE */
	{      63318,          0,  300,  300,  152,  8,      34080, NULL },		/* AG_CG_LEMI_WIN */
	{      67578,          0,  300,  273,  152,  8,      31552, NULL },		/* AG_CG_MAKO_LOSE */
	{      71522,          0,  300,  273,  152,  8,      31872, NULL },		/* AG_CG_MAKO_WIN */
	{      75506,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      75654,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      75746,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      75890,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      76038,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      76166,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      76306,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      76546,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      76706,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      76946,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      77186,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      77414,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      77650,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      77890,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      78106,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      78358,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
	{      78602,          0,  300,  300,  152,  8,       8160, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_1 */
	{      79622,          0,  300,  300,  152,  8,      19328, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_2 */
	{      82038,          0,  300,  300,  152,  8,      20352, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_3 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     27360,     27544,     27728,     27912,     28100,     28288,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_JUMP */
	     28497,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_RUN */
	     28698,     28878,     29062,     29246,     29434,     29618,     29798,     29986,
	     30170,     30366,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     30575,     30703,     30831,     30959,     31095,     31231,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     31388,     31524,     31664,     31804,     31944,     32084,     32220,     32360,
	     32500,     32640,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     32805,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_EFFECT_BOMB */
	     84602,     84762,     84938,     85130,     85370,     85626,     85902,     86186,
	     86478,     86754,     87010,     87242,     87434,     87594,     87738,     87834,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     87899,     88159,     88459,     88803,     89179,     89663,     90147,     90627,
	     91091,     91547,     91991,     92403,     92807,     93163,     93347,     93503,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     93640,     93840,     94084,     94344,     94624,     94940,     95272,     95612,
	     95952,     96248,     96452,     96640,     96804,     96984,     97140,     97288,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     97413,     97557,     97685,     97793,     97893,     97989,     98077,     98157,
	     98233,     98309,     98381,     98445,     98509,     98573,     98637,     98701,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_EFFECT_DEATH */
	     98790,     98942,     99122,     99330,     99578,     99854,    100118,    100386,
	    100654,    100930,    101210,    101474,    101726,    101954,    102154,    102302,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      27340,   50,   50,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      28477,   50,   50,   7680,      1, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_JUMP */
	{      28678,   50,   50,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_RUN */
	{      30555,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      31368,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      32785,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      84582,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      87879,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      93620,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      97393,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
	{      98770,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_EFFECT_DEATH */
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

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
	{       5480,          0,   80,   53,   40,  8,       3232, NULL },		/* AG_CG_GAME_BG_AIRSHIP */
	{       5884,          0,  300,  350,  152,  8,      10720, NULL },		/* AG_CG_GAME_BG_SUN */
	{       7224,          0,  300,  350,  152,  8,      13344, NULL },		/* AG_CG_GAME_BG_SUN_SHINE */
	{       8892,          0, 1024,  120,  512,  8,       6624, NULL },		/* AG_CG_GAME_BG_SAND */
	{       9720,          0, 1024,  768,  512,  8,      19520, NULL },		/* AG_CG_GAME_BG_SKY */
	{      12160,          0,  750,  293,  376,  8,      67680, NULL },		/* AG_CG_TITLE_LOGO */
	{      20620,          0,  700,  100,  352,  8,      24416, NULL },		/* AG_CG_PUSH_START_BUTTON */
	{      23672,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{      24448,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      31154,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET */
	{      31226,          0,   12,   12,   12,  3,        256, NULL },		/* AG_CG_LEMI_BULLET */
	{      31258,          0, 1024,  300,  512,  8,      78272, NULL },		/* AG_CG_CUTIN_LEMI */
	{      41042,          0, 1024,  300,  512,  8,      82624, NULL },		/* AG_CG_CUTIN_MAKO */
	{      51370,          0,  410,   90,  208,  8,       1664, NULL },		/* AG_CG_SCORE_BG */
	{      51578,          0,  400,  240,  200,  8,      26016, NULL },		/* AG_CG_RESULT_WORD_LOSE */
	{      54830,          0,  400,  240,  200,  8,      18656, NULL },		/* AG_CG_RESULT_WORD_WIN */
	{      57162,          0,  300,  300,  152,  8,      34816, NULL },		/* AG_CG_LEMI_LOSE */
	{      61514,          0,  300,  300,  152,  8,      34080, NULL },		/* AG_CG_LEMI_WIN */
	{      65774,          0,  300,  273,  152,  8,      31552, NULL },		/* AG_CG_MAKO_LOSE */
	{      69718,          0,  300,  273,  152,  8,      31872, NULL },		/* AG_CG_MAKO_WIN */
	{      73702,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      73850,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      73942,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      74086,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      74234,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      74362,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      74502,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      74742,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      74902,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      75142,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      75382,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      75610,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      75846,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      76086,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      76302,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      76554,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
	{      76798,          0,  300,  300,  152,  8,       8160, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_1 */
	{      77818,          0,  300,  300,  152,  8,      19328, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_2 */
	{      80234,          0,  300,  300,  152,  8,      20352, NULL },		/* AG_CG_COUNT_DOWN_NUMBER_3 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     25556,     25740,     25924,     26108,     26296,     26484,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_JUMP */
	     26693,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_RUN */
	     26894,     27074,     27258,     27442,     27630,     27814,     27994,     28182,
	     28366,     28562,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     28771,     28899,     29027,     29155,     29291,     29427,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     29584,     29720,     29860,     30000,     30140,     30280,     30416,     30556,
	     30696,     30836,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     31001,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_EFFECT_BOMB */
	     82798,     82958,     83134,     83326,     83566,     83822,     84098,     84382,
	     84674,     84950,     85206,     85438,     85630,     85790,     85934,     86030,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     86095,     86355,     86655,     86999,     87375,     87859,     88343,     88823,
	     89287,     89743,     90187,     90599,     91003,     91359,     91543,     91699,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     91836,     92036,     92280,     92540,     92820,     93136,     93468,     93808,
	     94148,     94444,     94648,     94836,     95000,     95180,     95336,     95484,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     95609,     95753,     95881,     95989,     96089,     96185,     96273,     96353,
	     96429,     96505,     96577,     96641,     96705,     96769,     96833,     96897,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_EFFECT_DEATH */
	     96986,     97138,     97318,     97526,     97774,     98050,     98314,     98582,
	     98850,     99126,     99406,     99670,     99922,    100150,    100350,    100498,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      25536,   50,   50,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      26673,   50,   50,   7680,      1, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_JUMP */
	{      26874,   50,   50,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_RUN */
	{      28751,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      29564,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      30981,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      82778,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      86075,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      91816,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      95589,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
	{      96966,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_EFFECT_DEATH */
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
	{ 2,     1282 },		/* AS_SND_SE_DEAD */
	{ 2,     2612 },		/* AS_SND_SE_PUSHED_START_BUTTON */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };

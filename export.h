#ifndef __AG_EXPORT__
#define __AG_EXPORT__

#include <agexport.h>
#include <ag3d.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************/
/*                       FrameBuffer                           */
/***************************************************************/
#define AGE_FB_WIDTH	(1024)
#define AGE_FB_HEIGHT	(768)
#define AGE_DISP_WIDTH	(1024)
#define AGE_DISP_HEIGHT	(768)
#define AGE_FB_ADDR0	(7602176)
#define AGE_FB_ADDR1	(6815744)
#define AGE_ZB_ADDR	(6815744)
#define AGE_ZB_DEPTH	(4)
#define AGE_ZMD	(1)
#define AGE_AAC_ADDR	(13631488)
#define AGE_AAC_SIZE	(13631488)
#define AGE_SOUND_ROM_OFFSET	(0x400000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_BLOCK_BLUE_1	(0)
#define AG_CG_BLOCK_BLUE_2	(1)
#define AG_CG_BLOCK_BLUE_3	(2)
#define AG_CG_BLOCK_GREEN_1	(3)
#define AG_CG_BLOCK_GREEN_2	(4)
#define AG_CG_BLOCK_GREEN_3	(5)
#define AG_CG_BLOCK_RED_1	(6)
#define AG_CG_BLOCK_RED_2	(7)
#define AG_CG_BLOCK_RED_3	(8)
#define AG_CG_BLOCK_NEEDLE	(9)
#define AG_CG_GAME_BG_STAGE_BACK	(10)
#define AG_CG_GAME_BG_CLOUD_BIG	(11)
#define AG_CG_GAME_BG_CLOUD_SMALL	(12)
#define AG_CG_GAME_BG_SUN	(13)
#define AG_CG_GAME_BG_SUN_SHINE	(14)
#define AG_CG_GAME_BG_SAND	(15)
#define AG_CG_GAME_BG_SKY	(16)
#define AG_CG_GAUGE_BG	(17)
#define AG_CG_GAME_BG_STAGE_FRONT	(18)
#define AG_CG_MAKO_BULLET	(19)
#define AG_CG_LEMI_BULLET	(20)
#define AG_CG_CUTIN_LEMI	(21)
#define AG_CG_CUTIN_MAKO	(22)
#define AG_CG_SCORE_BG	(23)
#define AG_CG_RESULT_WORD_WIN	(24)
#define AG_CG_RESULT_WORD_LOSE	(25)
#define AG_CG_LEMI_WIN	(26)
#define AG_CG_LEMI_LOSE	(27)
#define AG_CG_MAKO_WIN	(28)
#define AG_CG_MAKO_LOSE	(29)
#define AG_CG_WEAPON_GRADE_NUMBER_0	(30)
#define AG_CG_WEAPON_GRADE_NUMBER_1	(31)
#define AG_CG_WEAPON_GRADE_NUMBER_2	(32)
#define AG_CG_WEAPON_GRADE_NUMBER_3	(33)
#define AG_CG_WEAPON_GRADE_NUMBER_4	(34)
#define AG_CG_WEAPON_GRADE_NUMBER_5	(35)
#define AG_CG_SCORE_NUMBER_0	(36)
#define AG_CG_SCORE_NUMBER_1	(37)
#define AG_CG_SCORE_NUMBER_2	(38)
#define AG_CG_SCORE_NUMBER_3	(39)
#define AG_CG_SCORE_NUMBER_4	(40)
#define AG_CG_SCORE_NUMBER_5	(41)
#define AG_CG_SCORE_NUMBER_6	(42)
#define AG_CG_SCORE_NUMBER_7	(43)
#define AG_CG_SCORE_NUMBER_8	(44)
#define AG_CG_SCORE_NUMBER_9	(45)
#define AG_CG_COUNT_DOWN_NUMBER_1	(46)
#define AG_CG_COUNT_DOWN_NUMBER_2	(47)
#define AG_CG_COUNT_DOWN_NUMBER_3	(48)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_MAKO_IDLE	(0)
#define AG_RP_MAKO_JUMP	(1)
#define AG_RP_MAKO_RUN	(2)
#define AG_RP_LEMI_IDLE	(3)
#define AG_RP_LEMI_RUN	(4)
#define AG_RP_LEMI_JUMP	(5)
#define AG_RP_EFFECT_BOMB	(6)
#define AG_RP_EFFECT_SUNRISE	(7)
#define AG_RP_EFFECT_GRADE_MAX	(8)
#define AG_RP_EFFECT_LEVEL_UP	(9)
#define AG_RP_EFFECT_DEATH	(10)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                       Sound Member Symbol                   */
/***************************************************************/
#define AS_SND_MAKO_GRADE_MAX	(0)
#define AS_SND_MAKO_JUMP	(1)
#define AS_SND_MAKO_LEVEL_UP	(2)
#define AS_SND_MAKO_LOSE	(3)
#define AS_SND_MAKO_SELECTED_CHARACTER	(4)
#define AS_SND_MAKO_SKILL_1	(5)
#define AS_SND_MAKO_SKILL_2	(6)
#define AS_SND_MAKO_WIN	(7)
#define AS_SND_LEMI_GRADE_MAX	(8)
#define AS_SND_LEMI_JUMP	(9)
#define AS_SND_LEMI_LEVEL_UP	(10)
#define AS_SND_LEMI_LOSE	(11)
#define AS_SND_LEMI_SELECTED_CHARACTER	(12)
#define AS_SND_LEMI_SKILL_1	(13)
#define AS_SND_LEMI_SKILL_2	(14)
#define AS_SND_LEMI_WIN	(15)
#define AS_SND_GAME_BGM	(16)
#define AS_SND_SE_MAKO_WEAPON	(17)
#define AS_SND_SE_USE_SKILL	(18)
#define AS_SND_SE_LEMI_WEAPON	(19)
#define AS_SND_SE_JUMP	(20)
#define AS_SND_SE_BLOCK_CRASH	(21)
#define AS_SND_SE_LEVEL_MAX	(22)
#define AS_SND_SE_LEMI_SKILL	(23)
#define AS_SND_SE_TOUCH_NEEDLE	(24)
#define AS_SND_SE_LEVEL_UP	(25)
#define AS_SND_SE_MAKO_SKILL	(26)
#define AS_SND_SYSTEM_COUNT_DOWN	(27)
#define AS_SND_SYSTEM_GAME_START	(28)
#define AS_SND_LEMI_INTRODUCE	(29)
#define AS_SND_MAKO_INTRODUCE	(30)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[49];
extern const AGERM3Member ageRM3[11];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[31];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */

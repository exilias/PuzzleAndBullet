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
#define AGE_SOUND_ROM_OFFSET	(0x800000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_BLOCK_BLUE	(0)
#define AG_CG_BLOCK_GREEN	(1)
#define AG_CG_BLOCK_RED	(2)
#define AG_CG_BLOCK_NEEDLE	(3)
#define AG_CG_GAME_BG	(4)
#define AG_CG_GAUGE_BG	(5)
#define AG_CG_GAME_BG_STAGE_BACK_MAKO	(6)
#define AG_CG_GAME_BG_STAGE_FRONT	(7)
#define AG_CG_MAKO_BULLET_LEFT	(8)
#define AG_CG_MAKO_BULLET_RIGHT	(9)
#define AG_CG_MAKO_CUT_IN	(10)
#define AG_CG_SCORE_NUMBER_0	(11)
#define AG_CG_SCORE_NUMBER_1	(12)
#define AG_CG_SCORE_NUMBER_2	(13)
#define AG_CG_SCORE_NUMBER_3	(14)
#define AG_CG_SCORE_NUMBER_4	(15)
#define AG_CG_SCORE_NUMBER_5	(16)
#define AG_CG_SCORE_NUMBER_6	(17)
#define AG_CG_SCORE_NUMBER_7	(18)
#define AG_CG_SCORE_NUMBER_8	(19)
#define AG_CG_SCORE_NUMBER_9	(20)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_MAKO_IDLE	(0)
#define AG_RP_MAKO_RUN	(1)
#define AG_RP_MAKO_JUMP	(2)
#define AG_RP_LEMI_IDLE	(3)
#define AG_RP_LEMI_RUN	(4)
#define AG_RP_LEMI_JUMP	(5)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[21];
extern const AGERM3Member ageRM3[6];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */

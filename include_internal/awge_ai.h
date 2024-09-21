/*******************************************************************************
*                                 AWorks
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      ametal.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief 
 *
 * \internal
 * \par Modification history
 * - 1.00 18-06-23  win, first implementation.
 * \endinternal
 */


#ifndef __AWGE_AI_H
#define __AWGE_AI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

/**
 * \brief
 */
typedef struct awge_ai_move_coord {
    int x_old;
    int y_old;
    int x_move;
    int y_move;
    int bound_dir;
} awge_ai_move_coord_t;

/**
 * \brief AI
 */
typedef struct {
    int dir_style;
    int evade_dir[8][5];
} awge_ai_t;

/**
 * \brief AI≥ı ºªØ
 */
aw_err_t awge_ai_init (awge_ai_t *p_ai, int d_style);

/**
 * \brief get AI HIT RECT
 */
void awge_ai_hit_rect_get (awge_ai_t          *p_ai,
                           awge_sprite_t      *p_sp,
                           int                 sp_size_times,
                           awge_engine_rect_t *p_test);

/**
 * \brief get move coord
 */
struct awge_move_coord awge_ai_move_coord_get (awge_ai_t          *p_ai,
                                               awge_sprite_t      *p_npc_sp,
                                               int                 dir,
                                               int                 speed,
                                               awge_engine_rect_t  boundary);

/**
 * \brief AI wander
 */
void awge_ai_wander (awge_ai_t          *p_ai,
                     awge_sprite_t      *p_npc_sp,
                     int                 npc_dir,
                     int                 speed,
                     awge_engine_rect_t  boundary);

/**
 * \brief AI wander
 */
void awge_ai_wander_map (awge_ai_t     *p_ai,
                         awge_sprite_t *p_npc_sp,
                         int            npc_dir,
                         int            speed,
                         awge_map_t    *p_map);

/**
 * \brief AI evade
 */
void awge_ai_evade (awge_ai_t     *p_ai,
                    awge_sprite_t *p_npc_sp,
                    awge_sprite_t *p_player);

/**
 * \brief
 */
void awge_ai_overlay_check (awge_ai_t     *p_ai,
                            awge_sprite_t *p_npc_sp,
                            awge_vector_t *p_sprite_set);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_AI_H */

/* end of file */

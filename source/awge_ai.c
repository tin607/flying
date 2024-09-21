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
*******************************************************************************/

/**
 * \file
 * \brief 
 *
 * \internal
 * \par Modification history
 * - 1.00 18-12-01  win, first implementation.
 * \endinternal
 */

#include "awge_internal.h"

static int __g_ai_evade_dir[8][5]={
    {
        AWGE_GAME_DIR_RIGHT,
        AWGE_GAME_DIR_DOWN,
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_RIGHT_UP,
        AWGE_GAME_DIR_RIGHT_DOWN,
    },
    {
        AWGE_GAME_DIR_LEFT,
        AWGE_GAME_DIR_DOWN,
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_LEFT_UP,
        AWGE_GAME_DIR_LEFT_DOWN,
    },
    {
        AWGE_GAME_DIR_DOWN,
        AWGE_GAME_DIR_LEFT,
        AWGE_GAME_DIR_RIGHT,
        AWGE_GAME_DIR_LEFT_DOWN,
        AWGE_GAME_DIR_RIGHT_DOWN,
    },
    {
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_LEFT,
        AWGE_GAME_DIR_RIGHT,
        AWGE_GAME_DIR_LEFT_UP,
        AWGE_GAME_DIR_RIGHT_UP,
    },
    {
        AWGE_GAME_DIR_RIGHT_DOWN,
        AWGE_GAME_DIR_RIGHT_UP,
        AWGE_GAME_DIR_RIGHT,
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_DOWN,
    },
    {
        AWGE_GAME_DIR_RIGHT_UP,
        AWGE_GAME_DIR_RIGHT_DOWN,
        AWGE_GAME_DIR_RIGHT,
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_DOWN,
    },
    {
        AWGE_GAME_DIR_LEFT_DOWN,
        AWGE_GAME_DIR_LEFT_UP,
        AWGE_GAME_DIR_LEFT,
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_DOWN,
    },
    {
        AWGE_GAME_DIR_LEFT_UP,
        AWGE_GAME_DIR_LEFT_DOWN,
        AWGE_GAME_DIR_LEFT,
        AWGE_GAME_DIR_UP,
        AWGE_GAME_DIR_DOWN,
    }
};

/**
 * \brief AI³õÊ¼»¯
 */
aw_err_t awge_ai_init (awge_ai_t *p_ai, int d_style)
{
    p_ai->dir_style = d_style;
    return AW_OK;
}

/**
 * \brief get AI HIT RECT
 */
void awge_ai_hit_rect_get (awge_ai_t          *p_ai,
                           awge_sprite_t      *p_sp,
                           int                 sp_size_times,
                           awge_engine_rect_t *p_test)
{
    int sp_width  = awge_sprite_ratio_size_get(p_sp).cx;
    int sp_height = awge_sprite_ratio_size_get(p_sp).cy;

    if (p_ai == NULL || p_sp == NULL || sp_size_times == 0) {
        return;
    }

    switch(awge_sprite_dir_get(p_sp)) {

    case AWGE_GAME_DIR_LEFT:
        p_test->left   = awge_layer_x_get(&p_sp->layer) -
                         sp_size_times * sp_width;
        p_test->top    = awge_layer_y_get(&p_sp->layer);
        p_test->right  = awge_layer_x_get(&p_sp->layer);
        p_test->bottom = awge_layer_y_get(&p_sp->layer) + sp_height;;
        break;

    case AWGE_GAME_DIR_RIGHT:
        p_test->left   = awge_layer_x_get(&p_sp->layer) + sp_width;
        p_test->top    = awge_layer_y_get(&p_sp->layer);
        p_test->right  = awge_layer_x_get(&p_sp->layer) +
                         (sp_size_times + 1) * sp_width;
        p_test->bottom = awge_layer_y_get(&p_sp->layer) + sp_height;;
        break;

    case AWGE_GAME_DIR_UP:
        p_test->left   = awge_layer_x_get(&p_sp->layer);
        p_test->top    = awge_layer_y_get(&p_sp->layer) -
                         sp_size_times * sp_height;
        p_test->right  = awge_layer_x_get(&p_sp->layer) + sp_width;
        p_test->bottom = awge_layer_y_get(&p_sp->layer);
        break;

    case AWGE_GAME_DIR_DOWN:
        p_test->left   = awge_layer_x_get(&p_sp->layer);
        p_test->top    = awge_layer_y_get(&p_sp->layer) + sp_height;;
        p_test->right  = awge_layer_x_get(&p_sp->layer) + sp_width;
        p_test->bottom = awge_layer_y_get(&p_sp->layer) +
                         (sp_size_times + 1) * sp_height;
        break;

    case AWGE_GAME_DIR_LEFT_UP:
        p_test->left   = awge_layer_x_get(&p_sp->layer) -
                         sp_size_times * sp_width;
        p_test->top    = awge_layer_y_get(&p_sp->layer) -
                         sp_size_times * sp_height;
        p_test->right  = awge_layer_x_get(&p_sp->layer);
        p_test->bottom = awge_layer_y_get(&p_sp->layer);
        break;

    case AWGE_GAME_DIR_LEFT_DOWN:
        p_test->left   = awge_layer_x_get(&p_sp->layer) -
                         sp_size_times * sp_width;
        p_test->top    = awge_layer_y_get(&p_sp->layer) + sp_height;;
        p_test->right  = awge_layer_x_get(&p_sp->layer);
        p_test->bottom = awge_layer_y_get(&p_sp->layer) +
                         (sp_size_times + 1) * sp_height;
        break;

    case AWGE_GAME_DIR_RIGHT_UP:
        p_test->left   = awge_layer_x_get(&p_sp->layer) + sp_width;
        p_test->top    = awge_layer_y_get(&p_sp->layer) -
                         sp_size_times * sp_height;
        p_test->right  = awge_layer_x_get(&p_sp->layer) +
                         (sp_size_times + 1) * sp_width;
        p_test->bottom = awge_layer_y_get(&p_sp->layer);
        break;

    case AWGE_GAME_DIR_RIGHT_DOWN:
        p_test->left   = awge_layer_x_get(&p_sp->layer) + sp_width;
        p_test->top    = awge_layer_y_get(&p_sp->layer) + sp_height;;
        p_test->right  = awge_layer_x_get(&p_sp->layer) +
                         (sp_size_times + 1) * sp_width;
        p_test->bottom = awge_layer_y_get(&p_sp->layer) +
                         (sp_size_times + 1) * sp_height;
        break;
    }
}

/**
 * \brief get move coord
 */
struct awge_move_coord awge_ai_move_coord_get (awge_ai_t          *p_ai,
                                               awge_sprite_t      *p_npc_sp,
                                               int                 dir,
                                               int                 speed,
                                               awge_engine_rect_t  boundary)
{
    awge_ai_move_coord_t mrate;
    int                  next_step_x, next_step_y;
    int                  speed_x = 0, speed_y = 0;

    mrate.bound_dir = -1;

    int sp_width  = awge_sprite_ratio_size_get(p_npc_sp).cx;
    int sp_height = awge_sprite_ratio_size_get(p_npc_sp).cy;

    switch (dir) {

    case AWGE_GAME_DIR_LEFT:
        speed_x     = -speed;
        speed_y     = 0;
        next_step_x = awge_layer_x_get(&p_npc_sp->layer) - speed;

        if (next_step_x <= boundary.left) {
            speed_x         =  -(awge_layer_x_get(&p_npc_sp->layer) -
                                 boundary.left);
            mrate.bound_dir = AWGE_GAME_DIR_LEFT;
        }
        break;

    case AWGE_GAME_DIR_RIGHT:
        speed_x     = speed;
        speed_y     = 0;
        next_step_x = awge_layer_x_get(&p_npc_sp->layer) + sp_width + speed;

        if(next_step_x >= boundary.right) {
            speed_x         = boundary.right -
                              (awge_layer_x_get(&p_npc_sp->layer) + sp_width);
            mrate.bound_dir = AWGE_GAME_DIR_RIGHT;
        }
        break;

    case AWGE_GAME_DIR_UP:
        speed_x     = 0;
        speed_y     = -speed;
        next_step_y = awge_layer_y_get(&p_npc_sp->layer) - speed;

        if (next_step_y <= boundary.top) {
            speed_y        = -(awge_layer_y_get(&p_npc_sp->layer) -
                               boundary.top);
            mrate.bound_dir = AWGE_GAME_DIR_UP;
        }
        break;

    case AWGE_GAME_DIR_DOWN:
        speed_x     = 0;
        speed_y     = speed;
        next_step_y = awge_layer_y_get(&p_npc_sp->layer) + sp_height + speed;

        if (next_step_y >= boundary.bottom) {
            speed_y         = boundary.bottom -
                              (awge_layer_y_get(&p_npc_sp->layer) + sp_height);
            mrate.bound_dir = AWGE_GAME_DIR_DOWN;
        }
        break;

    case AWGE_GAME_DIR_LEFT_UP:
        speed_x     = -speed;
        speed_y     = -speed;
        next_step_x = awge_layer_y_get(&p_npc_sp->layer) - speed;

        if (next_step_x <= boundary.left) {
            speed_x = -(awge_layer_x_get(&p_npc_sp->layer) - boundary.left);
            speed_y = -(awge_layer_x_get(&p_npc_sp->layer) - boundary.left);

            mrate.bound_dir = AWGE_GAME_DIR_LEFT;
            break;
        }

        next_step_y = awge_layer_y_get(&p_npc_sp->layer) - speed;
        if(next_step_y <= boundary.top) {
            speed_y = -(awge_layer_y_get(&p_npc_sp->layer) - boundary.top);
            speed_x = -(awge_layer_y_get(&p_npc_sp->layer) - boundary.top);

            mrate.bound_dir = AWGE_GAME_DIR_UP;
        }
        break;

    case AWGE_GAME_DIR_LEFT_DOWN:
        speed_x     = -speed;
        speed_y     = speed;
        next_step_x = awge_layer_x_get(&p_npc_sp->layer) - speed;

        if (next_step_x <= boundary.left) {
            speed_x = -(awge_layer_x_get(&p_npc_sp->layer) - boundary.left);
            speed_y =  (awge_layer_x_get(&p_npc_sp->layer) - boundary.left);
            mrate.bound_dir = AWGE_GAME_DIR_LEFT;
            break;
        }

        next_step_y = awge_layer_y_get(&p_npc_sp->layer) + sp_height + speed;
        if (next_step_y >=boundary.bottom) {
            speed_y =   boundary.bottom -
                       (awge_layer_y_get(&p_npc_sp->layer) + sp_height);
            speed_x = -(boundary.bottom -
                       (awge_layer_y_get(&p_npc_sp->layer) + sp_height));
            mrate.bound_dir = AWGE_GAME_DIR_DOWN;
        }
        break;

    case AWGE_GAME_DIR_RIGHT_UP:
        speed_x     = speed;
        speed_y     = -speed;
        next_step_x = awge_layer_x_get(&p_npc_sp->layer) + sp_width + speed;

        if (next_step_x >= boundary.right) {
            speed_x =   boundary.right -
                       (awge_layer_x_get(&p_npc_sp->layer) + sp_width);
            speed_y = -(boundary.right -
                       (awge_layer_x_get(&p_npc_sp->layer) + sp_width));
            mrate.bound_dir = AWGE_GAME_DIR_RIGHT;
            break;
        }

        next_step_y = awge_layer_y_get(&p_npc_sp->layer) - speed;
        if (next_step_y <= boundary.top) {
            speed_y = -(awge_layer_y_get(&p_npc_sp->layer) - boundary.top);
            speed_x  = awge_layer_y_get(&p_npc_sp->layer) - boundary.top;
            mrate.bound_dir = AWGE_GAME_DIR_UP;
        }
        break;

    case AWGE_GAME_DIR_RIGHT_DOWN:
        speed_x     = speed;
        speed_y     = speed;
        next_step_x = awge_layer_x_get(&p_npc_sp->layer) + sp_width + speed;

        if (next_step_x >= boundary.right) {
            speed_x = boundary.right -
                      (awge_layer_x_get(&p_npc_sp->layer) + sp_width);
            speed_y = boundary.right -
                      (awge_layer_x_get(&p_npc_sp->layer) + sp_width);
            mrate.bound_dir = AWGE_GAME_DIR_RIGHT;
            break;
        }

        next_step_y = awge_layer_y_get(&p_npc_sp->layer) + sp_height + speed;
        if (next_step_y >=boundary.bottom) {
            speed_y = boundary.bottom -
                      (awge_layer_y_get(&p_npc_sp->layer) + sp_height);
            speed_x = boundary.bottom -
                      (awge_layer_y_get(&p_npc_sp->layer) + sp_height);
            mrate.bound_dir = AWGE_GAME_DIR_DOWN;
        }
        break;

    default:
        break;
    }

    mrate.x_move = speed_x;
    mrate.y_move = speed_y;
    mrate.x_old  = awge_layer_x_get(&p_npc_sp->layer);
    mrate.y_old  = awge_layer_y_get(&p_npc_sp->layer);
    return mrate;
}

/**
 * \brief AI wander
 */
void awge_ai_wander (awge_ai_t          *p_ai,
                     awge_sprite_t      *p_npc_sp,
                     int                 npc_dir,
                     int                 speed,
                     awge_engine_rect_t  boundary)
{
    awge_ai_move_coord_t mrate = awge_ai_move_coord_get(p_ai,
                                                        p_npc_sp,
                                                        npc_dir,
                                                        speed,
                                                        boundary);

    if (mrate.bound_dir == -1 ) {
        awge_layer_move(&p_npc_sp->layer, mrate.x_move, mrate.y_move);

    }

    if (mrate.bound_dir != -1) {
        int r_dir = 0;

        if (p_ai->dir_style == 8) {
            r_dir = rand() % 5;
        } else {
            r_dir = rand() % 3;
        }
        awge_layer_position_set(&p_npc_sp->layer, mrate.x_old, mrate.y_old);
        awge_sprite_dir_set(p_npc_sp, __g_ai_evade_dir[mrate.bound_dir][r_dir]);
    }
}

/**
 * \brief AI wander
 */
void awge_ai_wander_map (awge_ai_t     *p_ai,
                         awge_sprite_t *p_npc_sp,
                         int            npc_dir,
                         int            speed,
                         awge_map_t    *p_map)
{
    awge_engine_rect_t   map_bound;
    awge_ai_move_coord_t mrate;
    int                  r_dir = 0;

    map_bound.left   = awge_layer_x_get(&p_map->layer);
    map_bound.top    = awge_layer_y_get(&p_map->layer);
    map_bound.right  = awge_layer_x_get(&p_map->layer) +
                       awge_layer_width_get(&p_map->layer);
    map_bound.bottom = awge_layer_y_get(&p_map->layer) +
                       awge_layer_height_get(&p_map->layer);

    mrate = awge_ai_move_coord_get(p_npc_sp, npc_dir, speed, map_bound);

    if (p_ai->dir_style == 8) {
        r_dir = rand() % 5;
    } else {
        r_dir = rand() % 3;
    }

    if (mrate.bound_dir == -1 ) {
        awge_layer_move(&p_npc_sp->layer, mrate.x_move, mrate.y_move);
    }

    if (mrate.bound_dir != -1) {
        awge_layer_position_set(&p_npc_sp->layer, mrate.x_old, mrate.y_old);
        awge_sprite_dir_set(p_npc_sp, __g_ai_evade_dir[mrate.bound_dir][r_dir]);
    }

    if (awge_sprite_collide_with_map(p_npc_sp, p_map)) {
        awge_layer_position_set(&p_npc_sp->layer, mrate.x_old, mrate.y_old);
        awge_sprite_dir_set(
            p_npc_sp,
            __g_ai_evade_dir[awge_sprite_dir_get(p_npc_sp)][rand() % 3]);
    }
}

/**
 * \brief AI evade
 */
void awge_ai_evade (awge_ai_t     *p_ai,
                    awge_sprite_t *p_npc_sp,
                    awge_sprite_t *p_player)
{
    awge_engine_rect_t prc_dst;
    awge_engine_rect_t test_rect;
    awge_engine_rect_t player_rect = {
        awge_layer_x_get(&p_player->layer),
        awge_layer_y_get(&p_player->layer),
        awge_layer_x_get(&p_player->layer) +
        awge_sprite_ratio_size_get(p_player).cx,
        awge_layer_y_get(&p_player->layer) +
        awge_sprite_ratio_size_get(p_player).cy
    };

    awge_ai_hit_rect_get(p_ai, p_npc_sp, 1, &test_rect);
    if ((awge_gui_intersect_rect(&prc_dst, &player_rect, &test_rect))== TRUE) {

        int r_dir = 0;

        if(p_ai->dir_style == 8) {
            r_dir = rand()%5;
        } else {
            r_dir = rand()%3;
        }

        awge_sprite_dir_set(
            p_npc_sp,
            __g_ai_evade_dir[awge_sprite_dir_get(p_npc_sp)][r_dir]);
    }
}

/**
 * \brief overlay check
 */
void awge_ai_overlay_check (awge_ai_t     *p_ai,
                            awge_sprite_t *p_npc_sp,
                            awge_vector_t *p_sprite_set)
{
    awge_sprite_t      *p_sp;
    awge_engine_rect_t  test_rect;
    awge_engine_rect_t  prc_dst;
    int                 r_dir = 0;

    awge_ai_hit_rect_get(p_ai, p_npc_sp, 1, &test_rect);

    if(p_ai->dir_style == 8) {
        r_dir = rand() % 5;
    } else {
        r_dir = rand() % 3;
    }

    for (p_sp  = awge_vector_begin(p_sprite_set);
         p_sp != awge_vector_end(p_sprite_set);
         p_sp++) {

        awge_engine_rect_t rect = {
            awge_layer_x_get(&p_sp->layer),
            awge_layer_y_get(&p_sp->layer),
            awge_layer_x_get(&p_sp->layer) +
            awge_sprite_ratio_size_get(p_sp).cx,
            awge_layer_y_get(&p_sp->layer) +
            awge_sprite_ratio_size_get(p_sp).cy
        };

        if (*p_sp == p_npc_sp) {
            continue;
        }

        if ((awge_gui_intersect_rect(&prc_dst, &rect, &test_rect)) == TRUE) {
            awge_sprite_dir_set(
                p_npc_sp,
                __g_ai_evade_dir[awge_sprite_dir_get(p_npc_sp)][r_dir]);
        }
    }
}

/* end of file */

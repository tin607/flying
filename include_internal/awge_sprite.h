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


#ifndef __AWGE_SPRITE_H
#define __AWGE_SPRITE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

/**
 * \brief sprite
 */
typedef struct {

    /** \brief layer */
    awge_layer_t layer;

    awge_graph_t sp_img;
    awge_graph_t sp_old_img;

    int          frame_cols;
    int          frame_rows;
    int          raw_frames;
    int          total_frames;
    int          forward;
    int          backward;
    bool_t       loop_forward;
    int         *p_frame_sequence;
    float        frame_ratio;
    int          frame_rotate;
    uint8_t      frame_alpha;
    int          dir;
    int          last_dir;
    bool_t       active;
    bool_t       dead;
    int          speed;
    int          level;
    int          score;
    uint32_t     start_time;
    uint32_t     end_time;

    awge_engine_rect_t colide_rect;

    int     colide_width;
    int     colide_height;

    awge_point_t map_block_pt;

} awge_sprite_t;

/**
 * \brief sprite init
 */
aw_err_t awge_sprite_init (awge_sprite_t *p_sprite,
                           const char    *p_img_path,
                           int            frame_width,
                           int            frame_height);

/**
 * \brief get image
 */
static inline
awge_graph_t *awge_sprite_image_get (awge_sprite_t *p_sprite)
{
    return &p_sprite->sp_img;
}

/**
 * \brief set image
 */
static inline
void awge_sprite_image_set (awge_sprite_t *p_sprite, awge_graph_t* p_img)
{
    p_sprite->sp_img = *p_img;
}

/**
 * \brief reset image
 */
static inline
void awge_sprite_image_reset (awge_sprite_t *p_sprite)
{
    p_sprite->sp_img = p_sprite->sp_old_img;
}

/**
 * \brief get ratio
 */
static inline
float awge_sprite_ratio_get (awge_sprite_t *p_sprite)
{
    return p_sprite->frame_ratio;
}

/**
 * \brief set ratio
 */
static inline
void awge_sprite_ratio_set (awge_sprite_t *p_sprite, float rat)
{
    p_sprite->frame_ratio = rat;
}

/**
 * \brief get ratio size
 */
static inline
awge_size_t awge_sprite_ratio_size_get (awge_sprite_t *p_sprite)
{
    awge_size_t ratio;

    ratio.cx = AWGE_ROUND(p_sprite->frame_ratio * p_sprite->layer.width);
    ratio.cy = AWGE_ROUND(p_sprite->frame_ratio * p_sprite->layer.height);

    return ratio;
}

/**
 * \brief get rotation
 */
static inline
int awge_sprite_rotation_get (awge_sprite_t *p_sprite)
{
    return p_sprite->frame_rotate;
}

/**
 * \brief set rotation
 */
static inline
void awge_sprite_rotation_set (awge_sprite_t *p_sprite, int rot)
{
    p_sprite->frame_rotate = rot;
}

/**
 * \brief get alpha
 */
static inline
uint8_t awge_sprite_alpha_get (awge_sprite_t *p_sprite)
{
    return p_sprite->frame_alpha;
}

/**
 * \brief set alpha
 */
static inline
void awge_sprite_alpha_set (awge_sprite_t *p_sprite, uint8_t a)
{
    p_sprite->frame_alpha = a;
}

/**
 * \brief get dir
 */
static inline
int awge_sprite_dir_get (awge_sprite_t *p_sprite)
{
    return p_sprite->dir;
}

/**
 * \brief set dir
 */
static inline
void awge_sprite_dir_set (awge_sprite_t *p_sprite, int d)
{
    p_sprite->dir = d;
}

/**
 * \brief active?
 */
static inline
bool_t awge_sprite_is_active (awge_sprite_t *p_sprite)
{
    return p_sprite->active;
}

/**
 * \brief set active
 */
static inline
void awge_sprite_active_set (awge_sprite_t *p_sprite, bool_t act)
{
    p_sprite->active = act;
}

/**
 * \brief dead?
 */
static inline
bool_t awge_sprite_is_dead (awge_sprite_t *p_sprite)
{
    return p_sprite->dead;
}

/**
 * \brief set dead
 */
static inline
void awge_sprite_dead_set (awge_sprite_t *p_sprite, bool_t dd)
{
    p_sprite->dead = dd;
}

/**
 * \brief get speed
 */
static inline
int awge_sprite_speed_get (awge_sprite_t *p_sprite)
{
    return p_sprite->speed;
}

/**
 * \brief set speed
 */
static inline
void awge_sprite_speed_set (awge_sprite_t *p_sprite, int spd)
{
    p_sprite->speed = spd;
}

/**
 * \brief get level
 */
static inline
int awge_sprite_level_get (awge_sprite_t *p_sprite)
{
    return p_sprite->level;
}

/**
 * \brief
 */
static inline
void awge_sprite_level_set (awge_sprite_t *p_sprite, int lvl)
{
    p_sprite->level = lvl;
}

/**
 * \brief get score
 */
static inline
int awge_sprite_score_get (awge_sprite_t *p_sprite)
{
    return p_sprite->score;
}

/**
 * \brief set score
 */
static inline
void awge_sprite_score_set (awge_sprite_t *p_sprite, int scr)
{
    p_sprite->score = scr;
}

/**
 * \brief set end time
 */
static inline
void awge_sprite_end_time_set (awge_sprite_t *p_sprite, uint32_t time)
{
    p_sprite->end_time = time;
}

/**
 * \brief get end time
 */
static inline
uint32_t awge_sprite_end_time_get (awge_sprite_t *p_sprite)
{
    return p_sprite->end_time;
}

/**
 * \brief set start time
 */
static inline
void awge_sprite_start_time_set (awge_sprite_t *p_sprite, uint32_t time)
{
    p_sprite->start_time = time;
}

/**
 * \brief get
 */
static inline
uint32_t awge_sprite_start_time_get (awge_sprite_t *p_sprite)
{
    return p_sprite->start_time;
}

/**
 * \brief collide rect adjust
 */
static inline
void awge_sprite_collide_rect_adjust (awge_sprite_t *p_sprite,
                                      int            px,
                                      int            py)
{
    if (px == 0 && py == 0) {
        return;
    } else {
        awge_engine_rect_t temp = {
            0, 0, p_sprite->colide_width, p_sprite->colide_height
        };

        awge_gui_hal_rect_inflate(&temp, px, py);
        p_sprite->colide_width  = temp.right  - temp.left;
        p_sprite->colide_height = temp.bottom - temp.top;
    }
}

/**
 * \brief get collide rect
 */
static inline
awge_engine_rect_t *awge_sprite_collide_rect_get (awge_sprite_t *p_sprite)
{

    int c_left, c_top;

    if(p_sprite->frame_ratio > 0) {
        c_left = (awge_sprite_ratio_size_get(p_sprite).cx -
                  p_sprite->colide_width) / 2;
        c_top  = (awge_sprite_ratio_size_get(p_sprite).cy -
                  p_sprite->colide_height) / 2;
    } else {
        c_left = (awge_layer_width_get(&p_sprite->layer) -
                  p_sprite->colide_width) / 2;
        c_top  = (awge_layer_height_get(&p_sprite->layer) -
                  p_sprite->colide_height) / 2;
    }

    p_sprite->colide_rect.left   = (int32_t)p_sprite->layer.x + c_left;
    p_sprite->colide_rect.right  = p_sprite->colide_rect.left +
                                   p_sprite->colide_width;
    p_sprite->colide_rect.top    = (int32_t)p_sprite->layer.y + c_top;
    p_sprite->colide_rect.bottom = p_sprite->colide_rect.top +
                                   p_sprite->colide_height;
    return &p_sprite->colide_rect;
}

/**
 * \brief collide with
 */
static inline
bool_t awge_sprite_collide_with (awge_sprite_t *p_sprite,
                                 awge_sprite_t *p_target,
                                 int            distance)
{
    awge_engine_rect_t target = *(awge_sprite_collide_rect_get(p_target));
    awge_engine_rect_t hit;
    awge_engine_rect_t cur;
    int                cw, tw, ch, th;

    hit.left   = target.left   - distance;
    hit.top    = target.top    - distance;
    hit.right  = target.right  + distance;
    hit.bottom = target.bottom + distance;

    cur = *(awge_sprite_collide_rect_get(p_sprite));

    cw = abs(cur.right  - cur.left);
    tw = abs(hit.right  - hit.left);
    ch = abs(cur.bottom - cur.top);
    th = abs(hit.bottom - hit.top);

    return cur.left <= hit.right  &&
           hit.left <= cur.right  &&
           cur.top  <= hit.bottom &&
           hit.top  <= cur.bottom;
}

/**
 * \brief collide with
 */
bool_t
awge_sprite_collide_with_map (awge_sprite_t *p_sprite, awge_map_t *p_map);

/**
 * \brief get map block point
 */
awge_point_t awge_sprite_map_block_pt_get (awge_sprite_t *p_sprite)
{
    return p_sprite->map_block_pt;
}

/**
 * \brief loop frame
 */
void awge_sprite_frame_loop (awge_sprite_t *p_sprite,
                             bool_t         ahead);

/**
 * \brief frame loop once
 */
bool_t awge_sprite_frame_loop_once (awge_sprite_t *p_sprite,
                                    bool_t         ahead);

/**
 * \brief get raw frams
 */
static inline
int awge_sprite_raw_frames_get (awge_sprite_t *p_sprite)
{
    return p_sprite->raw_frames;
}

/**
 * \brief get total frames
 */
static inline
int awge_sprite_total_frames_get (awge_sprite_t *p_sprite)
{
    return p_sprite->total_frames;
}

/**
 * \brief get frame
 */
static inline
int awge_sprite_frame_get (awge_sprite_t *p_sprite,
                           bool_t         ahead)
{
    if (ahead) {
        return p_sprite->forward;
    } else {
        return p_sprite->backward;
    }
}

/**
 * \brief set frame
 */
static inline
void awge_sprite_frame_set (awge_sprite_t *p_sprite,
                            int            seq_index,
                            bool_t         ahead)
{
    if(ahead) {
        p_sprite->forward = seq_index;
    } else {
        p_sprite->backward = seq_index;
    }
}

/**
 * \brief set sequence
 */
static inline
void awge_sprite_sequence_set (awge_sprite_t *p_sprite,
                               int           *p_sequence,
                               int            length)
{
    p_sprite->p_frame_sequence = p_sequence;
    p_sprite->total_frames     = length;
}

/**
 * \brief get dir
 */
int awge_sprite_dir_get (awge_sprite_t *p_sprite,
                         awge_point_t   mouse);

/**
 * \brief move
 */
bool_t awge_sprite_move_to (awge_sprite_t      *p_sprite,
                            awge_point_t        mouse,
                            awge_point_t        dest,
                            awge_engine_rect_t  boundary,
                            awge_map_t         *p_map);

/**
 * \brief sprite initiate
 */
void awge_sprite_initiate(awge_sprite_t      *p_sprite,
                          awge_sprite_info_t  sprite_info);

/**
 * \brief draw
 */
void awge_srpite_draw (awge_sprite_t *p_sprite, awge_hdc_t *p_hdc);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_SPRITE_H */

/* end of file */

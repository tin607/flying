/*******************************************************************************
*                                 AWorks
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2019 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
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
 * - 1.00 19-04-07  win, first implementation.
 * \endinternal
 */

#include "awge_internal.h"

/**
 * \brief sprite init
 */
aw_err_t awge_sprite_init (awge_sprite_t *p_sprite,
                           const char    *p_img_path,
                           int            frame_width,
                           int            frame_height)
{
    if (strlen(p_img_path) > 0) {
        awge_graph_image_file_Load(p_sprite->sp_img,
                                   p_img_path);
        p_sprite->sp_old_img = p_sprite->sp_img;
    } else {
        aw_kprintf("image path is empty!");
        return -AW_ENOENT;
    }

    if (frame_width == 0 && frame_height == 0) {
        awge_layer_width_set(&p_sprite->layer,
                             awge_graph_image_width_get(&p_sprite->sp_img));
        awge_layer_height_set(&p_sprite->layer,
                              awge_graph_image_height_get(&p_sprite->sp_img));

        p_sprite->total_frames = p_sprite->raw_frames = 0;
    } else {
        awge_layer_width_set(&p_sprite->layer, frame_width);
        awge_layer_height_set(&p_sprite->layer, frame_height);

        p_sprite->frame_cols = awge_graph_image_width_get(&p_sprite->sp_img) /
                               frame_width;
        p_sprite->frame_rows = awge_graph_image_height_get(&p_sprite->sp_img) /
                               frame_height;

        p_sprite->total_frames = p_sprite->frame_cols *
                                 p_sprite->frame_rows;
        p_sprite->raw_frames   = p_sprite->frame_cols *
                                 p_sprite->frame_rows;
        p_sprite->forward  = 0;
        p_sprite->backward = p_sprite->total_frames - 1;
    }

    p_sprite->p_frame_sequence = NULL;
    p_sprite->loop_forward     = TRUE;
    p_sprite->map_block_pt.x   = -1;
    p_sprite->map_block_pt.y   = -1;
    return AW_OK;
}

/**
 * \brief sprite initiate
 */
void awge_sprite_initiate(awge_sprite_t      *p_sprite,
                          awge_sprite_info_t  sprite_info)
{
    awge_layer_position_set(&p_sprite->layer,
                            sprite_info.x,
                            sprite_info.y);

    p_sprite->layer.visible = sprite_info.visible;
    p_sprite->dir           = sprite_info.dir;
    p_sprite->active        = sprite_info.active;
    p_sprite->speed         = sprite_info.speed;
    p_sprite->dead          = sprite_info.dead;
    p_sprite->level         = sprite_info.level;
    p_sprite->score         = sprite_info.score;
    p_sprite->frame_ratio   = sprite_info.ratio;
    p_sprite->frame_rotate  = sprite_info.rotation;
    p_sprite->frame_alpha   = sprite_info.alpha;

    if (p_sprite->frame_ratio > 0) {
        p_sprite->colide_width  = awge_sprite_ratio_size_get(p_sprite).cx;
        p_sprite->colide_height = awge_sprite_ratio_size_get(p_sprite).cy;
    } else {
        p_sprite->colide_width  = (int)awge_layer_width_get(&p_sprite->layer);
        p_sprite->colide_height = (int)awge_layer_height_get(&p_sprite->layer);
    }
}

/**
 * \brief loop frame
 */
void awge_sprite_frame_loop (awge_sprite_t *p_sprite,
                             bool_t         ahead)
{
    p_sprite->loop_forward = ahead;

    if (p_sprite->total_frames > 0) {
        if(ahead == TRUE) {
            p_sprite->forward = p_sprite->forward + 1;
            if (p_sprite->forward > p_sprite->total_frames - 1) {
                p_sprite->forward = 0;
            }
        } else {
            p_sprite->backward = p_sprite->backward - 1;
            if (p_sprite->backward < 0) {
                p_sprite->backward = p_sprite->total_frames - 1;
            }
        }
    }
}

/**
 * \brief frame loop once
 */
bool_t awge_sprite_frame_loop_once (awge_sprite_t *p_sprite,
                                    bool_t         ahead)
{
    p_sprite->loop_forward = ahead;

    if (p_sprite->total_frames <= 0) {
        return TRUE;
    }

    if (p_sprite->total_frames > 0) {

        if (ahead == TRUE) {
            p_sprite->forward = p_sprite->forward + 1;
            if (p_sprite->forward > p_sprite->total_frames-1) {
                p_sprite->forward = 0;
                return TRUE;
            } else {
                return FALSE;
            }
        }

        if (ahead == FALSE) {
            p_sprite->backward = p_sprite->backward - 1;
            if (p_sprite->backward < 0) {
                p_sprite->backward = p_sprite->total_frames-1;
                return TRUE;
            } else {
                return FALSE;
            }
        }
    }

    return TRUE;
}

/**
 * \brief draw
 */
void awge_srpite_draw (awge_sprite_t *p_sprite, awge_hdc_t *p_hdc)
{
    int frame_index = 0;

    if (p_sprite->p_frame_sequence != NULL &&
        p_sprite->backward         >= 0    &&
        p_sprite->forward          >= 0) {

        if(p_sprite->loop_forward == FALSE) {
            frame_index = p_sprite->p_frame_sequence[p_sprite->backward];
        } else {
            frame_index = p_sprite->p_frame_sequence[p_sprite->forward];
        }
    } else {
        if(p_sprite->loop_forward == FALSE) {
            frame_index = p_sprite->backward;
        } else {
            frame_index = p_sprite->forward;
        }
    }

//    if (&p_sprite->sp_img != NULL)
//    {
    if(p_sprite->layer.visible == TRUE) {
        if (p_sprite->total_frames == 0) {
            spImg.PaintRegion(
                spImg.GetBmpHandle(), hdc, (int)X, (int)Y,
                0, 0, Width, Height, frameRatio, frameRotate, frameAlpha
            );
        }
        else
        {
            spImg.PaintFrame(
                spImg.GetBmpHandle(), hdc, (int)X, (int)Y, frmIndex,
                frameCols, Width, Height, frameRatio, frameRotate, frameAlpha
            );
        }
    }
//    }
}

/* end of file */

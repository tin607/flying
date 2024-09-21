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


#ifndef __AWGE_LAYER_H
#define __AWGE_LAYER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

/**
 * \brief layer
 */
typedef struct {

    int    width, height;
    int    x, y;
    bool_t visible;
    int    layer_type_id;
    int    zorder;

    void (*draw) (void);

} awge_layer_t;

/**
 * \brief layer init
 */
aw_err_t awge_layer_init (awge_layer_t *p_layer);

/**
 * \brief set width
 */
static inline
void awge_layer_width_set (awge_layer_t *p_layer, int width)
{
    p_layer->width = width;
}

/**
 * \brief get width
 */
static inline
int awge_layer_width_get (awge_layer_t *p_layer)
{
    return p_layer->width;
}

/**
 * \brief set height
 */
static inline
void awge_layer_height_set (awge_layer_t *p_layer, int height)
{
    p_layer->height = height;
}

/**
 * \brief get heighi
 */
static inline
int awge_layer_height_get (awge_layer_t *p_layer)
{
    return p_layer->height;
}

/**
 * \brief set position
 */
static inline
void awge_layer_position_set (awge_layer_t *p_layer, int x, int y)
{
    p_layer->x = x;
    p_layer->y = y;
}

/**
 * \brief get x
 */
static inline
int awge_layer_x_get (awge_layer_t *p_layer)
{
    return p_layer->x;
}

/**
 * \brief get y
 */
static inline
int awge_layer_y_get (awge_layer_t *p_layer)
{
    return p_layer->y;
}

/**
 * \brief set visible
 */
static inline
void awge_layer_visible_set (awge_layer_t *p_layer, bool_t visible)
{
    p_layer->visible = visible;
}

/**
 * \brief visible?
 */
static inline
bool_t awge_layer_is_visible (awge_layer_t *p_layer)
{
    return p_layer->visible;
}

/**
 * \brief set layer type id
 */
static inline
void awge_layer_layer_type_id_set (awge_layer_t *p_layer, int i)
{
    p_layer->layer_type_id = i;
}

/**
 * \brief get layer type id
 */
static inline
int awge_layer_layer_type_id_get (awge_layer_t *p_layer)
{
    return p_layer->layer_type_id;
}

/**
 * \brief get zorder
 */
static inline
int awge_layer_zorder_get (awge_layer_t *p_layer)
{
    return p_layer->zorder;
}

/**
 * \brief set zorder
 */
static inline
void awge_layer_zorder_set (awge_layer_t *p_layer, int z)
{
    p_layer->zorder = z;
}

/**
 * \brief move
 */
static inline
void awge_layer_move (awge_layer_t *p_layer, int dx_speed, int dy_speed)
{
    p_layer->x += dx_speed;
    p_layer->y += dy_speed;
}

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_LAYER_H */

/* end of file */

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


#ifndef __AWGE_MAP_H
#define __AWGE_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

typedef struct {
    awge_layer_t layer;

    int    tile_width;
    int    tile_height;
    int    map_cols;
    int    map_rows;
    int    first_gid;
    bool_t updated;

    awge_graph_t *p_graph;

//    HDC dc_buf;
//    HBITMAP hbmp_old;
//    HBITMAP hbmp_layer;

    /** \brief ´æ´¢ÕûÐÍÖµ */
    awge_vector_t layer_data;
} awge_map_t;

/**
 * \brief map init
 */
aw_err_t awge_map_init (awge_map_t        *p_map,
                        awge_layer_info_t  layerInfo,
                        const char        *p_img_file_path);

/**
 * \brief get map tile width
 */
int awge_map_tile_width_get (awge_map_t *p_map)
{
    return p_map->tile_width;
}

/**
 * \brief get tile heigh
 */
int awge_map_tile_height_get (awge_map_t *p_map)
{
    return p_map->tile_height;
}

/**
 * \brief get map cols
 */
int awge_map_map_cols_get (awge_map_t *p_map)
{
    return p_map->map_cols;
}

/**
 * \brief get map rows
 */
int awge_map_map_rows_get (awge_map_t *p_map)
{
    return p_map->map_rows;
}

/**
 * \brief set update
 */
void awge_map_update_set (awge_map_t *p_map, bool_t updt)
{
    p_map->updated = updt;
}

/**
 * \brief get update
 */
bool_t awge_map_update_get (awge_map_t *p_map)
{
    return p_map->updated;
}

/**
 * \brief set tile
 */
void awge_map_tile_set (awge_map_t *p_map,
                        int         col,
                        int         row,
                        int         tile_index);

/**
 * \brief get tile
 */
int awge_map_tile_get (awge_map_t *p_map, int col, int row);

///**
// * \brief
// */
//void awge_map_redraw(hdc hdc);
//
///**
// * \brief
// */
//void awge_map_draw(hdc hdc);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_MAP_H */

/* end of file */

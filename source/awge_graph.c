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

aw_err_t awge_graph_init (awge_graph_t *p_graph, const char *p_path)
{
    return awge_graph_image_file_Load(p_graph, p_path);
}

/**
 * \brief load image file
 */
bool_t awge_graph_image_file_Load (awge_graph_t *p_graph, const char *p_path)
{

}

/* end of file */

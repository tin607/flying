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


#ifndef __AWGE_INTERNAL_H
#define __AWGE_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "aworks.h"
#include "aw_common.h"
#include "aw_mem.h"

#include "awge_engine.h"

/**
 * \brief 四舍五入
 */
#define AWGE_ROUND(x) (int)(x + 0.5)

/**
 * \brief 游戏方位
 */
enum awge_game_dir {
    AWGE_GAME_DIR_LEFT,
    AWGE_GAME_DIR_RIGHT,
    AWGE_GAME_DIR_UP,
    AWGE_GAME_DIR_DOWN,
    AWGE_GAME_DIR_LEFT_UP,
    AWGE_GAME_DIR_LEFT_DOWN,
    AWGE_GAME_DIR_RIGHT_UP,
    AWGE_GAME_DIR_RIGHT_DOWN
};

/**
 * \brief 旋转角度
 */
enum awge_game_transfer {
    AWGE_GAME_TRANS_NONE,
    AWGE_GAME_TRANS_NOFLIP_ROT90,
    AWGE_GAME_TRANS_NOFLIP_ROT180,
    AWGE_GAME_TRANS_NOFLIP_ROT270,
    AWGE_GAME_TRANS_VFLIP_NOROT,
    AWGE_GAME_TRANS_VFLIP_ROT90,
    AWGE_GAME_TRANS_VFLIP_ROT180,
    AWGE_GAME_TRANS_VFLIP_ROT270,
    AWGE_GAME_TRANS_HFLIP_NOROT,
    AWGE_GAME_TRANS_HFLIP_ROT90,
    AWGE_GAME_TRANS_HFLIP_ROT180,
    AWGE_GAME_TRANS_HFLIP_ROT270
};

/**
 * \brief 游戏状态
 */
enum awge_game_state {
    AWGE_GAME_START,
    AWGE_GAME_RUN,
    AWGE_GAME_PAUSE,
    AWGE_GAME_UPGRADE,
    AWGE_GAME_WIN,
    AWGE_GAME_OVER,
    AWGE_GAME_HELP,
    AWGE_GAME_ABOUT,
    AWGE_GAME_SETTING
};

/**
 * \brief 按键和鼠标动作
 */
enum awge_km_action {
    AWGE_KEY_SYS_NONE,
    AWGE_KEY_UP,
    AWGE_KEY_DOWN,
    AWGE_MOUSE_MOVE,
    AWGE_MOUSE_LCLICK,
    AWGE_MOUSE_RCLICK
};

/**
 * \brief 图层类型
 */
enum awge_layer_type {
    AWGE_LAYER_PLY,
    AWGE_LAYER_NPC,
    AWGE_LAYER_PLY_BOMB,
    AWGE_LAYER_NPC_BOMB,
    AWGE_LAYER_MAP_BACK,
    AWGE_LAYER_MAP_BARR,
    AWGE_LAYER_MAP_MASK,
    AWGE_LAYER_EXPLOSION,
    AWGE_LAYER_TARGET,
    AWGE_LAYER_BONUS,
    AWGE_LAYER_NONE
};

/**
 * \brief 精灵信息
 */
typedef struct {
    int                 x;
    int                 y;
    enum awge_game_dir  dir;
    int                 speed;
    int                 level;
    int                 score;
    bool_t              visible;
    bool_t              active;
    bool_t              dead;
    uint8_t             alpha;
    float               ratio;
    int                 rotation;
} awge_sprite_info_t;

/**
 * \brief 图层信息
 */
typedef struct {
    int         type_id;
    int         map_cols;
    int         map_rows;
    int         tile_width;
    int         tile_height;
    const char *p_tile_path;
    int         first_gid;
    int        *p_data;

    /** \brief 存放整型数 */
    awge_vector_t data;
} awge_layer_info_t;

/**
 * \brief 坐标信息
 */
typedef struct {
    double x;
    double y;
} awge_point_t;

/**
 * \brief 菜单项
 */
typedef struct {
    awge_point_t  pos;
    const char   *p_item_name;
} awge_menu_item_t;

/**
 * \brief rgb颜色
 */
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t alpha;
} awge_color_t;

/**
 * \brief 菜单信息
 */
typedef struct {
    int           width;
    int           height;
    int           space;
    int           align;
    const char   *p_font_name;
    bool_t        is_bold;
    awge_color_t  normal_text_color;
    awge_color_t  focus_text_color;
} awge_menu_info_t;

/**
 * \brief the width and height of a rectangle.
 */
typedef struct {
    int32_t cx;
    int32_t cy;
} awge_size_t;

/**
 * \brief HDC
 */
typedef void *awge_hdc_t;

#include "awge_ai.h"
#include "awge_audio.h"
#include "awge_debug.h"
#include "awge_display.h"
#include "awge_graph.h"
#include "awge_layer.h"
#include "awge_map.h"
#include "awge_menu.h"
#include "awge_scene.h"
#include "awge_sprite.h"
#include "awge_gui.h"
#include "awge_fs.h"

#include "utils/awge_vector.h"

/*******************************************************************************
 * 标准C库
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_INTERNAL_H */

/* end of file */

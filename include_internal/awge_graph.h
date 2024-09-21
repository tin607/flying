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


#ifndef __AWGE_GRAPH_H
#define __AWGE_GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

/**
 * \brief bitmap
 */
typedef struct awge_bitmap {
    uint32_t  bm_tpye;
    uint32_t  bm_width;
    uint32_t  bm_height;
    uint32_t  bm_width_bytes;
    uint32_t  bm_planes;
    uint32_t  bm_bits_pixel;
    void     *p_bits;
} awge_bitmap_t;

/**
 * \brief graph
 */
typedef struct {

    //HBITMAP hBmp;
    int image_width;
    int image_height;

} awge_graph_t;

/**
 * \brief graph init
 */
aw_err_t awge_graph_init (awge_graph_t *p_graph, const char *p_path);

//HBITMAP GetBmpHandle(){ return hBmp; }

/**
 * \brief get image width
 */
static inline
int awge_graph_image_width_get (awge_graph_t *p_graph)
{
    return p_graph->image_width;
}

/**
 * \brief get image height
 */
static inline
int awge_graph_image_height_get (awge_graph_t *p_graph)
{
    return p_graph->image_height;
}

/**
 * \brief load image file
 */
bool_t awge_graph_image_file_Load (awge_graph_t *p_graph, const char *p_path);

/**
 * \brief image paint
 */
void awge_graph_image_paint (awge_graph_t *p_graph,
                             int           x,
                             int           y,
                             int           width,
                             int           height,
                             uint8_t       alpha);

/**
 * \brief destroy
 */
void awge_graph_destroy (awge_graph_t *p_graph);

//static HBITMAP CreateBlankBitmap(int width, int height, COLORREF color);
//static Bitmap* HBITMAP_To_Bitmap(HBITMAP hbmp, HDC hdc);
//static void PaintRegion(HBITMAP in_hbitmap, HDC destDC, int destX, int destY,
//                        int srcX, int srcY, int regionWidth, int regionHeight,
//                        float ratio, int rotType=0, BYTE alpha=255);
//static void PaintFrame(HBITMAP in_hbitmap, HDC destDC, int destX, int destY,
//                       int FrameCount, int RowFrames, int wFrame, int hFrame,
//                       float ratio=1, int rotType=0, BYTE alpha=255);
//static void PaintBlank(HBITMAP hbmp, int width, int height, COLORREF crColor);
//static void PaintBlank(HDC hdc, int x, int y,
//                       int width, int height, Color crColor);
//static void PaintBlank(HDC hdc, int x, int y, int width, int height,
//                       COLORREF crColor, int alpLevel);
//static void PaintText(HDC hdc, RectF fontRect, LPCTSTR text,
//                      REAL fontSize, LPCTSTR fontName,
//                      Color fontColor = Color::White,
//                      FontStyle style = FontStyleBold,
//                      StringAlignment align = StringAlignmentCenter);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_GRAPH_H */

/* end of file */

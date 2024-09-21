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


#ifndef __AWGE_MENU_H
#define __AWGE_MENU_H

#ifdef __cplusplus
extern "C" {
#endif

struct awge_menu {
    awge_menu_info_t menu_info;

    int    m_index;
    bool_t is_item_focused;
    int    last_index;
    int    key_index;
    int    max_menu_item_len;
    int    bk_image_alpha;
    int    bk_color;

    AudioDXBuffer* m_MoveSound;
    AudioDXBuffer* m_ClickSound;
    T_Graph gm_menuBkg;
    T_Graph BtnDIB;
    vector<MENUITEM> gm_menuItems;

    int GetMenuIndex(int x, int y);
    StringAlignment GetAlignment();
    FontStyle GetFontStyle();

};

aw_err_t awge_menu_init (struct awge_menu *p_menu);
void awge_menu_deinit (struct awge_menu *p_menu);

void SetMenuBkg(LPCTSTR img_path, int alphaLevel=255, COLORREF backColor=RGB(0,0,0));
void SetBtnBmp(LPCTSTR img_path, int btnWidth, int btnHeight);
void SetMenuInfo(MENU_INFO menuInfo);
void AddMenuItem(MENUITEM menuItem);
void SetMoveSound(AudioDXBuffer* ms_buffer);
void SetClickSound(AudioDXBuffer* mc_buffer);
void DrawMenu(HDC hdc, int bkgX = 0, int bkgY = 0, BYTE btnTrans=255, bool startState=true);
int MenuMouseClick(int x, int y);
void MenuMouseMove(int x, int y);
int MenuKeyDown(WPARAM key);

int GetMenuIndex(){ return m_index; }
void SetMenuIndex(int i){ m_index = i; }
void DestroyAll();

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_MENU_H */

/* end of file */

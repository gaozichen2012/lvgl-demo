#include "../lv_tp79p.h"
#include "lv_startup.h"

#include "lv_desktop.h"
#include "lv_menu.h"
#include "lv_setting.h"
#include "lv_blight.h"

lv_obj_t *desktop_src;
lv_obj_t *menu_src;
lv_obj_t *menu_net_src;

static lv_style_t style_box;

void page_refresh(PAGE_ID page)
{
    //登录时未刷新，下周来先来排查，怀疑是成员好友数据变了，lvgl未检测到
    switch (page)
    {
    case PAGE_DESKTOP:
        lv_event_send_refresh_recursive(all_src.desktop_src);
        break;
    case PAGE_MENU:
        lv_event_send_refresh_recursive(all_src.menu_src);
        break;
    case PAGE_SETING:
        lv_event_send_refresh_recursive(all_src.setting_src);
        break;
    case PAGE_BLIGHT:
        lv_event_send_refresh_recursive(all_src.blight_src);
        break;
    default:
        break;
    }
}

void page_switch(PAGE_ID page)
{
    lv_obj_clean(all_src.desktop_src);
    lv_obj_clean(all_src.menu_src);
    lv_obj_clean(all_src.setting_src);
    lv_obj_clean(all_src.blight_src);

    switch (page)
    {
    case PAGE_DESKTOP:
        lv_desktop(all_src.desktop_src);
        lv_scr_load(all_src.desktop_src);
        break;
    case PAGE_MENU:
        lv_menu(all_src.menu_src);
        lv_scr_load(all_src.menu_src);
        break;
    case PAGE_SETING:
        lv_setting(all_src.setting_src);
        lv_scr_load(all_src.setting_src);
        break;
    case PAGE_BLIGHT:
        lv_blight(all_src.blight_src);
        lv_scr_load(all_src.blight_src);
        break;
        break;
    default:
        break;
    }
}

void lv_startup(void)
{
    all_src.desktop_src = lv_obj_create(NULL, NULL);
    all_src.menu_src = lv_obj_create(NULL, NULL);
    all_src.setting_src = lv_obj_create(NULL, NULL);
    all_src.blight_src = lv_obj_create(NULL, NULL);

#if 1 //测试修改字体无效
    lv_style_init(&style_box);

    lv_obj_add_style(all_src.desktop_src, LV_OBJ_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.menu_src, LV_OBJ_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.setting_src, LV_OBJ_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.blight_src, LV_OBJ_PART_MAIN, &style_box);

    lv_obj_add_style(all_src.desktop_src, LV_BTN_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.menu_src, LV_BTN_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.setting_src, LV_BTN_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.blight_src, LV_BTN_PART_MAIN, &style_box);
#endif

    page_switch(PAGE_DESKTOP);
}

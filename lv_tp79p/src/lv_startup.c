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
#if 0 //测试style函数
    lv_style_init(&style_box);

    lv_style_init(&style_pad);
    lv_style_set_pad_top(&style_pad, LV_STATE_DEFAULT, LV_VER_RES / 30);
    lv_style_set_pad_bottom(&style_pad, LV_STATE_DEFAULT, LV_VER_RES / 30);
    lv_style_set_pad_left(&style_pad, LV_STATE_DEFAULT, LV_VER_RES / 40);
    lv_style_set_pad_right(&style_pad, LV_STATE_DEFAULT, LV_VER_RES / 40);

    lv_style_init(&style_circle);
    lv_style_set_radius(&style_circle, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);

    lv_style_init(&style_bg);
    lv_style_set_bg_opa(&style_bg, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_bg, LV_STATE_DEFAULT, LV_DEMO_PRINTER_LIGHT);
    lv_style_set_text_font(&style_bg, LV_STATE_DEFAULT, theme.font_normal);

    lv_style_init(&style_box);
    lv_style_set_bg_opa(&style_box, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_radius(&style_box, LV_STATE_DEFAULT, 10);
    lv_style_set_value_color(&style_box, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);
    lv_style_set_value_font(&style_box, LV_STATE_DEFAULT, theme.font_normal);

    lv_style_init(&style_box_border);
    lv_style_set_bg_opa(&style_box_border, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_style_set_border_width(&style_box_border, LV_STATE_DEFAULT, 2);
    lv_style_set_border_color(&style_box_border, LV_STATE_DEFAULT, LV_DEMO_PRINTER_GRAY);
    lv_style_set_text_color(&style_box, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);

    lv_style_init(&style_title);
    lv_style_set_text_color(&style_title, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_text_font(&style_title, LV_STATE_DEFAULT, theme.font_subtitle);

    lv_style_init(&style_label_white);
    lv_style_set_text_color(&style_label_white, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);

    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, LV_STATE_DEFAULT, 10);
    lv_style_set_bg_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);
    lv_style_set_bg_color(&style_btn, LV_STATE_PRESSED, lv_color_darken(LV_DEMO_PRINTER_BLUE, LV_OPA_20));
    lv_style_set_text_color(&style_btn, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_value_color(&style_btn, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_pad_top(&style_btn, LV_STATE_DEFAULT, LV_VER_RES / 40);
    lv_style_set_pad_bottom(&style_btn, LV_STATE_DEFAULT, LV_VER_RES / 40);

    lv_style_set_transform_width(&style_btn, LV_STATE_PRESSED, LV_HOR_RES / 100);
    lv_style_set_transform_height(&style_btn, LV_STATE_PRESSED, LV_HOR_RES / 150);
    lv_style_set_transition_time(&style_btn, LV_STATE_DEFAULT, 100);
    lv_style_set_transition_delay(&style_btn, LV_STATE_PRESSED, 0);
    lv_style_set_transition_delay(&style_btn, LV_STATE_DEFAULT, 70);
    lv_style_set_transition_prop_1(&style_btn, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_WIDTH);
    lv_style_set_transition_prop_2(&style_btn, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_HEIGHT);

    lv_style_init(&style_btn_border);
    lv_style_set_radius(&style_btn_border, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_border_color(&style_btn_border, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_border_width(&style_btn_border, LV_STATE_DEFAULT, 2);
    lv_style_set_bg_opa(&style_btn_border, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_style_set_bg_opa(&style_btn_border, LV_STATE_PRESSED, LV_OPA_30);
    lv_style_set_bg_color(&style_btn_border, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_bg_color(&style_btn_border, LV_STATE_PRESSED, LV_DEMO_PRINTER_WHITE);
    lv_style_set_text_color(&style_btn_border, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_value_color(&style_btn_border, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_transition_prop_3(&style_btn_border, LV_STATE_DEFAULT, LV_STYLE_BG_OPA);

    lv_style_init(&style_icon);
    lv_style_set_text_color(&style_icon, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_transform_zoom(&style_icon, LV_STATE_PRESSED, 245);
    lv_style_set_transition_time(&style_icon, LV_STATE_DEFAULT, 100);
    lv_style_set_transition_delay(&style_icon, LV_STATE_PRESSED, 0);
    lv_style_set_transition_delay(&style_icon, LV_STATE_DEFAULT, 70);
    lv_style_set_transition_prop_1(&style_icon, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_ZOOM);

    lv_style_init(&style_back);
    lv_style_set_value_color(&style_back, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_value_color(&style_back, LV_STATE_PRESSED, LV_DEMO_PRINTER_LIGHT_GRAY);
    lv_style_set_value_str(&style_back, LV_STATE_DEFAULT, LV_SYMBOL_LEFT);
    lv_style_set_value_font(&style_back, LV_STATE_DEFAULT, theme.font_subtitle);

    lv_style_init(&style_bar_indic);
    lv_style_set_bg_opa(&style_bar_indic, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_radius(&style_bar_indic, LV_STATE_DEFAULT, 10);

    lv_style_init(&style_scrollbar);
    lv_style_set_bg_opa(&style_scrollbar, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_radius(&style_scrollbar, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_bg_color(&style_scrollbar, LV_STATE_DEFAULT, LV_DEMO_PRINTER_LIGHT_GRAY);
    lv_style_set_size(&style_scrollbar, LV_STATE_DEFAULT, LV_HOR_RES / 80);
    lv_style_set_pad_right(&style_scrollbar, LV_STATE_DEFAULT, LV_HOR_RES / 60);

    lv_style_init(&style_list_btn);
    lv_style_set_bg_opa(&style_list_btn, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_list_btn, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_bg_color(&style_list_btn, LV_STATE_PRESSED, LV_DEMO_PRINTER_LIGHT_GRAY);
    lv_style_set_bg_color(&style_list_btn, LV_STATE_CHECKED, LV_DEMO_PRINTER_GRAY);
    lv_style_set_bg_color(&style_list_btn, LV_STATE_CHECKED | LV_STATE_PRESSED, lv_color_darken(LV_DEMO_PRINTER_GRAY, LV_OPA_20));
    lv_style_set_text_color(&style_list_btn, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);
    lv_style_set_text_color(&style_list_btn, LV_STATE_PRESSED, lv_color_darken(LV_DEMO_PRINTER_BLUE, LV_OPA_20));
    lv_style_set_text_color(&style_list_btn, LV_STATE_CHECKED, LV_DEMO_PRINTER_WHITE);
    lv_style_set_text_color(&style_list_btn, LV_STATE_CHECKED | LV_STATE_PRESSED, LV_DEMO_PRINTER_WHITE);
    lv_style_set_image_recolor(&style_list_btn, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);
    lv_style_set_image_recolor(&style_list_btn, LV_STATE_PRESSED, lv_color_darken(LV_DEMO_PRINTER_BLUE, LV_OPA_20));
    lv_style_set_image_recolor(&style_list_btn, LV_STATE_CHECKED, LV_DEMO_PRINTER_WHITE);
    lv_style_set_image_recolor(&style_list_btn, LV_STATE_CHECKED | LV_STATE_PRESSED, LV_DEMO_PRINTER_WHITE);
    lv_style_set_pad_left(&style_list_btn, LV_STATE_DEFAULT, LV_HOR_RES / 25);
    lv_style_set_pad_right(&style_list_btn, LV_STATE_DEFAULT, LV_HOR_RES / 25);
    lv_style_set_pad_top(&style_list_btn, LV_STATE_DEFAULT, LV_HOR_RES / 100);
    lv_style_set_pad_bottom(&style_list_btn, LV_STATE_DEFAULT, LV_HOR_RES / 100);
    lv_style_set_pad_inner(&style_list_btn, LV_STATE_DEFAULT, LV_HOR_RES / 50);

    lv_style_init(&style_ddlist_list);
    lv_style_set_text_line_space(&style_ddlist_list, LV_STATE_DEFAULT, LV_VER_RES / 25);
    lv_style_set_shadow_width(&style_ddlist_list, LV_STATE_DEFAULT, LV_VER_RES / 20);
    lv_style_set_shadow_color(&style_ddlist_list, LV_STATE_DEFAULT, LV_DEMO_PRINTER_GRAY);

    lv_style_init(&style_ddlist_selected);
    lv_style_set_bg_opa(&style_ddlist_selected, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_ddlist_selected, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);
    lv_style_set_bg_color(&style_ddlist_selected, LV_STATE_PRESSED, LV_DEMO_PRINTER_LIGHT_GRAY);
    lv_style_set_text_color(&style_ddlist_selected, LV_STATE_PRESSED, lv_color_darken(LV_DEMO_PRINTER_GRAY, LV_OPA_20));

    lv_style_init(&style_sw_bg);
    lv_style_set_bg_opa(&style_sw_bg, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_sw_bg, LV_STATE_DEFAULT, LV_DEMO_PRINTER_LIGHT_GRAY);
    lv_style_set_radius(&style_sw_bg, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_value_color(&style_sw_bg, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);

    lv_style_init(&style_sw_indic);
    lv_style_set_bg_opa(&style_sw_indic, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_sw_indic, LV_STATE_DEFAULT, LV_DEMO_PRINTER_GREEN);

    lv_style_init(&style_sw_knob);
    lv_style_set_bg_opa(&style_sw_knob, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_sw_knob, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_radius(&style_sw_knob, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_pad_top(&style_sw_knob, LV_STATE_DEFAULT, -4);
    lv_style_set_pad_bottom(&style_sw_knob, LV_STATE_DEFAULT, -4);
    lv_style_set_pad_left(&style_sw_knob, LV_STATE_DEFAULT, -4);
    lv_style_set_pad_right(&style_sw_knob, LV_STATE_DEFAULT, -4);

    lv_style_init(&style_slider_knob);
    lv_style_set_bg_opa(&style_slider_knob, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_slider_knob, LV_STATE_DEFAULT, LV_DEMO_PRINTER_BLUE);
    lv_style_set_border_color(&style_slider_knob, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_border_width(&style_slider_knob, LV_STATE_DEFAULT, 3);
    lv_style_set_radius(&style_slider_knob, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_pad_top(&style_slider_knob, LV_STATE_DEFAULT, 10);
    lv_style_set_pad_bottom(&style_slider_knob, LV_STATE_DEFAULT, 10);
    lv_style_set_pad_left(&style_slider_knob, LV_STATE_DEFAULT, 10);
    lv_style_set_pad_right(&style_slider_knob, LV_STATE_DEFAULT, 10);
    lv_style_set_pad_top(&style_slider_knob, LV_STATE_PRESSED, 14);
    lv_style_set_pad_bottom(&style_slider_knob, LV_STATE_PRESSED, 14);
    lv_style_set_pad_left(&style_slider_knob, LV_STATE_PRESSED, 14);
    lv_style_set_pad_right(&style_slider_knob, LV_STATE_PRESSED, 14);
    lv_style_set_transition_time(&style_slider_knob, LV_STATE_DEFAULT, 150);
    lv_style_set_transition_delay(&style_slider_knob, LV_STATE_PRESSED, 0);
    lv_style_set_transition_delay(&style_slider_knob, LV_STATE_DEFAULT, 70);
    lv_style_set_transition_prop_1(&style_slider_knob, LV_STATE_DEFAULT, LV_STYLE_PAD_BOTTOM);
    lv_style_set_transition_prop_2(&style_slider_knob, LV_STATE_DEFAULT, LV_STYLE_PAD_TOP);
    lv_style_set_transition_prop_3(&style_slider_knob, LV_STATE_DEFAULT, LV_STYLE_PAD_LEFT);
    lv_style_set_transition_prop_4(&style_slider_knob, LV_STATE_DEFAULT, LV_STYLE_PAD_RIGHT);

    lv_style_init(&style_arc_indic);
    lv_style_set_line_width(&style_arc_indic, LV_STATE_DEFAULT, 5);
    lv_style_set_line_color(&style_arc_indic, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);

    lv_style_init(&style_arc_bg);
    lv_style_set_value_color(&style_arc_bg, LV_STATE_DEFAULT, LV_DEMO_PRINTER_WHITE);
    lv_style_set_value_font(&style_arc_bg, LV_STATE_DEFAULT, theme.font_title);
    lv_style_init(&style_scrollbar);
    lv_style_set_size(&style_scrollbar, LV_STATE_DEFAULT, 4);
    lv_style_set_bg_opa(&style_scrollbar, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_scrollbar, LV_STATE_DEFAULT, lv_color_hex3(0xeee));
    lv_style_set_radius(&style_scrollbar, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_style_set_pad_right(&style_scrollbar, LV_STATE_DEFAULT, 4);

    lv_style_init(&style_btn);
    lv_style_set_bg_opa(&style_btn, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_style_set_bg_opa(&style_btn, LV_STATE_PRESSED, LV_OPA_COVER);
    lv_style_set_bg_opa(&style_btn, LV_STATE_CHECKED, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, LV_STATE_PRESSED, lv_color_hex(0x4c4965));
    lv_style_set_bg_color(&style_btn, LV_STATE_CHECKED, lv_color_hex(0x4c4965));
    lv_style_set_text_opa(&style_btn, LV_STATE_DISABLED, LV_OPA_40);
    lv_style_set_image_opa(&style_btn, LV_STATE_DISABLED, LV_OPA_40);

    lv_style_init(&style_title);
    lv_style_set_text_font(&style_title, LV_STATE_DEFAULT, &lv_font_montserrat_12);
    lv_style_set_text_color(&style_title, LV_STATE_DEFAULT, lv_color_hex(0xffffff));

    lv_style_init(&style_artist);
    lv_style_set_text_font(&style_artist, LV_STATE_DEFAULT, &lv_font_montserrat_10);
    lv_style_set_text_color(&style_artist, LV_STATE_DEFAULT, lv_color_hex(0xb1b0be));

    lv_style_init(&style_time);
    lv_style_set_text_font(&style_time, LV_STATE_DEFAULT, &lv_font_montserrat_10);
    lv_style_set_text_color(&style_time, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
    lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&style1, LV_STATE_PRESSED, LV_COLOR_GRAY);
    lv_style_set_bg_color(&style1, LV_STATE_FOCUSED, LV_COLOR_RED);
    lv_style_set_bg_color(&style1, LV_STATE_FOCUSED | LV_STATE_PRESSED, lv_color_hex(0xf88));

#endif
    lv_obj_add_style(all_src.desktop_src, LV_OBJ_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.menu_src, LV_OBJ_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.setting_src, LV_OBJ_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.blight_src, LV_OBJ_PART_MAIN, &style_box);

    lv_obj_add_style(all_src.desktop_src, LV_BTN_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.menu_src, LV_BTN_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.setting_src, LV_BTN_PART_MAIN, &style_box);
    lv_obj_add_style(all_src.blight_src, LV_BTN_PART_MAIN, &style_box);
#endif

    page_switch(PAGE_MENU);
}

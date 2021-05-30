#include "../lv_tp79p.h"
#include "lv_setting.h"

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);
LV_IMG_DECLARE(group_80x80);

static lv_group_t *g;
lv_obj_t *setting_list;

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    switch (event)
    {
    case LV_EVENT_CLICKED: //LV_KEY_ENTER
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));

        if (strcmp(lv_list_get_btn_text(obj), "group select") == 0)
        {
            page_switch(PAGE_MENU);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "member select") == 0)
        {
            page_switch(PAGE_BLIGHT);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "GPS") == 0)
        {
            page_switch(PAGE_BLIGHT);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "record") == 0)
        {
            page_switch(PAGE_BLIGHT);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "POC settings") == 0)
        {
            page_switch(PAGE_BLIGHT);
        }
        else
        {
            page_switch(PAGE_BLIGHT);
        }

        break;
    case LV_EVENT_CANCEL: //LV_KEY_ESC
        page_switch(PAGE_MENU);
        break;

    default:
        break;
    }
}

#ifndef EC20
static void sim_event_ok_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_event_send(setting_list, LV_EVENT_CLICKED, NULL);
    }
}

static void sim_event_back_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_event_send(setting_list, LV_EVENT_CANCEL, NULL);
    }
}
#endif

static void bottom_bar(lv_obj_t *parent)
{
#ifndef EC20
    lv_obj_t *btn;
    lv_obj_t *label;

    btn = lv_btn_create(parent, NULL);
    lv_obj_set_event_cb(btn, sim_event_ok_handler);
    lv_obj_set_size(btn, 40, 20);
    lv_obj_align(btn, parent, LV_ALIGN_IN_BOTTOM_LEFT, 5, -2);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    label = lv_label_create(btn, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_12);
    lv_label_set_text(label, "确认");

    btn = lv_btn_create(parent, NULL);
    lv_obj_set_event_cb(btn, sim_event_back_handler);
    lv_obj_set_size(btn, 40, 20);
    lv_obj_align(btn, parent, LV_ALIGN_IN_BOTTOM_RIGHT, -5, -2);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    label = lv_label_create(btn, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_12);
    lv_label_set_text(label, "返回");
#else
    static lv_style_t style1;
    lv_obj_t *cont;
    lv_obj_t *label;

    lv_style_init(&style1);
    lv_style_set_text_font(&style1, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_12);
    lv_style_set_text_color(&style1, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
    lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, lv_color_hex(0xf88));

    cont = lv_cont_create(parent, NULL);
    lv_obj_add_style(cont, LV_OBJ_PART_MAIN, &style1);
    lv_obj_set_size(cont, 160 - 4, 20);
    lv_obj_align(cont, parent, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

    label = lv_label_create(cont, NULL);
    lv_obj_align(label, cont, LV_ALIGN_IN_LEFT_MID, 5, 0);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_12);
    lv_label_set_text(label, "确认");

    label = lv_label_create(cont, NULL);
    lv_obj_align(label, cont, LV_ALIGN_IN_RIGHT_MID, -5, 0);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_12);
    lv_label_set_text(label, "返回");
#endif
}

void lv_setting(lv_obj_t *parent)
{
    setting_list = lv_list_create(parent, NULL);
    lv_obj_set_event_cb(setting_list, event_handler); //此句可能会对实际运行有影响

    lv_obj_set_size(setting_list, 160, 128 - 20);
    lv_obj_align(setting_list, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t *list_btn;

    list_btn = lv_list_add_btn(setting_list, LV_SYMBOL_CLOSE, "group select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(setting_list, LV_SYMBOL_CLOSE, "member select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(setting_list, LV_SYMBOL_CLOSE, "friend select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(setting_list, LV_SYMBOL_GPS, "GPS");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(setting_list, LV_SYMBOL_BELL, "record");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(setting_list, LV_SYMBOL_SETTINGS, "POC settings");
    lv_obj_set_event_cb(list_btn, event_handler);

    bottom_bar(parent);

    g = lv_group_create();
    lv_group_add_obj(g, setting_list);
#ifdef EC20
    lv_indev_set_group(indev_keypad, g);
#endif
}

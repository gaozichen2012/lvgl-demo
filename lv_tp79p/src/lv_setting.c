#include "../lv_tp79p.h"
#include "lv_setting.h"

#include "lvgl_indev.h"

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);
LV_IMG_DECLARE(group_80x80);

static lv_group_t *g;

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    switch (event)
    {
    case LV_EVENT_CLICKED: //LV_KEY_ENTER
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));

        if (strcmp(lv_list_get_btn_text(obj), "group select") == 0)
        {
            page_switch(PAGE_BLIGHT);
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
            page_switch(PAGE_MENU);
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

static lv_obj_t *bottom_bar(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;
    lv_obj_t *btn;

    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    btn = lv_btn_create(cont, NULL);
    lv_obj_set_event_cb(btn, event_handler);
    lv_obj_set_size(btn, 32, 16);
    lv_obj_align(btn, cont, LV_ALIGN_IN_LEFT_MID, 0, 0);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Enter");

    btn = lv_btn_create(cont, NULL);
    lv_obj_set_event_cb(btn, event_handler);
    lv_obj_set_size(btn, 32, 16);
    lv_obj_align(btn, cont, LV_ALIGN_IN_RIGHT_MID, 0, 0);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Back");

    return cont;
}

void lv_setting(lv_obj_t *parent)
{
    lv_obj_t *list1 = lv_list_create(parent, NULL);
    //lv_list_set_anim_time(list1, 100);
    //lv_list_set_layout(list1, LV_LAYOUT_ROW_MID);//水平滚动的列表
    lv_obj_set_size(list1, 160, 128 - 16);
    lv_obj_align(list1, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t *list_btn;

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "group select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "member select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "friend select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "GPS");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BELL, "record");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_SETTINGS, "POC settings");
    lv_obj_set_event_cb(list_btn, event_handler);

    bottom_bar(parent, list1);

    g = lv_group_create();
    lv_group_add_obj(g, list1);
    lv_indev_set_group(indev_keypad, g);
}

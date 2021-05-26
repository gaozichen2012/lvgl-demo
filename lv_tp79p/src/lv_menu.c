#include "../lv_tp79p.h"
#include "lv_menu.h"

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);
LV_IMG_DECLARE(group_80x80);

static lv_group_t *g;
lv_obj_t *menu_list;

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    switch (event)
    {
    case LV_EVENT_CLICKED: //LV_KEY_ENTER
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));

        if (strcmp(lv_list_get_btn_text(obj), "group select") == 0)
        {
            page_switch(PAGE_SETING);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "member select") == 0)
        {
            page_switch(PAGE_SETING);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "GPS") == 0)
        {
            page_switch(PAGE_SETING);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "record") == 0)
        {
            page_switch(PAGE_SETING);
        }
        else if (strcmp(lv_list_get_btn_text(obj), "POC settings") == 0)
        {
            page_switch(PAGE_SETING);
        }
        else
        {
            page_switch(PAGE_SETING);
        }

        break;
    case LV_EVENT_CANCEL: //LV_KEY_ESC
        page_switch(PAGE_DESKTOP);
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
        lv_event_send(menu_list, LV_EVENT_CLICKED, NULL);
    }
}

static void sim_event_back_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_event_send(menu_list, LV_EVENT_CANCEL, NULL);
    }
}
#endif

static void bottom_bar(lv_obj_t *parent)
{
    lv_obj_t *btn;

    btn = lv_btn_create(parent, NULL);
#ifndef EC20
    lv_obj_set_event_cb(btn, sim_event_ok_handler);
#endif
    lv_obj_set_size(btn, 40, 20);
    lv_obj_align(btn, parent, LV_ALIGN_IN_BOTTOM_LEFT, 5, -5);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Enter");

    btn = lv_btn_create(parent, NULL);
#ifndef EC20
    lv_obj_set_event_cb(btn, sim_event_back_handler);
#endif
    lv_obj_set_size(btn, 40, 20);
    lv_obj_align(btn, parent, LV_ALIGN_IN_BOTTOM_RIGHT, -5, -5);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Back");
}

void lv_menu(lv_obj_t *parent)
{
    lv_obj_t *menu_cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(menu_cont, 160, 128);

    menu_list = lv_list_create(menu_cont, NULL);
    lv_obj_set_event_cb(menu_list, event_handler); //此句可能会对实际运行有影响
    //lv_list_set_anim_time(menu_list, 50);
    lv_list_set_layout(menu_list, LV_LAYOUT_ROW_MID); //水平滚动的列表
    lv_obj_set_size(menu_list, 160, 128 - 50);
    lv_obj_align(menu_list, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t *list_btn;

    list_btn = lv_list_add_btn(menu_list, &group_80x80, "group select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(menu_list, &group_80x80, "member select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(menu_list, &group_80x80, "friend select");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(menu_list, &group_80x80, "GPS");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(menu_list, &group_80x80, "record");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(menu_list, &group_80x80, "POC settings");
    lv_obj_set_event_cb(list_btn, event_handler);

    bottom_bar(menu_cont);

    g = lv_group_create();
    lv_group_add_obj(g, menu_list);
#ifdef EC20
    lv_indev_set_group(indev_keypad, g);
#endif
}

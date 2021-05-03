#include "../lv_tp79p.h"
#include "lv_menu.h"

static void list_event_handler(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
    }
}

void lv_menu(lv_obj_t *parent)
{
#if 1
    /*Create a list*/
    lv_obj_t *list1 = lv_list_create(parent, NULL);
    lv_obj_set_size(list1, 160, 128 - 16);
    lv_obj_align(list1, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t *list_btn;

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_VIDEO, "Anglog settings");
    lv_obj_set_event_cb(list_btn, list_event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_HOME, "Poc settings");
    lv_obj_set_event_cb(list_btn, list_event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "Mode Switch");
    lv_obj_set_event_cb(list_btn, list_event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_SETTINGS, "General settings");
    lv_obj_set_event_cb(list_btn, list_event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_SAVE, "Save");
    lv_obj_set_event_cb(list_btn, list_event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BELL, "Notify");
    lv_obj_set_event_cb(list_btn, list_event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BATTERY_FULL, "Battery");
    lv_obj_set_event_cb(list_btn, list_event_handler);
#else
    lv_obj_t *cont;

    //创建一个容器对象
    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128);

    lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");

#endif
}

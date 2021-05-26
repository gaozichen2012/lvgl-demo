#include "../lv_tp79p.h"
#include "lv_blight.h"

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);

static lv_group_t *g;

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    switch (event)
    {
    case LV_EVENT_CLICKED: //LV_KEY_ENTER
        break;
    case LV_EVENT_CANCEL: //LV_KEY_ESC
        page_switch(PAGE_SETING);
        break;

    default:
        break;
    }
}

static lv_obj_t *central_area(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128 - 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_IN_TOP_MID, 0, 0);

    lv_obj_t *label1 = lv_label_create(cont, NULL);
    lv_label_set_text(label1, "backlight"); //
    lv_obj_align(label1, cont, LV_ALIGN_IN_TOP_MID, 0, 5);

    lv_obj_t *sw = lv_switch_create(cont, NULL);
    lv_switch_set_anim_time(sw, 50);
    lv_obj_align(sw, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(sw, event_handler);

    g = lv_group_create();
    lv_group_add_obj(g, sw);
#ifdef EC20
    lv_indev_set_group(indev_keypad, g);
#endif
    return cont;
}

static lv_obj_t *bottom_bar(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;
    lv_obj_t *btn;
    lv_obj_t *label;

    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

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

void lv_blight(lv_obj_t *parent)
{
    lv_obj_t *cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128);

    lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");
    lv_obj_t *cont_1 = central_area(cont, cont);
    lv_obj_t *cont_2 = bottom_bar(cont, cont_1);
}

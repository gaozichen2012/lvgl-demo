#include "../lv_tp79p.h"
#include "lv_blight.h"

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);

static lv_group_t *g;
lv_obj_t *sw;

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

#ifndef EC20
static void sim_event_back_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_event_send(sw, LV_EVENT_CANCEL, NULL);
    }
}
#endif

static void bottom_bar(lv_obj_t *parent)
{
#ifndef EC20
    lv_obj_t *btn;
    lv_obj_t *label;

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
    lv_obj_align(label, cont, LV_ALIGN_IN_RIGHT_MID, -5, 0);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_12);
    lv_label_set_text(label, "返回");
#endif
}

static void central_area(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128);
    lv_obj_align(cont, obj_ref, LV_ALIGN_IN_TOP_MID, 0, 0);

    lv_obj_t *label1 = lv_label_create(cont, NULL);
    lv_label_set_text(label1, "backlight"); //
    lv_obj_align(label1, cont, LV_ALIGN_IN_TOP_MID, 0, 5);

    sw = lv_switch_create(cont, NULL);
    lv_switch_set_anim_time(sw, 50);
    lv_obj_align(sw, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(sw, event_handler);

    g = lv_group_create();
    lv_group_add_obj(g, sw);
#ifdef EC20
    lv_indev_set_group(indev_keypad, g);
#endif

    bottom_bar(cont);
}

void lv_blight(lv_obj_t *parent)
{
    lv_obj_t *cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128);

    lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");
    central_area(cont, cont);
}

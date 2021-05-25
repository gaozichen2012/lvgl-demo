#include "../lv_tp79p.h"
#include "lv_desktop.h"

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);

static lv_obj_t *cont;

lv_obj_t *net_notification_bar(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;

    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_IN_TOP_MID, 0, 0);
    //lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT,LV_SYMBOL_DOWNLOAD  LV_SYMBOL_HOME  LV_SYMBOL_SETTINGS  LV_SYMBOL_POWER  LV_SYMBOL_CLOSE LV_SYMBOL_OK LV_SYMBOL_LIST LV_SYMBOL_AUDIO LV_SYMBOL_VIDEO LV_SYMBOL_PLUS );

    lv_obj_t *img1 = lv_img_create(cont, NULL);
    lv_img_set_src(img1, LV_SYMBOL_SD_CARD);
    lv_obj_align(img1, cont, LV_ALIGN_IN_TOP_LEFT, 5, 0);

    lv_obj_t *img2 = lv_img_create(cont, NULL);
    lv_img_set_src(img2, LV_SYMBOL_REFRESH);
    lv_obj_align(img2, img1, LV_ALIGN_OUT_RIGHT_MID, 8, 0);

    lv_obj_t *img3 = lv_img_create(cont, NULL);
    lv_img_set_src(img3, LV_SYMBOL_BLUETOOTH);
    lv_obj_align(img3, img2, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

    lv_obj_t *img4 = lv_img_create(cont, NULL);
    lv_img_set_src(img4, LV_SYMBOL_WARNING);
    lv_obj_align(img4, img3, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

    lv_obj_t *img5 = lv_img_create(cont, NULL);
    lv_img_set_src(img5, LV_SYMBOL_USB);
    lv_obj_align(img5, img4, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

    lv_obj_t *img6 = lv_img_create(cont, NULL);
    lv_img_set_src(img6, LV_SYMBOL_WIFI);
    lv_obj_align(img6, img5, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

    lv_obj_t *img7 = lv_img_create(cont, NULL);
    lv_img_set_src(img7, LV_SYMBOL_BATTERY_3);
    lv_obj_align(img7, img6, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    return cont;
}

lv_obj_t *net_display_bar(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;

    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128 - 16 - 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    // lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "net_display");

    lv_obj_t *img1 = lv_img_create(cont, NULL);
    lv_img_set_src(img1, &user_20x20);
    lv_obj_align(img1, cont, LV_ALIGN_IN_TOP_LEFT, 15, 25);
    lv_obj_t *label1 = lv_label_create(cont, NULL);
    lv_label_set_text(label1, "TOM NAME"); //
    lv_obj_align(label1, cont, LV_ALIGN_IN_TOP_LEFT, 15 + 20 + 5, 25 + 2);

    lv_obj_t *img2 = lv_img_create(cont, NULL);
    lv_img_set_src(img2, &group_20x20);
    lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    lv_obj_t *label2 = lv_label_create(cont, NULL);
    lv_label_set_text(label2, "TOM GROUP");
    lv_obj_align(label2, cont, LV_ALIGN_IN_TOP_LEFT, 15 + 20 + 5, 25 + 2 + 20 + 5);

    return cont;
}

static void btn_ok_event_cb(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
        printf("Clicked\n");
    }
    else if (event == LV_EVENT_VALUE_CHANGED)
    {
        printf("Toggled\n");

        page_switch(1);
    }
}

static lv_obj_t *bottom_bar(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;

    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    lv_obj_t *btn = lv_btn_create(cont, NULL);
    lv_obj_set_event_cb(btn, btn_ok_event_cb);
    lv_obj_set_size(btn, 32, 16);
    lv_obj_align(btn, cont, LV_ALIGN_IN_LEFT_MID, 0, 0);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Menu");

    return cont;
}

void lv_desktop(lv_obj_t *parent)
{
    lv_obj_t *cont_1, *cont_2, *cont_3;

    //创建一个容器对象
    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128);

    lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");
    cont_1 = net_notification_bar(cont, cont);
    cont_2 = net_display_bar(cont, cont_1);
    cont_3 = bottom_bar(cont, cont_2);
}

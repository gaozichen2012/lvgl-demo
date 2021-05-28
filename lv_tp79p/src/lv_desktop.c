#include "../lv_tp79p.h"
#include "lv_desktop.h"

#ifdef EC20
#include "Zpoc.h"
#endif

LV_IMG_DECLARE(user_20x20);
LV_IMG_DECLARE(group_20x20);
LV_IMG_DECLARE(freq_20x20);

LV_FONT_DECLARE(NotoSansSC_Regular_bpp2_12);
LV_FONT_DECLARE(NotoSansSC_Regular_bpp2_16);

static lv_group_t *g;
lv_obj_t *desktop_cont;

static void event_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    switch (event)
    {
    case LV_EVENT_CLICKED: //LV_KEY_ENTER
        page_switch(PAGE_MENU);
        break;
    case LV_EVENT_CANCEL: //LV_KEY_ESC
        break;
    default:
        break;
    }
}

lv_obj_t *net_notification_bar(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont = lv_cont_create(parent, NULL);
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

#ifndef EC20
static void sim_event_ok_handler(lv_obj_t *obj, lv_event_t event)
{
    printf("event_handler: %d\n", event);

    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_event_send(desktop_cont, LV_EVENT_CLICKED, NULL);
    }
}
#endif

static void bottom_bar(lv_obj_t *parent)
{
    lv_obj_t *btn = lv_btn_create(parent, NULL);
#ifndef EC20
    lv_obj_set_event_cb(btn, sim_event_ok_handler);
#endif
    lv_obj_set_size(btn, 40, 20);
    lv_obj_align(btn, parent, LV_ALIGN_IN_BOTTOM_LEFT, 5, -5);
    lv_btn_set_checkable(btn, true);
    lv_btn_toggle(btn);
    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_16);
#if 1
    lv_label_set_text(label, "菜单");
#else
    lv_label_set_text(label, "\xE4\xB8\x80"
                             "\xE4\xB8\x83");
#endif

    //lv_label_set_text(label, "Menu");
}

#define c_input_password "0031003200398bf763094e0a4e0b952e8f9351655bc600610064007a7801" //请按上下键输入密码
#define TTS_net_mode_disable_channel "7a0032006C51517F216A0F5F8179626B07526263E14F5390" //公网模式禁止切换信道

static void central_area(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;
    lv_obj_t *label;
    char user_name[3 * 12 + 1];
    char group_name[3 * 12 + 1];

    unsigned long tom_unicode_test = 0x7FA4;
    unsigned char tom_utf8_test[10] = {0};

    memset(user_name, 0, sizeof(user_name));
    memset(group_name, 0, sizeof(group_name));

#ifdef EC20
    data_conv(iUserInfo.ucUserName, user_name, 1);
    data_conv(iUserInfo.ucGroupName, group_name, 1);
#else
    memcpy(user_name, "高子晨TOM 1", strlen("高子晨用户名"));
    memcpy(group_name, "高子晨GROUP 1", strlen("高子晨GROUP 1"));
#endif

    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128 - 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    lv_obj_t *img1 = lv_img_create(cont, NULL);
    lv_img_set_src(img1, &user_20x20);
    lv_obj_align(img1, cont, LV_ALIGN_IN_TOP_LEFT, 15, 25);
    label = lv_label_create(cont, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_16);
    lv_label_set_text(label, user_name);
    lv_obj_align(label, cont, LV_ALIGN_IN_TOP_LEFT, 15 + 20 + 5, 25 + 2);

    lv_obj_t *img2 = lv_img_create(cont, NULL);
    lv_img_set_src(img2, &group_20x20);
    lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    label = lv_label_create(cont, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_16);
    lv_label_set_text(label, group_name);
    lv_obj_align(label, cont, LV_ALIGN_IN_TOP_LEFT, 15 + 20 + 5, 25 + 2 + 20 + 5);

    bottom_bar(cont);
}

void lv_desktop(lv_obj_t *parent)
{
    desktop_cont = lv_cont_create(parent, NULL);
    lv_obj_set_event_cb(desktop_cont, event_handler);
    lv_obj_set_size(desktop_cont, 160, 128);

    lv_obj_set_style_local_value_str(desktop_cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");
    lv_obj_t *cont_1 = net_notification_bar(desktop_cont, desktop_cont);
    central_area(desktop_cont, cont_1);

    g = lv_group_create();
    lv_group_add_obj(g, desktop_cont);
#ifdef EC20
    lv_indev_set_group(indev_keypad, g);
#endif
}

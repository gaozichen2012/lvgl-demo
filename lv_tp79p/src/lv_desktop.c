#include "../lv_tp79p.h"
#include "lv_desktop.h"

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

//WideCharToMultiByte和MultiByteToWideChar

int enc_get_utf8_size(const unsigned char pInput)
{
    unsigned char c = pInput;
    // 0xxxxxxx 返回0
    // 10xxxxxx 不存在
    // 110xxxxx 返回2
    // 1110xxxx 返回3
    // 11110xxx 返回4
    // 111110xx 返回5
    // 1111110x 返回6
    if (c < 0x80)
        return 0;
    if (c >= 0x80 && c < 0xC0)
        return -1;
    if (c >= 0xC0 && c < 0xE0)
        return 2;
    if (c >= 0xE0 && c < 0xF0)
        return 3;
    if (c >= 0xF0 && c < 0xF8)
        return 4;
    if (c >= 0xF8 && c < 0xFC)
        return 5;
    if (c >= 0xFC)
        return 6;
}

/*
    将一个字符的Unicode(UCS-2和UCS-4)编码转换成UTF-8编码
    输入："群"的UNICODE编码16进制0x7FA4
    输出：[0]=231=0xE7 [1]=190=0xBE [2]=164=0xA4 [3]=0 即0xE7BEA4 对应"群"
*/

int enc_unicode_to_utf8_one(unsigned long unic, unsigned char *pOutput)
{
    if (unic <= 0x0000007F)
    {
        // * U-00000000 - U-0000007F:  0xxxxxxx
        *pOutput = (unic & 0x7F);
        return 1;
    }
    else if (unic >= 0x00000080 && unic <= 0x000007FF)
    {
        // * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
        *(pOutput + 1) = (unic & 0x3F) | 0x80;
        *pOutput = ((unic >> 6) & 0x1F) | 0xC0;
        return 2;
    }
    else if (unic >= 0x00000800 && unic <= 0x0000FFFF)
    {
        // * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
        *(pOutput + 2) = (unic & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 6) & 0x3F) | 0x80;
        *pOutput = ((unic >> 12) & 0x0F) | 0xE0;
        return 3;
    }
    else if (unic >= 0x00010000 && unic <= 0x001FFFFF)
    {
        // * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        *(pOutput + 3) = (unic & 0x3F) | 0x80;
        *(pOutput + 2) = ((unic >> 6) & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 12) & 0x3F) | 0x80;
        *pOutput = ((unic >> 18) & 0x07) | 0xF0;
        return 4;
    }
    else if (unic >= 0x00200000 && unic <= 0x03FFFFFF)
    {
        // * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
        *(pOutput + 4) = (unic & 0x3F) | 0x80;
        *(pOutput + 3) = ((unic >> 6) & 0x3F) | 0x80;
        *(pOutput + 2) = ((unic >> 12) & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 18) & 0x3F) | 0x80;
        *pOutput = ((unic >> 24) & 0x03) | 0xF8;
        return 5;
    }
    else if (unic >= 0x04000000 && unic <= 0x7FFFFFFF)
    {
        // * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
        *(pOutput + 5) = (unic & 0x3F) | 0x80;
        *(pOutput + 4) = ((unic >> 6) & 0x3F) | 0x80;
        *(pOutput + 3) = ((unic >> 12) & 0x3F) | 0x80;
        *(pOutput + 2) = ((unic >> 18) & 0x3F) | 0x80;
        *(pOutput + 1) = ((unic >> 24) & 0x3F) | 0x80;
        *pOutput = ((unic >> 30) & 0x01) | 0xFC;
        return 6;
    }

    return 0;
}

//将一个字符的UTF8编码转换成Unicode (UCS-2和UCS-4)编码.
int enc_utf8_to_unicode_one(const unsigned char *pInput, unsigned long *Unic)
{
#if 0
    assert(pInput != NULL && Unic != NULL);
#endif

    // b1 表示UTF-8编码的pInput中的高字节, b2 表示次高字节, ...
    char b1, b2, b3, b4, b5, b6;

    *Unic = 0x0; // 把 *Unic 初始化为全零
    int utfbytes = enc_get_utf8_size(*pInput);
    unsigned char *pOutput = (unsigned char *)Unic;

    switch (utfbytes)
    {
    case 0:
        *pOutput = *pInput;
        utfbytes += 1;
        break;
    case 2:
        b1 = *pInput;
        b2 = *(pInput + 1);
        if ((b2 & 0xE0) != 0x80)
            return 0;
        *pOutput = (b1 << 6) + (b2 & 0x3F);
        *(pOutput + 1) = (b1 >> 2) & 0x07;
        break;
    case 3:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b2 << 6) + (b3 & 0x3F);
        *(pOutput + 1) = (b1 << 4) + ((b2 >> 2) & 0x0F);
        break;
    case 4:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        b4 = *(pInput + 3);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80) || ((b4 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b3 << 6) + (b4 & 0x3F);
        *(pOutput + 1) = (b2 << 4) + ((b3 >> 2) & 0x0F);
        *(pOutput + 2) = ((b1 << 2) & 0x1C) + ((b2 >> 4) & 0x03);
        break;
    case 5:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        b4 = *(pInput + 3);
        b5 = *(pInput + 4);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80) || ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b4 << 6) + (b5 & 0x3F);
        *(pOutput + 1) = (b3 << 4) + ((b4 >> 2) & 0x0F);
        *(pOutput + 2) = (b2 << 2) + ((b3 >> 4) & 0x03);
        *(pOutput + 3) = (b1 << 6);
        break;
    case 6:
        b1 = *pInput;
        b2 = *(pInput + 1);
        b3 = *(pInput + 2);
        b4 = *(pInput + 3);
        b5 = *(pInput + 4);
        b6 = *(pInput + 5);
        if (((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80) || ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80) || ((b6 & 0xC0) != 0x80))
            return 0;
        *pOutput = (b5 << 6) + (b6 & 0x3F);
        *(pOutput + 1) = (b5 << 4) + ((b6 >> 2) & 0x0F);
        *(pOutput + 2) = (b3 << 2) + ((b4 >> 4) & 0x03);
        *(pOutput + 3) = ((b1 << 6) & 0x40) + (b2 & 0x3F);
        break;
    default:
        return 0;
        break;
    }

    return utfbytes;
}

/*
最终的目标是将


0x7F(7FA47EC4)
0xA4
0x7E
0xC4
转为
0xe7（e7bea4 e7bb84）
0xbe
0xa4
0xe7
0xbb
0x84

1.将“7FA47EC4”分离
*/
/*
pStr 输入：汉字“群组”的UNICODE编码16进制“7FA47EC4”
iEds =0大端 =1小端


输出：供LVGL显示的UTF-8数组
0xe7（e7bea4 e7bb84）
0xbe
0xa4
0xe7
0xbb
0x84
*/

unsigned char ui_ascii_to_char(unsigned char nib_h, unsigned char nib_l)
{
    nib_h = (nib_h <= '9') ? (nib_h - 0x30) : ((nib_h <= 'F') ? (nib_h - 0x37) : (nib_h - 0x57));
    nib_l = (nib_l <= '9') ? (nib_l - 0x30) : ((nib_l <= 'F') ? (nib_l - 0x37) : (nib_l - 0x57));

    return ((nib_h << 4) | nib_l);
}

void data_conv(char *pStr, unsigned char *des, unsigned char iEds)
{
    unsigned short usUnicode, i = 0;
    unsigned char index = 0; //显示字符个数

    memset(des, 0, sizeof(des));

    if (strlen((char *)pStr) % 2 != 0)
    {
        printf("ui16 invalid length!!\r\n");
        return;
    }

    while (*pStr)
    {
        if (iEds == 0)
            usUnicode = ((unsigned short)(ui_ascii_to_char(*pStr, *(pStr + 1))) << 8) + ui_ascii_to_char(*(pStr + 2), *(pStr + 3));
        else
            usUnicode = ((unsigned short)(ui_ascii_to_char(*(pStr + 2), *(pStr + 3))) << 8) + ui_ascii_to_char(*(pStr), *(pStr + 1));

        if (usUnicode <= 0x007e)
        {
        }
        else
        {
            enc_unicode_to_utf8_one((unsigned long)usUnicode, &des[3 * i]);
        }

        i++;
        pStr += 4;
    }
}

#define c_input_password "8bf763094e0a4e0b952e8f9351655bc67801"                 //请按上下键输入密码
#define TTS_net_mode_disable_channel "6C51517F216A0F5F8179626B07526263E14F5390" //公网模式禁止切换信道

static void central_area(lv_obj_t *parent, lv_obj_t *obj_ref)
{
    lv_obj_t *cont;
    lv_obj_t *label;
    char tomtest1[3 * 10 + 1];
    char tomtest2[3 * 10 + 1];
    unsigned long tom_unicode_test = 0x7FA4;
    unsigned char tom_utf8_test[10] = {0};

    memset(tomtest1, 0, sizeof(tomtest1));
    memset(tomtest2, 0, sizeof(tomtest2));
    data_conv(c_input_password, tomtest1, 0);
    data_conv(TTS_net_mode_disable_channel, tomtest2, 1);
    cont = lv_cont_create(parent, NULL);
    lv_obj_set_size(cont, 160, 128 - 16);
    lv_obj_align(cont, obj_ref, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    // lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "net_display");

    lv_obj_t *img1 = lv_img_create(cont, NULL);
    lv_img_set_src(img1, &user_20x20);
    lv_obj_align(img1, cont, LV_ALIGN_IN_TOP_LEFT, 15, 25);
    label = lv_label_create(cont, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_16);
    lv_label_set_text(label, tomtest1); //TOM群组12abCDQ
    lv_obj_align(label, cont, LV_ALIGN_IN_TOP_LEFT, 15 + 20 + 5, 25 + 2);

    lv_obj_t *img2 = lv_img_create(cont, NULL);
    lv_img_set_src(img2, &group_20x20);
    lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    label = lv_label_create(cont, NULL);
    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &NotoSansSC_Regular_bpp2_16);
    lv_label_set_text(label, tomtest2);
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

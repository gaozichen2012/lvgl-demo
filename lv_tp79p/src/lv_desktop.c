#include "lv_desktop.h"
#include "../lv_tp79p.h"

static lv_obj_t *cont;
static lv_style_t style_box;

static lv_obj_t *tv;
static lv_obj_t *t1;
static lv_obj_t *t2;
static lv_obj_t *t3;
static lv_obj_t *t4;

void network_create(lv_obj_t *parent)
{
    //设置页面可滚动部分的布局
    lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);

    //Get the size category of the display based on it's hor. res. and dpi.
    lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);
    //划分对象的宽度并获得给定列数的宽度。还应考虑背景的填充和可滚动的填充。
    lv_coord_t grid_w = lv_page_get_width_grid(parent, disp_size <= LV_DISP_SIZE_SMALL ? 1 : 2, 1);

    //创建一个容器对象
    lv_obj_t *h = lv_cont_create(parent, NULL);
    lv_cont_set_layout(h, LV_LAYOUT_PRETTY_MID);
    //将新样式添加到对象的样式列表。
    lv_obj_add_style(h, LV_CONT_PART_MAIN, &style_box);
    //启用使用父项进行拖动相关的操作。如果尝试拖动对象，则父级将被移动
    lv_obj_set_drag_parent(h, true);

    lv_obj_set_style_local_value_str(h, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");

    //分别水平和垂直设置适合策略。它告诉您如何自动更改容器的大小。
    lv_cont_set_fit2(h, LV_FIT_NONE, LV_FIT_TIGHT);
    lv_obj_set_width(h, grid_w);
    lv_obj_t *btn = lv_btn_create(h, NULL);
    lv_btn_set_fit2(btn, LV_FIT_NONE, LV_FIT_TIGHT);
    lv_obj_set_width(btn, lv_obj_get_width_grid(h, disp_size <= LV_DISP_SIZE_SMALL ? 1 : 2, 1));
    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Button");

    btn = lv_btn_create(h, btn);
    lv_btn_toggle(btn);
    label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Button");
}

void lv_desktop(void)
{
#if 1
    //初始化一个style
    lv_style_init(&style_box);

    //add a value text properties
    lv_style_set_value_align(&style_box, LV_STATE_DEFAULT, LV_ALIGN_OUT_TOP_LEFT);
    lv_style_set_value_ofs_y(&style_box, LV_STATE_DEFAULT, -LV_DPX(10));
    lv_style_set_margin_top(&style_box, LV_STATE_DEFAULT, LV_DPX(30));

    //创建一个容器对象
    lv_obj_t *cont = lv_cont_create(lv_scr_act(), NULL);

    //Get the size category of the display based on it's hor. res. and dpi.
    lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);

    lv_cont_set_layout(cont, LV_LAYOUT_PRETTY_MID);
    //将新样式添加到对象的样式列表。
    lv_obj_add_style(cont, LV_CONT_PART_MAIN, &style_box);
    //启用使用父项进行拖动相关的操作。如果尝试拖动对象，则父级将被移动
    lv_obj_set_drag_parent(cont, true);

    lv_obj_set_style_local_value_str(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Basics");

    lv_obj_t *btn = lv_btn_create(cont, NULL);
    lv_btn_set_fit2(btn, LV_FIT_NONE, LV_FIT_TIGHT);
    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Button");

#else
    //lv_scr_act()获取默认显示的活动屏幕的指针
    //lv_tabview_create()创建一个tabview()
    tv = lv_tabview_create(lv_scr_act(), NULL);

    t1 = lv_tabview_add_tab(tv, "Network");
    t2 = lv_tabview_add_tab(tv, "Anglog");
    t3 = lv_tabview_add_tab(tv, "Mix");
    t4 = lv_tabview_add_tab(tv, "Mix");

    //初始化一个style
    lv_style_init(&style_box);

    //add a value text properties
    lv_style_set_value_align(&style_box, LV_STATE_DEFAULT, LV_ALIGN_OUT_TOP_LEFT);
    lv_style_set_value_ofs_y(&style_box, LV_STATE_DEFAULT, -LV_DPX(10));
    lv_style_set_margin_top(&style_box, LV_STATE_DEFAULT, LV_DPX(30));

    network_create(t1);
#endif
}
#include "../lv_tp79p.h"
#include "lv_startup.h"

#include "lv_desktop.h"
#include "lv_menu.h"
#include "lv_event.h"

lv_obj_t *desktop_src;
lv_obj_t *menu_src;

void lv_startup(void)
{
    desktop_src = lv_obj_create(NULL, NULL);
    menu_src = lv_obj_create(NULL, NULL);

    //lv_disp_set_default(desktop_src);
    //lv_scr_act()

    lv_desktop(desktop_src);
    lv_menu(menu_src);

    lv_scr_load(desktop_src);
}
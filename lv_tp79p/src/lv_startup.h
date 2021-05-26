#ifndef __LV_STARTUP_H
#define __LV_STARTUP_H

typedef enum
{
    PAGE_INIT,
    PAGE_DESKTOP,
    PAGE_MENU,
    PAGE_GROUP,
    PAGE_MEMBER,
    PAGE_FRIEND,
    PAGE_GPS,
    PAGE_SETING,
    PAGE_BLIGHT,
    PAGE_INVITE,
    PAGE_SOS,
} PAGE_ID;

typedef struct
{
    lv_obj_t *desktop_src;
    lv_obj_t *menu_src;
    lv_obj_t *setting_src;
    lv_obj_t *blight_src;
} ALL_SRC;

ALL_SRC all_src;

void lv_startup(void);

#endif

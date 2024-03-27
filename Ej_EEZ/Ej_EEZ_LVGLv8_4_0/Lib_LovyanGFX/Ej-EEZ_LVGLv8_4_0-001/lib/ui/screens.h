#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main1;
    lv_obj_t *main2;
    lv_obj_t *main3;
    lv_obj_t *bt_minus;
    lv_obj_t *bt_pagina_1;
    lv_obj_t *bt_pagina_2;
    lv_obj_t *bt_pagina_3;
    lv_obj_t *bt_pagina_dos_r;
    lv_obj_t *bt_pagina_tres_r;
    lv_obj_t *bt_pagina_tres_r_1;
    lv_obj_t *bt_pagina_uno;
    lv_obj_t *bt_pagina_uno_l;
    lv_obj_t *bt_pagina_uno_l_1;
    lv_obj_t *bt_plus;
    lv_obj_t *label_counter;
    lv_obj_t *panel_main1;
    lv_obj_t *panel_main1_1;
    lv_obj_t *panel_main1_2;
    lv_obj_t *panel01;
    lv_obj_t *panel01_1;
    lv_obj_t *panel01_2;
    lv_obj_t *panel02;
    lv_obj_t *panel03;
    lv_obj_t *panel03_1;
    lv_obj_t *panel03_2;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN1 = 1,
    SCREEN_ID_MAIN2 = 2,
    SCREEN_ID_MAIN3 = 3,
};

void create_screen_main1();
void tick_screen_main1();

void create_screen_main2();
void tick_screen_main2();

void create_screen_main3();
void tick_screen_main3();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/
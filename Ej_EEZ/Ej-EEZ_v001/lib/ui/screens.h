#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *bt_conectar_wi_fi;
    lv_obj_t *bt_conectar_wi_fi_1;
    lv_obj_t *bt_des_conectar_wi_fi;
    lv_obj_t *panel_boton01;
    lv_obj_t *panel_dns;
    lv_obj_t *panel_ip;
    lv_obj_t *panel_mac;
    lv_obj_t *panel_red_wi_fi;
    lv_obj_t *panel_text01;
    lv_obj_t *ui_bt_conectado;
    lv_obj_t *ui_lab_dns;
    lv_obj_t *ui_lab_ip;
    lv_obj_t *ui_lab_mac;
    lv_obj_t *ui_lab_ssid;
    lv_obj_t *ui_label_conectar_wi_fi;
    lv_obj_t *ui_panel_conectar_wi_fi;
    lv_obj_t *wi_fi_cautivo;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/
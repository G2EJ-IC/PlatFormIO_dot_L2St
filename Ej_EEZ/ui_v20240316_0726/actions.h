#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>
#include "screens.h"

#ifdef __cplusplus
extern "C" {
#endif

// objects_t my_objects;

extern void action_fn_conectar_wi_fi(lv_event_t * e);
extern void action_fn_des_conectar_wi_fi(lv_event_t * e);
extern void action_fn_presionar_bt_ok(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/
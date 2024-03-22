#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <lvgl.h>

extern void action_fn_pagina_1_uno(lv_event_t * e);
extern void action_fn_pagina_2_dos(lv_event_t * e);
extern void action_fn_plus(lv_event_t * e);
extern void action_fn_minus(lv_event_t * e);
extern void action_fn_pagina_3_tres(lv_event_t * e);
extern void action_fn_pagina_1_ok(lv_event_t * e);
extern void action_fn_pagina_2_ok(lv_event_t * e);
extern void action_fn_pagina_3_ok(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/
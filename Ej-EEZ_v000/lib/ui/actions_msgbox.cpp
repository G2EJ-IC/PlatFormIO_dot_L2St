#include <Arduino.h>
/** 
* @brief : Función Similar a cout << de C++, Debe estar despues de #include <Arduino.h> para que funcione.
* @param : T.
* @return : obj.
*/
template<class T>
inline Print &operator <<(Print &obj, T arg) { 
    obj.print(arg); 
    return obj; 
}

#include "actions.h"
#include "screens.h"
#include "actions_msgbox.h"

#if LV_USE_MSGBOX && LV_BUILD_EXAMPLES

lv_obj_t *mbox1;

static void event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_current_target(e);

    LV_LOG_USER("Button %s clicked", lv_msgbox_get_active_btn_text(obj));

    if (lv_msgbox_get_active_btn_text(obj) == "Aceptar") {
        lv_obj_del(lv_event_get_target(e));  // Cierra el cuadro de mensaje
        // Realiza acciones adicionales para Aceptar aquí
        lv_msgbox_close(mbox1);
    }

    if (lv_msgbox_get_active_btn_text(obj) == "Cancelar") {
        lv_obj_del(lv_event_get_target(e));    // Cierra el cuadro de mensaje
        // Realiza acciones adicionales para Cancelar aquí
        lv_msgbox_close(mbox1);
    }
}

void lv_msgbox_1(const char * title,int counter)
{
    std::string counter1 = "Elemento.: (" + std::to_string(counter) + ")";
	const char * TXT = counter1.c_str();

    static const char * btns[] = {"Aceptar", "Cancelar", NULL};

    mbox1 = lv_msgbox_create(NULL, title, TXT, btns, true);

    {
        lv_obj_set_style_bg_color(mbox1, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(mbox1, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(mbox1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            lv_obj_t * btn1 = lv_msgbox_get_btns(mbox1);
            lv_btnmatrix_set_map(btn1, btns);
            lv_btnmatrix_set_btn_ctrl(btn1, 0, LV_BTNMATRIX_CTRL_CHECKED);
            lv_btnmatrix_set_btn_ctrl(btn1, 1, LV_BTNMATRIX_CTRL_CHECKED);
        }
        lv_obj_add_event_cb(mbox1, event_cb, LV_EVENT_CLICKED, NULL);
        lv_obj_center(mbox1);
    }   
}

#endif

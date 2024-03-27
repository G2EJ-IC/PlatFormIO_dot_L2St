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
#include "widgets_AIoT.h"
#include "ConectarWiFi_AIoT.h"

int counter;
WiFi_AIoT wifi_AIoT;

extern void action_fn_pagina_1_uno(lv_event_t * e)
{
	lv_scr_load(objects.main1);
}

extern void action_fn_pagina_2_dos(lv_event_t * e)
{
	lv_scr_load(objects.main2);
}

extern void action_fn_pagina_3_tres(lv_event_t * e)
{	
	lv_scr_load(objects.main3);
}

extern void action_fn_pagina_1_ok(lv_event_t * e)
{
	lv_msgbox_1("- Pag. 1 -", &counter);
}

extern void action_fn_pagina_2_ok(lv_event_t * e)
{
	lv_msgbox_1("- Pag. 2 -", &counter);
}

extern void action_fn_pagina_3_ok(lv_event_t * e)
{
	lv_msgbox_1("- Pag. 3 -", &counter);
}

extern void action_fn_plus(lv_event_t * e)
{
	int counter2 = ++counter;
	const char *counter3 = std::to_string(counter2).c_str();
	lv_label_set_text(objects.label_counter, counter3);
	Serial << "\nEl contador va en.: (" << counter << ").\n\n";
}

extern void action_fn_minus(lv_event_t * e)
{
	int counter2 = --counter;
	const char *counter3 = std::to_string(counter2).c_str();
	lv_label_set_text(objects.label_counter, counter3);
	Serial << "\nEl contador va en.: (" << counter << ").\n\n";
}

extern void action_fn_conectar_wi_fi(lv_event_t * e)
{
	int opcion = lv_dropdown_get_selected(objects.drop_down_1);
	wifi_AIoT.ConectarWiFi_AIoT(opcion);
	if (WiFi.status() == WL_CONNECTED) {
		lv_label_set_text(objects.ui_lab_ssid, wifi_AIoT.get_AIoT_SSID().c_str());
		lv_label_set_text(objects.ui_lab_ip, wifi_AIoT.get_AIoT_IP().c_str());
		lv_label_set_text(objects.ui_lab_dns, wifi_AIoT.get_AIoT_DNS().c_str());
		lv_label_set_text(objects.ui_lab_mac, wifi_AIoT.get_AIoT_MAC().c_str());
		lv_obj_set_style_bg_color(objects.bt_conectado_2, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(objects.bt_conectado_3, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
	} else {
		lv_label_set_text(objects.ui_lab_ssid, "Nombre WiFi (SSID)");
		lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
		lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
		lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
		lv_obj_set_style_bg_color(objects.bt_conectado_2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(objects.bt_conectado_3, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	}
}

extern void action_fn_desconectar_wi_fi(lv_event_t * e)
{
	lv_label_set_text(objects.ui_lab_ssid, "Nombre WiFi (SSID)");
	lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
	lv_obj_set_style_bg_color(objects.bt_conectado_2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(objects.bt_conectado_3, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	wifi_AIoT.DisconnectWiFi_AIoT();
}

extern void action_fn_rescan_wi_fi(lv_event_t * e)
{
	lv_label_set_text(objects.ui_lab_ssid, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
	lv_obj_set_style_bg_color(objects.bt_conectado_2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(objects.bt_conectado_3, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	wifi_AIoT.ResetWiFi_AIoT();
}

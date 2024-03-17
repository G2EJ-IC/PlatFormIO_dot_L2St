#include "actions.h"
#include "screens.h"

// #include "ui.h"
#include <WiFi.h>
#include <WiFiManager.h>
#include <ConectarWiFi_AIoT.h>

extern void action_fn_conectar_wi_fi(lv_event_t * e)
{
	lv_obj_add_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);
	ConectarWiFi_AIoT();
	if (WiFi.status() == WL_CONNECTED) {
	    lv_label_set_text(objects.ui_lab_ssid, WiFi.SSID().c_str());
		lv_label_set_text(objects.ui_lab_ip, WiFi.localIP().toString().c_str());
		lv_label_set_text(objects.ui_lab_dns, WiFi.dnsIP().toString().c_str());
		lv_label_set_text(objects.ui_lab_mac, WiFi.macAddress().c_str());
		lv_label_set_text(objects.ui_label_conectar_wi_fi, "Conecte el celular a la red \n(.:: AIoT_NodeESP32 ::.)\n y configure WiFi....");
		lv_obj_clear_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);	
		lv_obj_set_style_bg_color(objects.ui_bt_conectado, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
	} else {
	    lv_label_set_text(objects.ui_lab_ssid, "xx.xx.xx.xx");
		lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
		lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
		lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
		lv_label_set_text(objects.ui_label_conectar_wi_fi, "Conecte el celular a la RED \n(.:: AIoT_NodeESP32 ::.)\n y configure WiFi....");
		lv_obj_clear_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_color(objects.ui_bt_conectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	}
}

extern void action_fn_des_conectar_wi_fi(lv_event_t * e)
{
	lv_obj_add_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);
	lv_label_set_text(objects.ui_lab_ssid, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
	lv_label_set_text(objects.ui_label_conectar_wi_fi, "DesConectado de la RED WiFi");
	lv_obj_clear_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_bg_color(objects.ui_bt_conectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	DisconnectWiFi_AIoT();
}

extern void action_fn_presionar_bt_ok(lv_event_t * e)
{
    lv_obj_add_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);
}
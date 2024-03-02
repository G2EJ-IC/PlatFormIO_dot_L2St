// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: Ej_ButtonL2St

#include "ui.h"
#include <WiFi.h>
#include <WiFiManager.h>
#include <ConectarWiFi_AIoT.h>

void Presionar_Bt11(lv_event_t * e) {
	lv_obj_add_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);
	ConectarWiFi_AIoT();
	if (WiFi.status() == WL_CONNECTED) {
		lv_label_set_text(ui_LabSSID, WiFi.SSID().c_str());
		lv_label_set_text(ui_LabIP, WiFi.localIP().toString().c_str());
		lv_label_set_text(ui_LabDNS, WiFi.dnsIP().toString().c_str());
		lv_label_set_text(ui_LabMAC, WiFi.macAddress().c_str());
		lv_label_set_text(ui_LabelConectarWiFi, "Conectese a la Red Cautiva WiFi \n.:: AIoT_NodeESP32 ::.");
		lv_obj_clear_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);		
		lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(ui_BtConectado1, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
	} else {
		lv_label_set_text(ui_LabSSID, "xx.xx.xx.xx");
		lv_label_set_text(ui_LabIP, "xx.xx.xx.xx");
		lv_label_set_text(ui_LabDNS, "xx.xx.xx.xx");
		lv_label_set_text(ui_LabMAC, "xx:xx:xx:xx:xx:xx");
		lv_label_set_text(ui_LabelConectarWiFi, "Conectese a la Red Cautiva WiFi \n.:: AIoT_NodeESP32 ::.");
		lv_obj_clear_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(ui_BtConectado1, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	}
}

void Presionar_Bt12(lv_event_t * e) {
	DisconnectWiFi_AIoT();
	lv_obj_add_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);
	lv_label_set_text(ui_LabSSID, "xx.xx.xx.xx");
	lv_label_set_text(ui_LabIP, "xx.xx.xx.xx");
	lv_label_set_text(ui_LabDNS, "xx.xx.xx.xx");
	lv_label_set_text(ui_LabMAC, "xx:xx:xx:xx:xx:xx");
	lv_label_set_text(ui_LabelConectarWiFi, "DesConectado de la Red WiFi");
	lv_obj_clear_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Presionar_Bt21(lv_event_t * e) {
	Presionar_Bt11(e);
}

void Presionar_Bt22(lv_event_t * e) {
	ResetWiFi_AIoT();
	lv_obj_add_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);	
	lv_label_set_text(ui_LabSSID, "xx.xx.xx.xx");
	lv_label_set_text(ui_LabIP, "xx.xx.xx.xx");
	lv_label_set_text(ui_LabDNS, "xx.xx.xx.xx");
	lv_label_set_text(ui_LabMAC, "xx:xx:xx:xx:xx:xx");
	lv_label_set_text(ui_LabelConectarWiFi, "Reseteo de la Red WiFi");
	lv_obj_clear_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Presionar_BtOk(lv_event_t * e)
{
	lv_obj_add_flag(ui_PanelConectarWiFi, LV_OBJ_FLAG_HIDDEN);
}

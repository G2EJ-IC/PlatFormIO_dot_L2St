// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: Ej_ButtonL2St

#include "ui.h"
#include <WiFi.h>
#include <WiFiManager.h>
#include <ConectarWiFi_IoT.h>

void Presionar_Bt01(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
		ConectarWiFi_IoT();
        if (WiFi.status() == WL_CONNECTED) {
			lv_label_set_text(ui_LabSSID, WiFi.SSID().c_str());
			lv_label_set_text(ui_LabIP, WiFi.localIP().toString().c_str());
			lv_label_set_text(ui_LabDNS, WiFi.dnsIP().toString().c_str());
			lv_label_set_text(ui_LabMAC, WiFi.macAddress().c_str());		
			lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
		}
		else {
			lv_label_set_text(ui_LabSSID, "xx.xx.xx.xx");
			lv_label_set_text(ui_LabIP, "xx.xx.xx.xx");
			lv_label_set_text(ui_LabDNS, "xx.xx.xx.xx");
			lv_label_set_text(ui_LabMAC, "xx:xx:xx:xx:xx:xx");
			lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
		}
	}	
}

void Presionar_Bt02(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
		DisconnectWiFi_IoT();
		lv_label_set_text(ui_LabSSID, "xx.xx.xx.xx");
		lv_label_set_text(ui_LabIP, "xx.xx.xx.xx");
		lv_label_set_text(ui_LabDNS, "xx.xx.xx.xx");
		lv_label_set_text(ui_LabMAC, "xx:xx:xx:xx:xx:xx");
		lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	}
}
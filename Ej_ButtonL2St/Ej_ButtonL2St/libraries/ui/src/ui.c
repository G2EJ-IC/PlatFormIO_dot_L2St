// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: Ej_ButtonL2St

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Container4;
lv_obj_t * ui_TabViewWiFi;
lv_obj_t * ui_TabPageWiFiCautivo;
lv_obj_t * ui_Container1;
lv_obj_t * ui_Container11;
lv_obj_t * ui_LabSSID;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Container12;
lv_obj_t * ui_LabIP;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Container13;
lv_obj_t * ui_LabDNS;
lv_obj_t * ui_Label7;
lv_obj_t * ui_Container14;
lv_obj_t * ui_LabMAC;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Container2;
void ui_event_Bt1(lv_event_t * e);
lv_obj_t * ui_Bt1;
lv_obj_t * ui_Label1;
void ui_event_Bt2(lv_event_t * e);
lv_obj_t * ui_Bt2;
lv_obj_t * ui_Label5;
lv_obj_t * ui_BtConectado;
lv_obj_t * ui_TabPageConectarWiFi;
lv_obj_t * ui_Container3;
void ui_event_Bt3(lv_event_t * e);
lv_obj_t * ui_Bt3;
lv_obj_t * ui_Label2;
void ui_event_Bt4(lv_event_t * e);
lv_obj_t * ui_Bt4;
lv_obj_t * ui_Label6;
lv_obj_t * ui_BtConectado1;
lv_obj_t * ui_PanelConectarWiFi;
lv_obj_t * ui_LabelConectarWiFi;
void ui_event_BtOk(lv_event_t * e);
lv_obj_t * ui_BtOk;
lv_obj_t * ui_Label8;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Bt1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Presionar_Bt11(e);
    }
}
void ui_event_Bt2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Presionar_Bt12(e);
    }
}
void ui_event_Bt3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Presionar_Bt21(e);
    }
}
void ui_event_Bt4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Presionar_Bt22(e);
    }
}
void ui_event_BtOk(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Presionar_BtOk(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}

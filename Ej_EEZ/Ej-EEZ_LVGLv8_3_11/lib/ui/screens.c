#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_bt_conectar_wi_fi(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_conectar_wi_fi(e);
    }
}

static void event_handler_cb_main_bt_des_conectar_wi_fi(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_des_conectar_wi_fi(e);
    }
}

static void event_handler_cb_main_bt_conectar_wi_fi_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_presionar_bt_ok(e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // WiFiCautivo
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.wi_fi_cautivo = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 320);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // PanelBoton01
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel_boton01 = obj;
                    lv_obj_set_pos(obj, -10, -10);
                    lv_obj_set_size(obj, LV_PCT(105), LV_PCT(20));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Bt_ConectarWiFi
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_conectar_wi_fi = obj;
                            lv_obj_set_pos(obj, -10, -6);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_bt_conectar_wi_fi, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 19, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Conectar WiFi");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_DesConectarWiFi
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_des_conectar_wi_fi = obj;
                            lv_obj_set_pos(obj, 269, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_bt_des_conectar_wi_fi, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Desconectar WiFi");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // ui_BtConectado
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_bt_conectado = obj;
                            lv_obj_set_pos(obj, 201, -5);
                            lv_obj_set_size(obj, 30, 30);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // PanelText01
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel_text01 = obj;
                    lv_obj_set_pos(obj, -10, 55);
                    lv_obj_set_size(obj, LV_PCT(105), LV_PCT(85));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // PanelRedWiFi
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.panel_red_wi_fi = obj;
                            lv_obj_set_pos(obj, -10, -9);
                            lv_obj_set_size(obj, LV_PCT(105), LV_PCT(25));
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Red WiFi (SSID).:");
                                }
                                {
                                    // ui_LabSSID
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_lab_ssid = obj;
                                    lv_obj_set_pos(obj, 154, 0);
                                    lv_obj_set_size(obj, 258, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "xx.xx.xx.xx");
                                }
                            }
                        }
                        {
                            // PanelIP
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.panel_ip = obj;
                            lv_obj_set_pos(obj, -10, 48);
                            lv_obj_set_size(obj, LV_PCT(105), LV_PCT(25));
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Direccion IP.:");
                                }
                                {
                                    // ui_LabIP
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_lab_ip = obj;
                                    lv_obj_set_pos(obj, 154, 0);
                                    lv_obj_set_size(obj, 258, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "xx.xx.xx.xx");
                                }
                            }
                        }
                        {
                            // PanelDNS
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.panel_dns = obj;
                            lv_obj_set_pos(obj, -10, 105);
                            lv_obj_set_size(obj, LV_PCT(105), LV_PCT(25));
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Direccion DNS.:");
                                }
                                {
                                    // ui_LabDNS
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_lab_dns = obj;
                                    lv_obj_set_pos(obj, 154, 0);
                                    lv_obj_set_size(obj, 258, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "xx.xx.xx.xx");
                                }
                            }
                        }
                        {
                            // PanelMAC
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.panel_mac = obj;
                            lv_obj_set_pos(obj, -10, 163);
                            lv_obj_set_size(obj, LV_PCT(105), LV_PCT(25));
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Direccion MAC.:");
                                }
                                {
                                    // ui_LabMAC
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_lab_mac = obj;
                                    lv_obj_set_pos(obj, 154, 0);
                                    lv_obj_set_size(obj, 258, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "xx:xx:xx:xx:xx:xx");
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // ui_PanelConectarWiFi
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_panel_conectar_wi_fi = obj;
            lv_obj_set_pos(obj, 60, 119);
            lv_obj_set_size(obj, LV_PCT(75), LV_PCT(53));
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ui_LabelConectarWiFi
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ui_label_conectar_wi_fi = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(45));
                    lv_label_set_text(obj, "Conecte el celular a la red \n(.:: AIoT_NodeESP32 ::.)\ny configure WiFi....");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Bt_ConectarWiFi_1
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.bt_conectar_wi_fi_1 = obj;
                    lv_obj_set_pos(obj, 81, 93);
                    lv_obj_set_size(obj, LV_PCT(50), LV_PCT(25));
                    lv_obj_add_event_cb(obj, event_handler_cb_main_bt_conectar_wi_fi_1, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, -2);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(140));
                            lv_label_set_text(obj, "Aceptar");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}

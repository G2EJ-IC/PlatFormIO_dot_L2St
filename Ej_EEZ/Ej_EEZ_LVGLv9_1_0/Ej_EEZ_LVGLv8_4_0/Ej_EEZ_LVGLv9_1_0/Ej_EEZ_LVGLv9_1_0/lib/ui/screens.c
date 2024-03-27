#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main1_bt_pagina_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        action_fn_pagina_1_ok(e);
    }
}

static void event_handler_cb_main1_bt_pagina_uno(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_pagina_3_tres(e);
    }
}

static void event_handler_cb_main1_bt_pagina_dos_r(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_pagina_2_dos(e);
    }
}

static void event_handler_cb_main1_bt_plus(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        action_fn_plus(e);
    }
}

static void event_handler_cb_main1_bt_minus(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        action_fn_minus(e);
    }
}

static void event_handler_cb_main2_bt_pagina_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        action_fn_pagina_2_ok(e);
    }
}

static void event_handler_cb_main2_bt_pagina_uno_l(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_pagina_1_uno(e);
    }
}

static void event_handler_cb_main2_bt_pagina_tres_r(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_pagina_3_tres(e);
    }
}

static void event_handler_cb_main3_bt_pagina_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        action_fn_pagina_3_ok(e);
    }
}

static void event_handler_cb_main3_bt_pagina_uno_l_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_pagina_2_dos(e);
    }
}

static void event_handler_cb_main3_bt_pagina_tres_r_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        action_fn_pagina_1_uno(e);
    }
}

void create_screen_main1() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // PanelMain1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_main1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 320);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Panel01
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel01 = obj;
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
                            // Bt_Pagina_1
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_1 = obj;
                            lv_obj_set_pos(obj, 172, -5);
                            lv_obj_set_size(obj, LV_PCT(20), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main1_bt_pagina_1, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 5, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pag . 1");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_Pagina_Uno
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_uno = obj;
                            lv_obj_set_pos(obj, -9, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main1_bt_pagina_uno, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pagina Tres (03)");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_Pagina_Dos_R
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_dos_r = obj;
                            lv_obj_set_pos(obj, 268, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main1_bt_pagina_dos_r, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pagina Dos (02)");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
                {
                    // Panel02
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel02 = obj;
                    lv_obj_set_pos(obj, -11, 51);
                    lv_obj_set_size(obj, LV_PCT(105), LV_PCT(20));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Bt_Plus
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_plus = obj;
                            lv_obj_set_pos(obj, -8, -5);
                            lv_obj_set_size(obj, LV_PCT(20), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main1_bt_plus, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 18, -12);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "+");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // LabelCounter
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_counter = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "0");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Bt_Minus
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_minus = obj;
                            lv_obj_set_pos(obj, 348, -5);
                            lv_obj_set_size(obj, LV_PCT(20), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main1_bt_minus, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 21, -12);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "-");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
                {
                    // Panel03
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel03 = obj;
                    lv_obj_set_pos(obj, -10, 112);
                    lv_obj_set_size(obj, LV_PCT(105), LV_PCT(65));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_main1() {
    void *flowState = getFlowState(0, 0);
}

void create_screen_main2() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // PanelMain1_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_main1_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 320);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Panel01_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel01_1 = obj;
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
                            // Bt_Pagina_2
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_2 = obj;
                            lv_obj_set_pos(obj, 172, -5);
                            lv_obj_set_size(obj, LV_PCT(20), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main2_bt_pagina_2, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 5, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pag . 2");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_Pagina_Uno_L
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_uno_l = obj;
                            lv_obj_set_pos(obj, -9, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main2_bt_pagina_uno_l, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pagina Uno (01)");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_Pagina_Tres_R
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_tres_r = obj;
                            lv_obj_set_pos(obj, 268, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main2_bt_pagina_tres_r, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pagina Tres (03)");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
                {
                    // Panel03_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel03_1 = obj;
                    lv_obj_set_pos(obj, -10, 51);
                    lv_obj_set_size(obj, LV_PCT(105), LV_PCT(87));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_main2() {
    void *flowState = getFlowState(0, 1);
}

void create_screen_main3() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // PanelMain1_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.panel_main1_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 320);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Panel01_2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel01_2 = obj;
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
                            // Bt_Pagina_3
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_3 = obj;
                            lv_obj_set_pos(obj, 172, -5);
                            lv_obj_set_size(obj, LV_PCT(20), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main3_bt_pagina_3, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 5, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pag . 3");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_Pagina_Uno_L_1
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_uno_l_1 = obj;
                            lv_obj_set_pos(obj, -9, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main3_bt_pagina_uno_l_1, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pagina Dos (02)");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            // Bt_Pagina_Tres_R_1
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.bt_pagina_tres_r_1 = obj;
                            lv_obj_set_pos(obj, 268, -5);
                            lv_obj_set_size(obj, LV_PCT(40), LV_PCT(150));
                            lv_obj_add_event_cb(obj, event_handler_cb_main3_bt_pagina_tres_r_1, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 6, -3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Pagina Uno (01)");
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
                {
                    // Panel03_2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel03_2 = obj;
                    lv_obj_set_pos(obj, -10, 51);
                    lv_obj_set_size(obj, LV_PCT(105), LV_PCT(87));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_main3() {
    void *flowState = getFlowState(0, 2);
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main1();
    create_screen_main2();
    create_screen_main3();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main1,
    tick_screen_main2,
    tick_screen_main3,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}

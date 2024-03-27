#include <Arduino.h>
#include <lvgl.h>
#include "config.h"
#include <SPI.h>
#include <TFT_eSPI.h>
#include "display_service.h"
#include "tp_service.h"
#include "esp_freertos_hooks.h"
#include "ui.h"

display_service::display_service() {}
display_service::~display_service() {}

/*Change to your screen resolution*/
static const uint16_t N = 10u; // N = {10, 12, 16, 20, 24, 25, 32}

// extern TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
TFT_eSPI tft = TFT_eSPI(LV_HOR_RES_MAX, LV_VER_RES_MAX); /* TFT instance */
extern tp_service tp; // load tp service

static lv_disp_draw_buf_t draw_buf;

#if (BUF_NUM == 1)
/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (LV_HOR_RES_MAX * LV_VER_RES_MAX / N * (LV_COLOR_DEPTH / 8))
static lv_color_t buf1[DRAW_BUF_SIZE / 4];
#elif (BUF_NUM == 2)
static lv_color_t buf2[DRAW_BUF_SIZE / 4];
#endif

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR display_service::lv_setup()
{
    lv_init();
    tft.begin();                /* TFT init */
    tft.setRotation(ROTATION);  /* Landscape orientation, flipped */
    String LVGL_Arduino = "\n\nHello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println(LVGL_Arduino);
    Serial.println("I am LVGL_Arduino\n");

#if LV_USE_LOG != 0
    /* Serial debugging */
    void my_print(const char *buf1)
    {
        Serial.printf(buf1);
        Serial.flush();
    }
#endif    

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
}

void ICACHE_FLASH_ATTR display_service::touch_setup()
{
    tp.setup();         /* TFT setup*/

    //************************************************************************************************
    // tft.setBrightness(255);
    // uint16_t calData[5] = {X0, X1, Y0, Y1, rotate/invert_x/invert_y};

    uint16_t calData[5] = {209, 3656, 209, 3499, 1}; //
    tft.setTouch(calData);
    // lv_init();
    //************************************************************************************************

#if (BUF_NUM == 1)
    // lv_disp_buf_init(&disp_buf, buf1, NULL, DISP_BUF_SIZE);
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, DRAW_BUF_SIZE / 4);
#elif (BUF_NUM == 2)
    lv_disp_buf_init(&draw_buf, buf1, buf2, DRAW_BUF_SIZE / 4);
#endif

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    ui_init();

    Serial.println("Setup done");
}

void IRAM_ATTR display_service::lv_main()
{
    Serial.print(F("\n\n[INFO] LV GUI started.\n"));
}

void IRAM_ATTR display_service::my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();
    lv_disp_flush_ready(disp);
}

void IRAM_ATTR display_service::my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX = 0, touchY = 0;

    bool touched = tft.getTouch(&touchX, &touchY, 600);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        Serial.print("Data x ");
        Serial.println(touchX);

        Serial.print("Data y ");
        Serial.println(touchY);
    }
}

/* =============================iram functions=============================== */
void ICACHE_FLASH_ATTR display_service::setup()
{
    lv_setup();
    lv_task_handler();
    // esp_register_freertos_tick_hook(lv_tick_task);

    Serial.print(F("[INFO] Display GUI setup finished! \n"));
    touch_setup();
    // lv_main();
} // end display service setup

void IRAM_ATTR display_service::loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    // ui_tick();
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
    
} // end loop

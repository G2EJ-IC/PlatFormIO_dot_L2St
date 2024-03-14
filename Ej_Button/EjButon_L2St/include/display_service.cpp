#include <Arduino.h>
#include <lvgl.h>
#include "ui.h"
#include "LovyanGFX_Class_ILI9488.h"
#include "display_service.h"

static LGFX tft;

display_service::display_service() {}
display_service::~display_service() {}

#define DISP_STATE_INIT_WAIT_TIME (2000u)
#define DISP_STATE_WIFI_SSID_SCANNED_DONE_TIME (1000u)
#define WIFI_CONNECT_MAX_RETRY (5u)

/*Change to your screen resolution*/
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;
static const uint16_t N = 20u; // N = {10, 12, 16, 20, 24, 25, 32}

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / N];

/* Serial debugging */
void display_service::my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR display_service::lv_setup(void)
{
    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println(LVGL_Arduino);
    Serial.println("I am LVGL_Arduino");

#if LV_USE_LOG != 0
    /* Serial debugging */
    my_print(const char *buf);
#endif

    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
}

void ICACHE_FLASH_ATTR display_service::touch_setup(void)
{
    tft.begin();        /* TFT init */
    tft.setRotation(3); /* Landscape orientation, flipped */

    //************************************************************************************************
    // tft.setBrightness(255);
    // uint16_t calData[] = { 120, 3120, 170, 170, 4880, 3030, 4770, 50};
    uint16_t calData[] = {239, 3926, 233, 265, 3856, 3896, 3714, 308};
    tft.setTouchCalibrate(calData);
    lv_init();
    //************************************************************************************************

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / N);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
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

void IRAM_ATTR display_service::lv_main(void)
{
    Serial.print(F("[INFO] LV GUI started.\n"));
    // header_create();
    // body_create();
}

void IRAM_ATTR display_service::my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(disp);
}

void IRAM_ATTR display_service::my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX = 0, touchY = 0;

    // bool touched = false;//tft.getTouch(&touchX, &touchY, 600);
    bool touched = tft.getTouch(&touchX, &touchY, 0);

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
    // esp_register_freertos_tick_hook(lv_tick_task);

    Serial.print(F("[INFO] Display GUI setup finished! \n"));
    touch_setup();
    // lv_main();
} // end display service setup

void IRAM_ATTR display_service::loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
} // end loop
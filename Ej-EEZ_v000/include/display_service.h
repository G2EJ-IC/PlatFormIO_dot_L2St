#ifndef __DISPLAY_SERVICE_H__
#define __DISPLAY_SERVICE_H__

#define ICACHE_FLASH_ATTR

#include "lvgl.h"

class display_service
{
private:
    void ICACHE_FLASH_ATTR lv_setup();
    void ICACHE_FLASH_ATTR touch_setup();
    void IRAM_ATTR lv_main();
    static void IRAM_ATTR my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
    static void IRAM_ATTR my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

public:
    display_service();
    ~display_service();
    void IRAM_ATTR setup();
    void IRAM_ATTR loop();
};

#endif // __DISPLAY_SERVICE_H__
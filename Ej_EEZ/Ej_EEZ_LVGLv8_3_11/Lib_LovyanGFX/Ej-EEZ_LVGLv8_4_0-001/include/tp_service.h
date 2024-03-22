#ifndef __TP_SERVICE_H__
#define __TP_SERVICE_H__

#define ICACHE_FLASH_ATTR

#include "lvgl.h"

class tp_service
{
private:
    static void IRAM_ATTR my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

public:
    tp_service();
    ~tp_service();

    void ICACHE_FLASH_ATTR setup();
    void ICACHE_FLASH_ATTR loop();
};

#endif // __TP_SERVICE_H__
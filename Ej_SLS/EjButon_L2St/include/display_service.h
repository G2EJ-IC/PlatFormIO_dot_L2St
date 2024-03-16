//////////////////////////////////////////////////////////////////////////
/*
	ESP32 | LVGL8 | Ep 0. GFX Setup (ft. LovyanGFX)
	Developing Embedded GUI with SquareLine Studio [2/2]
	Configuración de lv_conf.h
	Video Tutorial: https://youtu.be/b_4m1A3A2yw
	Created by That Project
*/
//////////////////////////////////////////////////////////////////////////
/*
	Modificado: Ernesto José Guerrero González, Civil Engineering ud FJdC.
*/
//////////////////////////////////////////////////////////////////////////
#ifndef __DISPLAY_SERVICE_H__
#define __DISPLAY_SERVICE_H__

#define ICACHE_FLASH_ATTR

#include "lvgl.h"

class display_service
{
private:
    /* Serial debugging */
    void my_print(const char *);
    void ICACHE_FLASH_ATTR lv_setup(void);
    void ICACHE_FLASH_ATTR touch_setup(void);
    void IRAM_ATTR lv_main(void);
    static void IRAM_ATTR my_disp_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *);
    static void IRAM_ATTR my_touchpad_read(lv_indev_drv_t *, lv_indev_data_t *);

public:
    display_service();
    ~display_service();
    void IRAM_ATTR setup();
    void IRAM_ATTR loop();
};

#endif // __DISPLAY_SERVICE_H__
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
#ifndef __TP_SERVICE_H__
#define __TP_SERVICE_H__

#define ICACHE_FLASH_ATTR

class tp_service
{
private:
public:
    tp_service();
    ~tp_service();

    void ICACHE_FLASH_ATTR setup();
    void ICACHE_FLASH_ATTR loop();
};

#endif // __TP_SERVICE_H__
#ifndef __TP_SERVICE_H__
#define __TP_SERVICE_H__

#define ICACHE_FLASH_ATTR

#include "lvgl.h"

class tp_service
{
private:
    friend class display_service;
    friend class io_service;
    // friend class tp_service;

public:
    tp_service();
    ~tp_service();

    void ICACHE_FLASH_ATTR setup();
    void ICACHE_FLASH_ATTR loop();

    void ICACHE_FLASH_ATTR lv_no_sleep(uint32_t);
};

#endif // __TP_SERVICE_H__
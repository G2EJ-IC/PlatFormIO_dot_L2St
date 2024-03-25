#include <Arduino.h>
#include "display_service.h"
#include "config.h"
#include "tp_service.h"
#include "DateTime_AIoT.h"
#include "io_service.h"

dhms_AIoT DateTimeAhora;       // load DateTime
io_service ioAhora;            // load IO control service

tp_service::tp_service() {}
tp_service::~tp_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR tp_service::setup()
{
    lv_task_handler();
    pinMode(PIN_BL, OUTPUT);
} // end tp setup

void ICACHE_FLASH_ATTR tp_service::loop()
{
    
} // end tp loop

void ICACHE_FLASH_ATTR tp_service::lv_no_sleep(uint32_t lv_sleep)
{
    /*Normal operation (no sleep) in < 1 sec inactivity*/
    if (lv_disp_get_inactive_time(NULL) < (1000 * lv_sleep))
    {
        lv_task_handler();
        digitalWrite(PIN_BL, HIGH);
    }
    /*Sleep after 1 sec inactivity*/
    else
    {
        Serial.println();
        // Serial.print(lv_disp_get_inactive_time(NULL));
        uint32_t Ahora = lv_disp_get_inactive_time(NULL);
        String DHMS = DateTimeAhora.DHMS_AIoT((uint64_t)(Ahora));
        Serial.printf("%u mSeg - %s",Ahora, DHMS);
        digitalWrite(PIN_BL, LOW);
        Serial.println();
    }
    //my_delay_ms(5);
}


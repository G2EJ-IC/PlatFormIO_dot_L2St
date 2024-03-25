#include <Arduino.h>
#include "soc/timer_group_struct.h"  //for wdt
#include "soc/timer_group_reg.h"     //for wdt
#include "config.h"
#include "io_service.h"
#include "screens.h"
#include "DateTime_AIoT.h"

dhms_AIoT DateTime;       // load DateTime

io_service::io_service() {}
io_service::~io_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR io_service::setup()
{
  lv_task_handler();
  Serial.begin(115200);
  pinMode(PinLED, OUTPUT);
  ParpadeoLED();
} // end io setup

void ICACHE_FLASH_ATTR io_service::loop()
{
  
} // end io loop

/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void io_service::ParpadeoLED(void) {
    digitalWrite(PinLED, !digitalRead(PinLED));
}

///////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void ICACHE_FLASH_ATTR io_service::TestHWM(const char *taskName, uint32_t Ahora)
{
  UBaseType_t stack_HWM = uxTaskGetStackHighWaterMark(nullptr);
  BaseType_t portGCID = xPortGetCoreID();
  uint32_t dispGIT = lv_disp_get_inactive_time(NULL);
  float temperature = temperatureRead();
  int HallEffectSensor = hallRead();
  // String DHMS = DateTime.DHMS_AIoT((uint64_t)Ahora);

  Serial.println("\n================================================================================");
  Serial.printf("(%s).: \n"
              "Tiene un máximo en la Pila (High Water Mark) de.: %u \n"
              "En el núcleo (%u) \n"
              "Timer(%u) \n"
              "Temperatura (%.2f°C) \n"
              "Ahora (%u mSeg) \n"
              "Hall Effect Sensor (%i)", 
              taskName, stack_HWM, portGCID, dispGIT, temperature, Ahora, HallEffectSensor);
  Serial.println("\n================================================================================");
}

void ICACHE_FLASH_ATTR io_service::feedTheDog(void)
{
  // feed dog 0
  TIMERG0.wdt_wprotect=TIMG_WDT_WKEY_VALUE; // write enable
  TIMERG0.wdt_feed=1;                       // feed dog
  TIMERG0.wdt_wprotect=0;                   // write protect
  // feed dog 1
  TIMERG1.wdt_wprotect=TIMG_WDT_WKEY_VALUE; // write enable
  TIMERG1.wdt_feed=1;                       // feed dog
  TIMERG1.wdt_wprotect=0;                   // write protect
}

void ICACHE_FLASH_ATTR io_service::memoria_ESP(void)
{
  Serial.println("\n\n\n");
  Serial.println("\n================================================================================");
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Min Free heap: %d", ESP.getMinFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  log_d("Min Free PSRAM: %d", ESP.getMinFreePsram());
  log_d("Total Flash: %d", ESP.getFlashChipSize());
  log_d("Free Flash: %d", ESP.getFreeSketchSpace());
  Serial.println("\n================================================================================");
  Serial.println("\n\n\n");
}

void ICACHE_FLASH_ATTR io_service::cronometro(uint32_t Ahora)
{
    String DHMS = DateTime.DHMS_AIoT((uint64_t)(Ahora));
    lv_label_set_text(objects.label_dhms_1, String(DHMS).c_str());
    lv_label_set_text(objects.label_dhms_2, String(DHMS).c_str());
    lv_label_set_text(objects.label_dhms_3, String(DHMS).c_str());
}

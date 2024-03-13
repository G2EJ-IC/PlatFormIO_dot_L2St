#include <lvgl.h>
#include "LovyanGFX_Class_ILI9488.h"
#include <ui.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <ConectarWiFi_AIoT.h>
#include "display_service.h"
#include "io_service.h"

#define LVGL_REFRESH_TIME (5u)      // 5 milliseconds
#define PinLED  2 // LED_BUILTIN
static LGFX tft;

TaskHandle_t Task1 = NULL;
TaskHandle_t Task2 = NULL;
TaskHandle_t Task3 = NULL;
SemaphoreHandle_t cuentaMutex;

io_service io;           // load IO control service
display_service display; // load display service

//************************************************************************************************
inline void loop_Task1(void);
inline void loop_Task2(void);
inline void loop_Task3(void);
//************************************************************************************************
void loop1(void *);
void loop2(void *);
void loop3(void *);
//************************************************************************************************
void StatusWiFi_AIoT(void);
void TestHwm(const char *);
//************************************************************************************************

#define LVGL_REFRESH_TIME (5u) // 5 milliseconds
#define PinLED 2               // LED_BUILTIN

unsigned long asyncDelay0 = 0;
unsigned long asyncDelay1 = 0;
unsigned long asyncDelay2 = 0;
unsigned long asyncDelay3 = 0;
int delayLength = 5000;
static uint32_t lvgl_refresh_timestamp = 5u;

// Temporizador para apagar la pantalla después de un minuto de inactividad
lv_timer_t *screen_off_timer;

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf) {
  Serial.printf(buf);
  Serial.flush();
}
#endif

void setup() {
  Serial.begin(115200);
  pinMode(PinLED, OUTPUT);
  digitalWrite(PinLED, !digitalRead(PinLED));
  WiFi.mode(WIFI_STA);
  /************************************FreeRTOS*******************************************/
  BaseType_t taskCreationResult;  
  taskCreationResult = xTaskCreatePinnedToCore(
      loop1,
      "Task_1",
      10000,
      NULL,
      1,
      &Task1,
      1);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task1");
    while (true)
      ;
  }
  taskCreationResult = xTaskCreatePinnedToCore(
      loop2,
      "Task_2",
      10000,
      NULL,
      1,
      &Task2,
      1);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task2");
    while (true)
      ;
  }
  taskCreationResult = xTaskCreatePinnedToCore(
      loop3,
      "Task_3",
      10000,
      NULL,
      1,
      &Task3,
      0);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task3");
    while (true)
      ;
  }
  cuentaMutex = xSemaphoreCreateMutex();
  if (cuentaMutex == NULL)
  {
    Serial.println("Error al crear semáforo");
    while (true)
      ;
  }
  /************************************End FreeRTOS***************************************/
}

void loop()
{
  delay(delayLength);
  digitalWrite(PinLED, !digitalRead(PinLED));

  Serial.println("================================================================================");
  TestHwm("loop");
  Serial.println(".::========== En núcleo -> " + String(xPortGetCoreID()) + " ==========::.");
}
//************************************************************************************************
inline void loop_Task1(void)
{
  io.loop();
}
inline void loop_Task2(void)
{
  display.loop();
}
inline void loop_Task3(void)
{
  StatusWiFi_AIoT();
}
//************************************************************************************************
void loop1(void *parameter)
{
  io.setup();
  for (;;)
  {
    loop_Task1();
    if (millis() > asyncDelay1)
    {
      asyncDelay1 += delayLength;
      Serial.println("================================================================================");
      TestHwm("loop1");
      Serial.println(".::========== En núcleo -> " + String(xPortGetCoreID()) + " ==========::.");
    }
  }
}
void loop2(void *parameter)
{
  display.setup();
  for (;;)
  {
    loop_Task2();
    if (millis() > asyncDelay2)
    {
      asyncDelay2 += delayLength;
      Serial.println("================================================================================");
      TestHwm("loop2");
      Serial.println(".::========== En núcleo -> " + String(xPortGetCoreID()) + " ==========::.");
    }
  }
}

void loop3(void *parameter)
{
  for (;;)
  {
    vTaskDelay(pdMS_TO_TICKS(5000));
    loop_Task3();
    Serial.println("================================================================================");
    TestHwm("loop3");
    Serial.println(".::========== En núcleo -> " + String(xPortGetCoreID()) + " ==========::.");
  }
}
//************************************************************************************************
void StatusWiFi_AIoT() {
    if (WiFi.status() == WL_CONNECTED) {    
    lv_label_set_text(ui_LabSSID, WiFi.SSID().c_str());
    lv_label_set_text(ui_LabIP, WiFi.localIP().toString().c_str());
    lv_label_set_text(ui_LabDNS, WiFi.dnsIP().toString().c_str());
    lv_label_set_text(ui_LabMAC, WiFi.macAddress().c_str());		
    lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtConectado1, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else {
    lv_label_set_text(ui_LabSSID, "xx.xx.xx.xx");
    lv_label_set_text(ui_LabIP, "xx.xx.xx.xx");
    lv_label_set_text(ui_LabDNS, "xx.xx.xx.xx");
    lv_label_set_text(ui_LabMAC, "xx:xx:xx:xx:xx:xx");
    lv_obj_set_style_bg_color(ui_BtConectado, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtConectado1, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
  }
}

void TestHwm(const char *taskName) {
  int stack_hwm_temp = uxTaskGetStackHighWaterMark(nullptr);
  Serial.println(" ");
  Serial.printf("%s Tiene un máximo en la Pila (High Water Mark) de.: %u\n",taskName, stack_hwm_temp);
}
//************************************************************************************************
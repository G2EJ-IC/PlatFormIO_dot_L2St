#include <lvgl.h>
#include "ClassILI9488.h"
#include <ui.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <ConectarWiFi_IoT.h>

#define LVGL_REFRESH_TIME (5u)      // 5 milliseconds
#define PinLED  2 // LED_BUILTIN
static LGFX tft;

TaskHandle_t Task2, Task3;
SemaphoreHandle_t cuentaMutex;

unsigned long asyncDelay1 = 0;
unsigned long asyncDelay2 = 0;
int delayLength = 5000;
static uint32_t lvgl_refresh_timestamp = 5u;

// Temporizador para apagar la pantalla después de un minuto de inactividad
lv_timer_t *screen_off_timer;

/*Change to your screen resolution*/
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;
static const uint16_t N = 20u; // N = {10, 12, 16, 20, 24, 25, 32}

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / N];
// static lv_color_t buf[screenWidth * screenHeight / 10];
// static lv_color_t buf[screenWidth * 10];

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf) {
  Serial.printf(buf);
  Serial.flush();
}
#endif

//************************************************************************************************
void loop2(void *);
void loop3(void *);
void StatusWiFi_AIoT();
void TestHwm(const char *);
//************************************************************************************************

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)&color_p->full, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX = 0, touchY = 0;

  // bool touched = false;//tft.getTouch(&touchX, &touchY, 600);
  bool touched = tft.getTouch(&touchX, &touchY, 0);

  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
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

void setup() {
  Serial.begin(115200); /* prepare for possible serial debug */
  pinMode(PinLED, OUTPUT);
  WiFi.mode(WIFI_STA);

  /************************************FreeRTOS*******************************************/
  BaseType_t taskCreationResult;
  taskCreationResult = xTaskCreatePinnedToCore(
                        loop2, 
                        "Task_2", 
                        9216, 
                        NULL, 
                        1, 
                        &Task2, 
                        0);
  if (taskCreationResult != pdPASS) {
    Serial.println("Error al crear Task2");
    while (true);
  }
  taskCreationResult = xTaskCreatePinnedToCore(
                        loop3, 
                        "Task_3", 
                        4096, 
                        NULL, 
                        1, 
                        &Task3, 
                        0);
  if (taskCreationResult != pdPASS) {
    Serial.println("Error al crear Task3");
    while (true);
  }
  cuentaMutex = xSemaphoreCreateMutex();
  if (cuentaMutex == NULL) {
    Serial.println("Error al crear semáforo");
    while (true);
  }
  /***************************************************************************************/

  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");

  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

  tft.begin();        /* TFT init */
  tft.setRotation(3); /* Landscape orientation, flipped */

  //************************************************************************************************
  //tft.setBrightness(255);
  //uint16_t calData[] = { 120, 3120, 170, 170, 4880, 3030, 4770, 50};
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

void loop() {
  delay(5000);
  Serial.println("================================================================================");
  TestHwm("loop");
  Serial.println(".:: En núcleo -> " +  String(xPortGetCoreID()) + " ::.");
}
//************************************************************************************************
void loop2(void *parameter) {
  for(;;){    
    vTaskDelay(pdMS_TO_TICKS(5000));
    StatusWiFi_AIoT();
    Serial.println("================================================================================");
    TestHwm("loop2");
    Serial.println(".:: En núcleo -> " +  String(xPortGetCoreID()) + " ::.");
  }
}
void loop3(void *parameter) {
  for(;;){    
    vTaskDelay(pdMS_TO_TICKS(5));
    lv_timer_handler();
    if(millis() > asyncDelay2) {
      digitalWrite(PinLED, !digitalRead(PinLED));
      asyncDelay2+=delayLength;      
      Serial.println("================================================================================");
      TestHwm("loop3");
      Serial.println(".:: En núcleo -> " +  String(xPortGetCoreID()) + " ::.");
    }
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
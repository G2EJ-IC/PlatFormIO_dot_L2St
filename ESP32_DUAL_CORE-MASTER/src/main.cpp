#include <Arduino.h>

TaskHandle_t Task2, Task3;
int cuenta = 0;
SemaphoreHandle_t cuentaMutex;

void loop2(void *);
void loop3(void *);
void TestHwm(const char *);

void setup() {

  Serial.begin(115200);

  BaseType_t taskCreationResult;

  taskCreationResult = xTaskCreatePinnedToCore(
                        loop2, 
                        "Task_2", 
                        10000, 
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
                        10000, 
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
}

void loop() {
  Serial.println("\t\t\t En núcleo -> " +  String(xPortGetCoreID()));
  Serial.println("\t\t\t Loop uno (1) - 🤯🤯🤯");
  delay(1111);
  cuenta++;
  Serial.println("desde loop -> " + String(cuenta));
  Serial.println("================================================================================");
  TestHwm("loop");  
  Serial.println("================================================================================");
}

void loop2(void *parameter){
  for(;;){
    Serial.println("\t\t\t En núcleo -> " +  String(xPortGetCoreID()));
    Serial.println("\t\t\t Loop dos (2) - 🤯🤯🤯");
    vTaskDelay(pdMS_TO_TICKS(2222));
    // delay(100);
    cuenta++;
    Serial.println("desde loop 2 -> " + String(cuenta));
    Serial.println("================================================================================");
    TestHwm("loop2");
    Serial.println("================================================================================");
  }
}

void loop3(void *parameter){
  for(;;){
    Serial.println("\t\t\t En núcleo -> " +  String(xPortGetCoreID()));
    Serial.println("\t\t\t Loop tres (3) - 🤯🤯🤯");
    vTaskDelay(pdMS_TO_TICKS(3333));
    // delay(2000);
    cuenta++;
    Serial.println("desde loop 3 -> " + String(cuenta));
    Serial.println("================================================================================");
    TestHwm("loop3");
    Serial.println("================================================================================");
  }
}

void TestHwm(const char *taskName) {
  int stack_hwm_temp = uxTaskGetStackHighWaterMark(nullptr);
  Serial.println(" ");
  Serial.printf("%s Tiene un máximo en la Pila (High Water Mark) de.: %u\n",taskName, stack_hwm_temp);
}

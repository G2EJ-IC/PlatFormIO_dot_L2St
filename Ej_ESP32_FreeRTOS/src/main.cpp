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
  delay(1111);
  Serial.println("\t\t\t En núcleo -> " +  String(xPortGetCoreID()));
  Serial.println("\t\t\t Loop uno (1) - 🤯🤯🤯");
  cuenta++;
  Serial.println("================================================================================");
  Serial.println("desde loop -> " + String(cuenta));
  TestHwm("loop");  
}

void loop2(void *parameter){
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(2222));
    Serial.println("\t\t\t En núcleo -> " +  String(xPortGetCoreID()));
    Serial.println("\t\t\t Loop dos (2) - 🤯🤯🤯");
    cuenta++;
    Serial.println("================================================================================");
    Serial.println("desde loop 2 -> " + String(cuenta));
    TestHwm("loop2");
  }
}

void loop3(void *parameter){
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(3333));
    Serial.println("\t\t\t En núcleo -> " +  String(xPortGetCoreID()));
    Serial.println("\t\t\t Loop tres (3) - 🤯🤯🤯");    
    cuenta++;
    Serial.println("================================================================================");
    Serial.println("desde loop 3 -> " + String(cuenta));
    TestHwm("loop3");
  }
}

void TestHwm(const char *taskName) {
  int stack_hwm_temp = uxTaskGetStackHighWaterMark(nullptr);
  Serial.println("\n================================================================================\n");
  Serial.printf("%s Tiene un máximo en la Pila (High Water Mark) de.: %u\n", taskName, stack_hwm_temp);
  Serial.println("En núcleo -> " + String(xPortGetCoreID()));
  Serial.println("\n================================================================================\n");
}

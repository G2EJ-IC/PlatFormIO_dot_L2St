#include <Arduino.h>

TaskHandle_t Task2, Task3;
int cuenta = 0;
SemaphoreHandle_t cuentaMutex;

// define two tasks for Blink & AnalogRead
void TaskLoop2(void *);
void TaskLoop3(void *);

void TestHwm(const char *);

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);

  BaseType_t taskCreationResult;

  taskCreationResult = xTaskCreatePinnedToCore(
                        TaskLoop2, 
                        "Look_2", 
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
                        TaskLoop3, 
                        "Look_3", 
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
  // Empty. Things are done in Tasks. 
}

void TaskLoop2(void *pvParameters){
  (void) pvParameters;
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

void TaskLoop3(void *pvParameters){
  (void) pvParameters;
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

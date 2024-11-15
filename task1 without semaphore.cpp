//omar ahmed mostafa - 120210131 



#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

// Define the tick period in milliseconds
#define portTICK_PERIOD_MS (1000 / configTICK_RATE_HZ)

void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while (1) {
    digitalWrite(8, !digitalRead(8)); 
    vTaskDelay(500 / portTICK_PERIOD_MS); 
  }
}

void TaskBlink2(void *pvParameters) {
  pinMode(13, OUTPUT);

  while (1) {
    digitalWrite(13, !digitalRead(13)); 
    vTaskDelay(1000 / portTICK_PERIOD_MS); 
  }
}

void setup() {
  // Create two tasks for blinking LEDs
  xTaskCreate(TaskBlink1, "Blink1", 128, NULL, 1, NULL);
  xTaskCreate(TaskBlink2, "Blink2", 128, NULL, 1, NULL);

  // Start the FreeRTOS scheduler
  vTaskStartScheduler();
}

void loop() {
  // Empty loop; tasks are managed by FreeRTOS
}

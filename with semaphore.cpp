//omar ahmed mostafa - 120210131 

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

volatile bool semaphore = true;

void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while (1) {
    if (semaphore) {
      semaphore = false;
      digitalWrite(8, !digitalRead(8));
      vTaskDelay(100 / portTICK_PERIOD_MS);
      semaphore = true;
      vTaskDelay(400 / portTICK_PERIOD_MS);
    } else {
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }
}

void TaskBlink2(void *pvParameters) {
  pinMode(13, OUTPUT);

  while (1) {
    if (semaphore) {
      semaphore = false;
      digitalWrite(13, !digitalRead(13));
      vTaskDelay(200 / portTICK_PERIOD_MS);
      semaphore = true;
      vTaskDelay(800 / portTICK_PERIOD_MS);
    } else {
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }
}

void setup() {
  xTaskCreate(TaskBlink1, "Blink1", 128, NULL, 2, NULL);
  xTaskCreate(TaskBlink2, "Blink2", 128, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop() {
}

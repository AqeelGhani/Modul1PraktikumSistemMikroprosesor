#include <Arduino.h>
#include "soc/gpio_reg.h"
#include "driver/gpio.h"

#define INPUT_1 25
#define OUTPUT_1 22

void setup(){
    pinMode(INPUT_1, INPUT_PULLUP);
    REG_WRITE(GPIO_ENABLE_REG, REG_READ(GPIO_ENABLE_REG) | (1 << OUTPUT_1));
    Serial.begin(115200);
    Serial.println("ESP32 Started");
}

void loop() {
  uint32_t gpio_in = REG_READ(GPIO_IN_REG);
  bool input1 = (gpio_in >> INPUT_1) & 0x1;

  if (input1) {
    REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << OUTPUT_1));
  } else {
    REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << OUTPUT_1));
  }
}
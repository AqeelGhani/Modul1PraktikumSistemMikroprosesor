#include "soc/gpio_reg.h"
#include "driver/gpio.h"
#include <Arduino.h>

#define LED_PIN 22

void setup(){
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    Serial.println("ESP32 Register-based LED Blink Started");
    setCpuFrequencyMhz(240);
}

void loop(){
    REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << LED_PIN));
    REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << LED_PIN));
}
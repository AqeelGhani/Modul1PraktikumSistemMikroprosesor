#include "soc/gpio_reg.h"
#include "driver/gpio.h"
#include <Arduino.h>

#define LED_PIN 2 // Built-in LED on most ESP32 boards
#define BLINK_DELAY_MS 500 // 500ms on + 500ms off = 1Hz
void setup() {
 // Configure GPIO pin as output using register access
 // Enable the GPIO pin in the output enable register
 REG_WRITE(GPIO_ENABLE_REG, REG_READ(GPIO_ENABLE_REG) | (1 << LED_PIN));
 
 // Set pin function to GPIO (not special function)
 PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[LED_PIN], PIN_FUNC_GPIO);
 
//  // Optional: Set pin to push-pull mode (default, but explicit)
//  REG_SET_BIT(GPIO_PIN_REG[LED_PIN], GPIO_PIN_PAD_DRIVER);
 
 Serial.begin(115200);
 Serial.println("ESP32 Register-based LED Blink Started");
}
void loop() {
 // Turn LED ON - Set the bit high using register access
 REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << LED_PIN));
 Serial.println("LED ON");
 delay(BLINK_DELAY_MS);
 
 // Turn LED OFF - Clear the bit using register access
 REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << LED_PIN));
 Serial.println("LED OFF");
 delay(BLINK_DELAY_MS);
}

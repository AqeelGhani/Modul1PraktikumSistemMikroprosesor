#include <Arduino.h>

#define LED_PIN 22

void setup(){
    pinMode(LED_PIN, OUTPUT);
}

void lopp(){
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN, LOW);
}
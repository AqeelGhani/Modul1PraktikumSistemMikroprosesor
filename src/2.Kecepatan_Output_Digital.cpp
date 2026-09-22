#include <Arduino.h>

#define LED_BUILTIN 22

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}

void lopp(){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
}
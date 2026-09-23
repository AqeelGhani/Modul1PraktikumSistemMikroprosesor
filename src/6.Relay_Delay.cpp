#include <Arduino.h>

#define Relay_Read 25
#define Relay_Write 22

unsigned long start_time = 0 , stop_time = 0;
unsigned short On=0;

void setup(){
    pinMode(Relay_Read, INPUT_PULLUP);
    pinMode(Relay_Write, OUTPUT);
    Serial.begin(115200);
    Serial.println("ESP32 Started");
}

void loop(){
    if (On && digitalRead(Relay_Read)){
        stop_time = millis();
        Serial.print("Rising Delay : ");
        Serial.print(stop_time-start_time);
        Serial.println(" ms");
        On = 0;
        digitalWrite(Relay_Write, LOW);
        start_time = millis();
    } else if (!On && !digitalRead(Relay_Read)){
        stop_time = millis();
        Serial.print("Falling Delay : ");
        Serial.print(stop_time-start_time);
        Serial.println(" ms");
        On = 1;
        digitalWrite(Relay_Write, HIGH);
        start_time = millis();
    }
}
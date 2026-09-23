#include <Arduino.h>

#define Relay_Read 25
#define Relay_Write 22

unsigned long start_time, stop_time;
unsigned short read=0;

void setup(){
    pinMode(Relay_Read, INPUT_PULLUP);
    pinMode(Relay_Write, OUTPUT);
    Serial.begin(115200);
    Serial.println("ESP32 Started");
}

void loop(){
    if (read && digitalRead(Relay_Read)){
        stop_time = millis();
        Serial.print("Delay : ");
        Serial.print(stop_time-start_time);
        Serial.println(" ms");
        read = 0;
        digitalWrite(Relay_Write, LOW);
    } else if (!read){
        read = 1;
        digitalWrite(Relay_Write, HIGH);
        start_time = millis();
    }
}
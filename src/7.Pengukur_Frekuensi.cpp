#include <Arduino.h>

#define input1 25

int counter = 0;

void IRAM_ATTR count_interup();

void setup(){
    pinMode(input1, INPUT);
    Serial.begin(115200);
    Serial.println("ESP32 Started");
    attachInterrupt(digitalPinToInterrupt(input1), count_interup, RISING);
}

void loop(){
    delay(1000);

    Serial.print("Frekuensi ");
    Serial.print(counter);
    Serial.println("Hz");

    counter = 0;
}

void IRAM_ATTR count_interup(){
    counter++;
}

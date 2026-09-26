#include <Arduino.h>

#define RELAY_PIN 22
#define FEEDBACK_PIN 25

const unsigned long HALF_PERIOD = 500;
const unsigned long TIMEOUT_MS = 200;

void waktuRespon(uint8_t targetState) {
  bool validasiAwal = (digitalRead(FEEDBACK_PIN) != targetState);
  
  unsigned long startTime = millis();
  digitalWrite(RELAY_PIN, targetState);
  
  bool isTimeout = false;
  
  while (digitalRead(FEEDBACK_PIN) != targetState) {
    if (millis() - startTime >= TIMEOUT_MS) {
      isTimeout = true;
      break;
    }
  }
  
  unsigned long durasi = millis() - startTime;
  
  if (targetState == HIGH) {
    Serial.print("Respon HIGH  : ");
  } else {
    Serial.print("Respon LOW : ");
  }
  
  if (!validasiAwal) {
    Serial.println("GAGAL - State awal tidak sesuai.");
  } else if (isTimeout) {
    Serial.println("TIMEOUT - Relay tidak merespons.");
  } else {
    Serial.print(durasi);
    Serial.println(" ms");
  }
  while (millis() - startTime < HALF_PERIOD) {
    delay(1);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  pinMode(FEEDBACK_PIN, INPUT_PULLDOWN);
  Serial.println("ESP32 Started");
  delay(1000);
}

void loop() {
  waktuRespon(HIGH);
  waktuRespon(LOW);
  
}
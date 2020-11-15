#include <SoftwareSerial.h>

SoftwareSerial RFID(10, 11); // RX

void setup() {
  Serial.begin(9600);
  RFID.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() { // run over and over
  if (RFID.available()) {
    String Key = RFID.readString();
    Serial.println(Key);
    if (Key == "09008110D941") {
      digitalWrite(13, HIGH);
      delay(2000);
      digitalWrite(13, LOW);
    }
    else {
      digitalWrite(13, LOW);
    }
  }
}

#include <Wire.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

#define ledPin 12

String data = "2";

void setup() {
  Wire.begin();
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
}

byte x = 0;
byte flickUp = 1;

void loop() {
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)){
    data = (char*)buf;
    Serial.println(data);
  }
if(data.startsWith("0")){
  digitalWrite(ledPin, HIGH);
  Wire.beginTransmission(8);
  Wire.write(x);
  Wire.endTransmission();
  delay(2000);
  digitalWrite(ledPin, LOW);
  data = "2";
}
if(data.startsWith("1")){
  digitalWrite(ledPin, HIGH);
  Wire.beginTransmission(8);
  Wire.write(flickUp);
  Wire.endTransmission();
  delay(2000);
  digitalWrite(ledPin, LOW);
  data ="2";
}
}




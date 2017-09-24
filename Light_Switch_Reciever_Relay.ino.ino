#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

#define ledPin 12
#define relay 7

String data = "2";

void setup() {
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
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
  digitalWrite(relay, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  data = "2";
}
if(data.startsWith("1")){
  digitalWrite(ledPin, HIGH);
  digitalWrite(relay, LOW);
  delay(2000);
  digitalWrite(ledPin, LOW);
  data ="2";
}
}



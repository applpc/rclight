#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

#define buttonPin1 4
#define buttonPin2 5
#define ledPin1 8
#define ledPin2 9

bool buttonPress1 = false;
bool buttonPress2 = false;
int buttonState1 = 0;
int buttonState2 = 0;

void setup(){
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
   pinMode(buttonPin1, INPUT_PULLUP);
   pinMode(buttonPin2, INPUT_PULLUP);
   pinMode(ledPin1, OUTPUT);  
   pinMode(ledPin2, OUTPUT);  
   digitalWrite(ledPin1, LOW); 
   digitalWrite(ledPin2, LOW);    
 }

void loop(){
  const char *flickDown = "0";
  const char *flickUp= "1";
  
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  
  if(buttonState1 == LOW){
    buttonPress1 = true;
    digitalWrite(ledPin1, HIGH);
  }
  
  if(buttonPress1 == true){
     driver.send((uint8_t *)flickDown, strlen(flickDown));
     driver.waitPacketSent();
     delay(1000);   //Wait for 1 second
     buttonPress1 = false;
     digitalWrite(ledPin1, LOW);
  }
  if(buttonState2 == LOW){
    buttonPress2 = true;
    digitalWrite(ledPin2, HIGH);
  }
  if(buttonPress2 == true){
     driver.send((uint8_t *)flickUp, strlen(flickUp));
     driver.waitPacketSent();
     delay(1000);   //Wait for 1 second
     buttonPress2 = false;
     digitalWrite(ledPin2, LOW);
  }
 }

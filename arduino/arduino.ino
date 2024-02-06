#include <Wire.h>
const int buttonPin = 2;  
int buttonState = 0;      
int lastButtonState = 0;  
int pressCount = 0;       

void setup() {
 pinMode(buttonPin, INPUT);
 Wire.begin(8);         
 Wire.onRequest(requestEvent); 
 Serial.begin(9600);           
 }

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      pressCount++;
      Serial.print("Count: ");
      Serial.println(pressCount);
    }
    delay(500);
  }
  lastButtonState = buttonState;
}
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      
    Serial.print(c);           
  }
 Serial.println();        
}

void requestEvent() {
  String pressCountString = String(pressCount); 
  Wire.write(pressCountString.c_str()); 
}
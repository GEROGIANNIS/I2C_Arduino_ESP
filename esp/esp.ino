#include <Wire.h>

void setup() {
 Serial.begin(9600); 
  Wire.begin(5, 4); 
}

void loop() {
 Wire.requestFrom(8, 13);
 while(Wire.available()){
  char c = Wire.read();
  //char num = c.toInt();
  Serial.print(c);
 }
 Serial.println();
 delay(1000);
}
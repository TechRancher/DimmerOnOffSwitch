/*
  Push button dimmer LED. To learn more about this project, chech out my readME.adoc
*/
// Header
// Define
// Variables
int btnAPin = 2;
int btnBPin = 5;
int LEDPin = 9;
int buzzPin = 4;
int dT = 30;
int dT1 = 250;
int btnA;
int btnB;
int LEDVal;
int j;
// Functions

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(btnAPin, INPUT_PULLUP);
  pinMode(btnBPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  btnA = digitalRead(btnAPin);
  btnB = digitalRead(btnBPin);
  LEDVal = analogRead(LEDPin);

  if (btnA == 0){
    j = j+5;
  }
  if(btnB == 0){
    j = j-5;
  }

  if(j > 255){
    j = 255;
    digitalWrite(buzzPin, HIGH);
    delay(dT1);
    digitalWrite(buzzPin, LOW);
  }
  
  if(j < 0){
    j = 0;
    digitalWrite(buzzPin, HIGH);
    delay(dT1);
    digitalWrite(buzzPin, LOW);
  }
  
  analogWrite(LEDPin, j);
  delay(dT);
}

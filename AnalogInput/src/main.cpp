#include <Arduino.h>
void setup() {
  // I, Robert Zaranek, 001161598 certify that this material is my original work.
  // No other person's work has been used without due acknowledgement.
  
  // configure the USB serial monitor
  Serial.begin(115200);
}
void loop() {
  int iVal;
  double calcTemp;
  String tempJudgement;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  // calculate tempturature
  calcTemp = (iVal / 1024.0) * 50;

  // make judgement based on tempurature calculation
  if (calcTemp < 10) {
    tempJudgement = "Cold!";
  } else if (calcTemp >= 10 && calcTemp <= 15) {
    tempJudgement = "Cool";
  } else if (calcTemp >= 15 && calcTemp <= 25) {
    tempJudgement = "Perfect";
  } else if (calcTemp >= 25 && calcTemp <= 30) {
    tempJudgement = "Warm";
  } else if (calcTemp >= 30 && calcTemp <= 35) {
    tempJudgement = "Hot";
  } else if (calcTemp > 35) {
    tempJudgement = "Too Hot!";
  }
  

  // print value to the USB port
  Serial.println(
    "Digitized Value of " + String(iVal) + 
    " is equivalent to a tempurature of " + String(calcTemp) + 
    " deg. C, which is " + String(tempJudgement)
    );

  // wait 2 seconds (2000 ms)
  delay(2000);
}
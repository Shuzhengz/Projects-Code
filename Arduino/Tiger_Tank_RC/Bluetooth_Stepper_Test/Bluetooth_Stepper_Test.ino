#include <Stepper.h>

int ledPin = 13;
int pinRX = 0;
int pinTX = 1;
String val ="";
const int stepsPerRevolution = 1500;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    myStepper.setSpeed(20);
    
}

void loop()
{
    while(Serial.available()>0)
    {
      val += char(Serial.read());
      delay(1);
    }
     if(val=="clockwise")
     {
      myStepper.step(stepsPerRevolution);
  delay(500);
     }
     if(val=="cclockwise")
     {
      myStepper.step(-stepsPerRevolution);
  delay(500);
     }
     if(val=="End")
     {
     }
     
}

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

void setup() {
  // put your setup code here, to run once:
pinMode(1,INPUT);
pinMode(0,INPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,INPUT);
pinMode(5,OUTPUT);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if ((digitalRead(5))==(HIGH));
  digitalWrite(4,HIGH);
}

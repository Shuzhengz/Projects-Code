int ledPin = 13;
int pinRX = 0;
int pinTX = 1;
String val ="";

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    while(Serial.available()>0)
    {
      val += char(Serial.read());
      delay(2);
    }
    if(val=="Start")
     {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin, LOW);
      delay(1000);
      Serial.println("Bluetooth");
     }
     if(val=="End")
     {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin, LOW);
     }
     
}

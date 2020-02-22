const int ledPin = 13;
const int pinRX = 0;
const int pinTX = 1;
String val ="";
const int lf = 2;
const int lb = 3;
const int rf = 4;
const int rb = 5;

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(6, OUTPUT);
    digitalWrite(ledPin, LOW);
    digitalWrite(6, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
}

void loop()
{
    while(Serial.available()>0)
    {
      val = "";
      val += char(Serial.read());
      delay(2);
    }
    if(val=="start")
     {
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      Serial.println("Connected");
      Serial.println(val);
     }
     if(val=="f")
      {
        while(val!="fend")
        {
          digitalWrite(lf, HIGH);
          digitalWrite(rf, HIGH);
        }
        digitalWrite(lf, LOW);
        digitalWrite(rf, LOW);
      }
     if(val=="b")
     {
      while(val!="bend")
      {
        digitalWrite(lb, HIGH);
        digitalWrite(rb, HIGH);
      }
      digitalWrite(lb, LOW);
      digitalWrite(rb, LOW);
     }
     if(val=="l")
     {
      while(val!="lend")
      {
        digitalWrite(lb, HIGH);
        digitalWrite(rf, HIGH);
      }
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
     }
     if(val=="r")
     {
      while(val!="rend")
      {
        digitalWrite(lf, HIGH);
        digitalWrite(rb, HIGH);
      }
      digitalWrite(lf, LOW);
      digitalWrite(rb, LOW);
     }
     if(val=="fire")
     {
      digitalWrite(lb, HIGH);
      digitalWrite(rb, HIGH);
      delay(250);
      digitalWrite(lb, LOW);
      digitalWrite(rb, LOW);
      digitalWrite(lf, HIGH);
      digitalWrite(rf, HIGH);
      delay(200);
      digitalWrite(lf, LOW);
      digitalWrite(rf, LOW);
      Serial.println("Fired!");
     }
     if(val=="fi")
     {
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(150);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(150);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(150);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(150);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(150);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(150);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(150);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(150);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(150);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(150);
     }
     
}

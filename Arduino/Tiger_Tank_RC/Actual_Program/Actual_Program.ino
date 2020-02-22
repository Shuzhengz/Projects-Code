const int ledPin = 13;
const int pinRX = 0;
const int pinTX = 1;
const int lf = 2;
const int lb = 3;
const int rf = 4;
const int rb = 5;
String val = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(6, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
}

void loop() {
    while(Serial.available()>0)
    {
      val += char(Serial.read());
      delay(10);
    }
    while(val == "start")
     {
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      Serial.println("Connected");
      Serial.println(val);
      break;
     }
     while(val=="f")
      {
        digitalWrite(lf, HIGH);
        digitalWrite(rf, HIGH);
        delay(50);
        digitalWrite(lf, LOW);
        digitalWrite(rf, LOW);
        Serial.println("Done (foward)");
        Serial.println(val);
        break;
      }
     while(val=="b")
     {
      digitalWrite(lb, HIGH);
      digitalWrite(rb, HIGH);
      delay(50);
      digitalWrite(lb, LOW);
      digitalWrite(rb, LOW);
      Serial.println("Done (backward)");
      Serial.println(val);
      break;
     }
     while(val=="l")
     {
      digitalWrite(lb, HIGH);
      digitalWrite(rf, HIGH);
      delay(50);
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
      Serial.println("Done (left)");
      Serial.println(val);
      break;
     }
     while(val=="r")
     {
      digitalWrite(lf, HIGH);
      digitalWrite(rb, HIGH);
      delay(50);
      digitalWrite(lf, LOW);
      digitalWrite(rb, LOW);
      Serial.println("Done (right)");
      Serial.println(val);
      break;
     }
     while(val=="fire")
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
      Serial.println(val);
      break;
     }
     while(val=="fi")
     {
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(100);
      digitalWrite(ledPin, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6,LOW);
      digitalWrite(ledPin, LOW);
      delay(100);
      Serial.println("Done");
      Serial.println(val);
      break;
     }
  val = "";
}

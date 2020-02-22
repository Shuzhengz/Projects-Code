const int leftForward = 2;
const int leftBackward = 3;

void setup() 
{
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);

}

void loop()
{
  digitalWrite(leftForward , HIGH);
  delay(1000);
  digitalWrite(leftForward , LOW);
  delay(1000);
  digitalWrite(leftBackward , HIGH);
  delay(1000);
  digitalWrite(leftBackward , LOW);
  delay(1000);
 
}

//#define Led 8

void setup()
{
  pinMode(8, OUTPUT);
  //pinMode(Led, OUTPUT);
}

void loop()
{
  digitalWrite(8, HIGH);
  //digitalWrite(Led, HIGH);
  delay(500); 
  digitalWrite(8, LOW);
  //digitalWrite(Led, LOW);
  delay(500); 
}

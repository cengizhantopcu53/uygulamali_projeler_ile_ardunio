#define echopin 6
#define trigpin 7
#define buzzerpin 8

int maxRange=50;
int minRange=0;

void setup()
{
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
}

void loop()
{
  int olcum=mesafe(maxRange,minRange);
  melodi(olcum*10);
}

int mesafe(int maxRange,int minRange)
{
  long duration, distance;
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  duration=pulseIn(echopin,HIGH);
  distance=duration/58.2;
  delay(50);
  
  if (distance>=maxRange || distance <=minRange)
  return 0;
  return distance;
}

int melodi(int dly)
{
  tone(buzzerpin,440);
  delay(dly);
  noTone(buzzerpin);
  delay(dly);
}
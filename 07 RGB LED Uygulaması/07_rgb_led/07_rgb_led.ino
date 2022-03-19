#define redpin 11
#define greenpin 10
#define bluepin 9

#define potpin A0

int potdeger=0;

int reddeger=0;
int greendeger=0;
int bluedeger=0;

void deger_oku() {
  potdeger = analogRead(potpin);
  
  if (potdeger < 341)
  {
    potdeger=(potdeger*3)/4;
    reddeger=255-potdeger;
    greendeger=potdeger;
    bluedeger=0;
  }
  else if (potdeger < 682)
  {
    potdeger=((potdeger-341)*3)/4;
    reddeger=0;
    greendeger=255 - potdeger;
    bluedeger=potdeger;
  }
  else 
  {
    potdeger=((potdeger-683)*3)/4;
    reddeger=potdeger;
    greendeger=0;
    bluedeger=255 - potdeger;
  }
}

void deger_yaz() {
  analogWrite(redpin,255 - reddeger);
  analogWrite(greenpin,255 - greendeger);
  analogWrite(bluepin,255 - bluedeger);
}

void setup()
{
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);
  
  //digitalWrite(redpin,HIGH);
  //digitalWrite(greenpin,LOW);
  //digitalWrite(bluepin,HIGH);
}

void loop()
{
  deger_oku();
  deger_yaz();
}
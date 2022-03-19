#define led 9
#define buzzer 8

#define lm A0

int zaman=100;
int okunan_deger=0;
float sicaklik_gerilim=0;
float sicaklik=0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  okunan_deger=analogRead(lm);
  sicaklik_gerilim=(5000.0/1023.0) * okunan_deger;
  sicaklik=sicaklik_gerilim/10.0;
  
  if (sicaklik>=30){
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(zaman);
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);	
  }
  else{
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
  }
}

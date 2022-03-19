#define Buton 10
#define Led 8

int buton_durumu = 0;

void setup(){
  pinMode(Buton, INPUT);
  pinMode(Led, OUTPUT);
}

void loop(){
  buton_durumu = digitalRead(Buton);
  if(buton_durumu == 1){
  digitalWrite(Led, HIGH);
  }
  else{
  digitalWrite(Led, LOW);
  }
}

/*
#define Buton 10
#define Led 8

void setup(){
  pinMode(Buton, INPUT);
  pinMode(Led, OUTPUT);
}

void loop(){
  if(digitalRead(Buton) == 1)
  digitalWrite(Led, HIGH);
  else
  digitalWrite(Led, LOW);
}
*/

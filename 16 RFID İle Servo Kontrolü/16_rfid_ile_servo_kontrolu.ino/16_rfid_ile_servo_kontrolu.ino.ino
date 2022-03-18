#include <MFRC522.h>
#include <Servo.h>
#include <SPI.h>

int RST_PIN = 9;                          
int SS_PIN = 10;                          
int servoPin = 8;                         

Servo motor;                              
MFRC522 rfid(SS_PIN, RST_PIN);            
byte ID[4] = {218, 5, 185, 37};          

void setup() { 
  motor.attach(servoPin);                 
  Serial.begin(9600);                     
  SPI.begin();                            
  rfid.PCD_Init();                        
}
 
void loop() {

  if ( ! rfid.PICC_IsNewCardPresent())    
    return;

  if ( ! rfid.PICC_ReadCardSerial())      
    return;

  if (rfid.uid.uidByte[0] == ID[0] &&     
    rfid.uid.uidByte[1] == ID[1] && 
    rfid.uid.uidByte[2] == ID[2] && 
    rfid.uid.uidByte[3] == ID[3] ) {
        Serial.println("Kapi acildi");
        ekranaYazdir();
        motor.write(90);                 
        delay(1000);
        motor.write(0);                   
        delay(500);
    }
    else{                                 
      Serial.println("Yetkisiz Kart");
      ekranaYazdir();
    }
  rfid.PICC_HaltA();
}
void ekranaYazdir(){
  Serial.print("ID Numarasi: ");
  for(int sayac = 0; sayac<4; sayac++){
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println(" ");
}

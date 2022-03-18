#include <LiquidCrystal.h>
#include <virtuabotixRTC.h>
 
int CLK_PIN = 6;                                     
int DAT_PIN = 7;                                      
int RST_PIN = 8;                                       
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);
  
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;    
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

void setup() {
   Serial.begin(9600);                                   
   //myRTC.setDS1302Time(10, 11, 01, 4, 31, 12, 2020);     
   lcd.begin(16, 2);
}

void loop() {
 myRTC.updateTime();                                   

 Serial.print("Tarih / Saat: ");                       
 Serial.print(myRTC.dayofmonth);
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);

  lcd.clear();                                          
  lcd.setCursor(0,0);                                   
  lcd.print(myRTC.dayofmonth);                          
  lcd.print("/");
  lcd.print(myRTC.month);                               
  lcd.print("/");
  lcd.print(myRTC.year);                                
  lcd.setCursor(0, 1);                                  
  lcd.print(myRTC.hours);                               
  lcd.print(":");
  lcd.print(myRTC.minutes);                                
  lcd.print(":");
  lcd.print(myRTC.seconds);                             

 delay(1000);                                          
}

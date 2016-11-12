#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  pinMode(1,INPUT);
  pinMode(13,INPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}


void loop() {
lcd.print("HI"); 
  if(digitalRead(10)==HIGH){
   for(int i = 140; i<3600; i+=100){
     tone(9,i);
     Serial.println(i);
     lcd.setCursor(0,1);
     lcd.print(i);
     delay(1000);
     if(digitalRead(10)==LOW){
      noTone(9);
    }

  }
  
  if(digitalRead(13)==HIGH){
    int f = 140;
   // manual();
    Serial.println("hi");
    lcd.setCursor(0,1);
    lcd.print(f);
    
  }

}
}



    




int i ;
int f = 400;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
boolean mode;
int val;
int hert;

void setup(){
  lcd.begin(16, 2);
  pinMode(9,OUTPUT);
  pinMode(13,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);
}


void loop(){
 
  if(digitalRead(13)==HIGH){
   mode=true;
  }else{
    mode=false;
  }
  if(mode==true){
   steps();
  }else if(mode==false){
    mode2();
  }
}

void steps(){
  for(i=100;i<3100;i+=100){
    if(digitalRead(13)==LOW){
      break;
      mode2();
      Serial.print(true);
      
    }
      tone(9,i);
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print("hz");
      delay(1000);
      lcd.clear();
    }
}

void mode2(){
 val = analogRead(1);
 hert = map(val,0,1023,100,3100);
 tone(9,hert);
 lcd.setCursor(0,1);
 lcd.print(hert);
 lcd.print("hz");
 delay(50);
 lcd.clear();  
}



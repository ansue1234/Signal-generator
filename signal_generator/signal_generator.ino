int i ;
int f = 400;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
boolean mode;
void setup(){
  lcd.begin(16, 2);
  pinMode(9,OUTPUT);
  pinMode(13,INPUT);
  pinMode(6,INPUT);
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
   Serial.println("true");
  }else if(mode==false){
    mode2();
  }
}


void steps(){
  for(i=400;i<3000;i+=100){
      tone(9,i);
      lcd.setCursor(0,1);
      lcd.print(i);
      lcd.print("hz");
      delay(500);
      lcd.clear();
    }
}

void mode2(){
  //tone(9,f);
  lcd.setCursor(0,1);
  lcd.print(f);  
  lcd.print("hz");
  
  if(digitalRead(6)==HIGH){
//    f+=100;
//    delay(200);
    lcd.clear();
    lcd.print("LOW");
  }
  if(digitalRead(8)==HIGH){
    //f-=100;
    //delay(200);
    lcd.clear();
    lcd.print("HIGH");
     
  }
}

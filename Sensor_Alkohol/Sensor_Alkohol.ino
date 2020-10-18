#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
int MQ7_LOW = 3;
int YELLOW_LED = 5;
int RED_LED = 4;
void setup (){
  
  pinMode(MQ7_LOW, INPUT_PULLUP);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("SYSTEM PENDETEKSI");
  lcd.setCursor(0,1);
  lcd.print("ALKOHOL");
  lcd.setCursor(0,2);
  lcd.print("TELEKOMUNIKASI PNJ");
  delay (1000);
}

void loop (){
  int MQ7_LOW_READ = digitalRead (MQ7_LOW);
  if(MQ7_LOW_READ == LOW)
  {
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("ALCOHOL DETECTED");
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(20);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("ALCOHOL NOT DETECTED");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    delay(20);
  }
}


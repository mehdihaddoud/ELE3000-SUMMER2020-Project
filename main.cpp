#include <Wire.h>
#include <ds3231.h>
#include <LiquidCrystal_I2C.h>

struct ts t; 

String voice;    
int 
const unsigned short redPin = 2, serrure=3, buzzer=4;
const unsigned short MAXMOT=10;
unsigned short indice[MAXMOT]={0,0,0,0,0,0,0,0,0,0};
uint8_t heures[MAXMOT];
uint8_t minutes[MAXMOT];
uint8_t secondes[MAXMOT];
unsigned short i=0;
unsigned short location=0;
const unsigned char buttonPin=7;
unsigned short buttonState=0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

 void setup() {
  Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  pinMode(redPin, OUTPUT); 
  pinMode(serrure, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin();
  lcd.clear();
  lcd.backlight(); 

  t.hour=18; 
  t.min=41;
  t.sec=00;
  t.mday=25;
  t.mon=12;
  t.year=2019;
 
  DS3231_set(t); 
}


 void loop() {
  
  DS3231_get(&t);
  
  while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  }  
  if (voice.length() > 0) {
    
    Serial.println(voice);
  
    
  if(voice == "*allumer")
  {
    indice[i]=1;
    heures[i]=t.hour;
    minutes[i]=t.min;
    secondes[i]=t.sec;
    i=i+1;
    digitalWrite(redPin,HIGH);
    digitalWrite(serrure,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(redPin,LOW);
    digitalWrite(serrure,LOW);
    digitalWrite(buzzer,LOW);
  }  
  
  else if(voice == "*ouvrir")
    { 
      indice[i]=2;
      heures[i]=t.hour;
      minutes[i]=t.min;
      secondes[i]=t.sec;
      i=i+1;
      digitalWrite(redPin,HIGH);           
      digitalWrite(serrure,HIGH);
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(redPin,LOW);
      digitalWrite(serrure,LOW);
      digitalWrite(buzzer,LOW);
    } 

    else if(voice =="*partir"){
      indice[i]=3;
      heures[i]=t.hour;
      minutes[i]=t.min;
      secondes[i]=t.sec;
      i=i+1;
      digitalWrite(redPin,HIGH);
      digitalWrite(serrure,HIGH);
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(redPin,LOW);
      digitalWrite(serrure,LOW);
      digitalWrite(buzzer,LOW);
      }
  
  

  
voice="";}  

 buttonState=digitalRead(buttonPin);
 delay(20);
  if(buttonState==HIGH){  
    if(location>=i){
      location=0;
      }
   
    if (indice[location]==1){
      lcd.begin();              
      lcd.print("Allumer : ");
      lcd.print(location, DEC);
      lcd.setCursor(0,1);
      lcd.print(heures[location]);
      lcd.print(":");
      lcd.print(minutes[location]);
      lcd.print(":");
      lcd.print(secondes[location]);
      delay(3000);
      lcd.clear();
      location++;
      }
     else if (indice[location]==2){
      lcd.begin();
      lcd.print("Ouvrir : ");
      lcd.print(location, DEC);
      lcd.setCursor(0,1);
      lcd.print(heures[location]);
      lcd.print(":");
      lcd.print(minutes[location]);
      lcd.print(":");
      lcd.print(secondes[location]);
      delay(3000);
      lcd.clear();
      location++;
      }
      else if (indice[location]==3){
      lcd.begin();
      lcd.print("Partir : ");
      lcd.print(location, DEC);
      lcd.setCursor(0,1);
      lcd.print(heures[location]);
      lcd.print(":");
      lcd.print(minutes[location]);
      lcd.print(":");
      lcd.print(secondes[location]);
      delay(3000);
      lcd.clear();
      location++;
      }
      else if (indice[location]==0){
      lcd.print("Libre: ");
      lcd.print(location,DEC);
      lcd.print(" ");
      lcd.print(i, DEC);
      lcd.setCursor(0,1);
      lcd.print(t.sec);
      delay(1000);
      lcd.clear();
      location++;
        }
      while(buttonState==HIGH){
         buttonState=digitalRead(buttonPin);
         delay(20);
        }
  }




}
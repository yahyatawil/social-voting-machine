/*
author  : yahya tawil
licence : http://creativecommons.org/licenses/by-nd/3.0
2011-2012 
beta
*/  
#include <LiquidCrystal.h>
#include <Keypad.h>
//four keys 
const byte ROWS = 2;
const byte COLS = 2;
char keys[ROWS][COLS] = {  {'1','2'},  {'4','5'}  };
byte rowPins[ROWS] = {8,9}; 
byte colPins[COLS] = {10,11}; 


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

char v_user[31];// string to store in it the name of the member will be voted 

byte plus[8]={
 B11111,
 B11111,
 B11011,
 B10001,
 B11011,
 B11111,
 B11111,
 B11111
};

/*
welcom function print some welcoming and guiding messages 
*/
void welcom()
{
 lcd.clear();
   lcd.setCursor(0,0);
  lcd.write("welcom to voting");
  lcd.setCursor(0,1);
  lcd.write("machine!");
  delay(3000);
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.write("stay hold any ");
  lcd.setCursor(0,1);
  lcd.write("key");
  delay(3000); 
}

/*
select function will recive the first letter of the user will be voted 
*/
void select()
{
    lcd.createChar(1,plus);//plus simbol
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write("please enter the ");
    lcd.setCursor(0,1);
    lcd.write("first letter of ");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write("the user you ");
    lcd.setCursor(0,1);
    lcd.write("want to ");
    lcd.write(1);
    lcd.write("him");    
    delay(2000);
    int i=1;
    while (i)
      {
        for(char c='a';c<='z';c++)
        { 
     lcd.clear();
     lcd.write("when arrive");
     lcd.setCursor(0,1);
     lcd.write("press 1,");
     lcd.write(c);
     if(keypad.waitForKey()=='1')
     {i=0;//Serial.write(c);
   break;}}}
}

/*
voting function is for voting process 
*/
void voting()
{
 int j =1;
     lcd.clear();
     lcd.print("press 1 when ");
     lcd.setCursor(0,5);
     lcd.write("arrive");
     delay(3000);
     while(j){
     byte bytesReceived = Serial.readBytesUntil('\0', v_user, 30);
     v_user[bytesReceived] = '\0';
     Serial.flush();
     lcd.clear() ;
     lcd.print(v_user);
     if(keypad.waitForKey()=='1'){Serial.write("1");j=0;break;}
     Serial.write(keypad.waitForKey());
     }
  
}
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
}

void loop() {
  welcom();
  
  if(keypad.getKey())
  {
    select();
     
     voting();
  }
  
}



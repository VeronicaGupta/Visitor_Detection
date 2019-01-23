#include <LiquidCrystal.h>
LiquidCrystal lcd(3,2,4,5,6,7);   //RS / E/ D4/ D5/ D6/ D7

void setup() {
  // put your setup code here, to run once:
pinMode(13,INPUT);//Infrared sensor facing outside of room
pinMode(12,INPUT);//Infrared sensor facing inside of room
pinMode(11,OUTPUT);//light 1
pinMode(10,OUTPUT);//light 2
pinMode(9,OUTPUT);//AC 
pinMode(8,OUTPUT);

lcd.begin(16,2);   //initialisation of 16 * 2 lcd

}
int i,j;
void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(13))
{
  while(digitalRead(12)==0 ); 
  i++;
  while(digitalRead(12)==1 );
}

if(digitalRead(12))
{
  while(digitalRead(13)==0 ); 
  i--;
  while(digitalRead(13)==1 );
}


lcd.setCursor(3,0);
lcd.print("VISITOR ");
lcd.print(i);

if(i>=1)
{
  digitalWrite(11,HIGH);
  digitalWrite(9,HIGH);
  
}

if(i==0)
{
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
}

if(i>=3)
{
  digitalWrite(10,HIGH);
  digitalWrite(8,HIGH);
}

}

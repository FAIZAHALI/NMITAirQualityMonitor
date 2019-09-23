#include <LiquidCrystal.h>
int sensorValue;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{ 
  lcd.begin(16, 2);                         //lcd initialization
  Serial.begin(9600);                            // sets the serial port to 9600 baud i.e 9600 bits per second
 }

 
void loop()
{
  sensorValue = analogRead(0);       // read analog input pin 0
  Serial.print("NMIT AIRQ=");
  Serial.print(sensorValue, DEC);               // prints the value read
  Serial.println(" PPM");
  lcd.setCursor(0,0);
  lcd.print("NMIT AIRQ=");
  lcd.print(sensorValue,DEC);
  lcd.print("PPM");
  lcd.println("       "); 
  lcd.print("  ");
    lcd.setCursor(0,1);
  if(sensorValue<=500)
 {
  lcd.print("Fresh Air");

 }
   else if(sensorValue>500 && sensorValue<=1000)
 {
  
  lcd.print("Poor Air");
 }
    else if(sensorValue>1000)
 {
  
  lcd.print("Hazardous");
 }
  delay(1000);                                    // wait 500ms for next reading
} 


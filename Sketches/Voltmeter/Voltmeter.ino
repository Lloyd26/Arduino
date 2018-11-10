#include "LiquidCrystal.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float input_voltage = 0.0;
float temp=0.0;


void setup()
{
   Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
   lcd.begin(16, 2);       //// set up the LCD's number of columns and rows: 
   lcd.print("Voltmeter");
}
void loop()
{

//Conversion formula for voltage
   
   int analog_value = analogRead(A0);
   input_voltage = (analog_value / 125); 

   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    Serial.print("v = ");
    Serial.println(input_voltage);
    lcd.setCursor(0, 1);
    lcd.print("Voltage = ");
    lcd.print(input_voltage);
    delay(500);
}

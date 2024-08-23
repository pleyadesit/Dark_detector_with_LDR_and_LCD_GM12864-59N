/* A4 --> SDA  /  A5 --> SCL */

#include"lcd_st7567s.h"

lcd_st7567s Lcd;

int analogPin = 7;
int lectura = 0;
int pinLED = 12;
char lectura_string[10];

void setup()
{
  Lcd.Init();
  Lcd.Clear(false);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);

  Lcd.Cursor(1, 1);              // Horizontal x vertical
  Lcd.Display("Light ambient");
  Lcd.Cursor(1, 2);
  Lcd.Display("sensor with LDR");
  delay(800);
  Lcd.Cursor(1, 5);
  Lcd.Display("--> Pleyades IT");
  delay(2000);
  Lcd.Clear(false);
  delay(400);
  Lcd.Cursor(1, 0);
  Lcd.Display("Elements used:");
  delay(700);
  Lcd.Cursor(1, 2);
  Lcd.Display("- Nano clone");
  delay(700);
  Lcd.Cursor(1, 3);
  Lcd.Display("- LCD 128x64 I2C");
  delay(700);
  Lcd.Cursor(1, 4);
  Lcd.Display("- LDR resistor");
  delay(700);
  Lcd.Cursor(1, 5);
  Lcd.Display("- 1k resistor");
  delay(700);
  Lcd.Cursor(1, 6);
  Lcd.Display("- Breadboard");
  delay(2000);
  Lcd.Clear(false);
  delay(400);
  Lcd.Clear(false);
  Lcd.Cursor(1, 1);
  Lcd.Display("Ambient light:");
}

void clear_line()
{
  for(int a=0; a<=115; a++)
  {
    //Lcd.ClearPixel(a,30);
    for(int b=24; b<=30; b++)
    {
      Lcd.ClearPixel(a,b);
    }
  }
}

void loop()
{
  lectura = analogRead(analogPin);
  while (lectura <= 900)
  {
    Lcd.Cursor(1, 3);
    Lcd.Display("LIGHT");
    lectura = analogRead(analogPin);
    if (lectura > 900)
    {
      clear_line();
    }
  }
  while (lectura > 900 && lectura <= 1015)
  {
    Lcd.Cursor(1, 3);
    Lcd.Display("SEMI-DARKNESS");
    lectura = analogRead(analogPin);
    if (lectura <=900 || lectura > 1015)
    {
      clear_line();
    }
  }
  while (lectura > 1015)
  {
    Lcd.Cursor(1, 3);
    Lcd.Display("DARKNESS");
    digitalWrite(pinLED, HIGH);
    lectura = analogRead(analogPin);
    if (lectura <= 1015)
    {
      clear_line();
      digitalWrite(pinLED, LOW);
    }
  }  
}

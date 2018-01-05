#include "MeOrion.h"

Me7SegmentDisplay disp(PORT_6);
MeRGBLed led(PORT_3);

unsigned long previousMillis = 0;
unsigned long currentMillis;
int interval = 1000;
int i = 30;
uint8_t r;
uint8_t g; 
uint8_t b;

void setup()
{
}

void loop()
{
  if(i < 0)
  {
    buzzerOn();
    delay(1000);
    buzzerOff();
    i = 30;
  }
  currentMillis = millis();
  disp.display(i);
  indicators(i/2);
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    i--;
  }
}

void indicators(uint8_t count)
{
  if (count >= 8)
  {
    r = 0;
    g = 100;
    b = 0;
  }
  else if (count >= 3)
  {
    r = 100;
    g = 100;
    b = 0;
  }
  else
  {
    r = 100;
    g = 0;
    b = 0;
  }
  for(int16_t x = 0; x <= count; x++)
  {
    led.setColorAt(x, r, g, b);
    led.show();
    delay(1);
  }
  for(int16_t x = count + 1; x <= 15; x++)
  {
    led.setColorAt(x, 0, 0, 0);
    led.show();
    delay(1);
  }
}

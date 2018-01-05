#include "MeOrion.h"

Me7SegmentDisplay disp(PORT_6);
MeRGBLed led(PORT_3);

unsigned long previousMillis = 0;
unsigned long lastTime = 0;
unsigned long currentMillis;
int interval = 1000;
int lastNum = 0;
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
  else if (count > 5 && count < 8)
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
  
  if(lastNum <= count)
  {
    for(int16_t x = lastNum; x <= count; x++)
    {
      led.setColorAt(x, r, g, b);
      led.show();
      delay(10);
    }
  }
  else
  {
    for(int16_t x = lastNum; x > count; x--)
    {
      led.setColorAt(x, 0, 0, 0);
      led.show();
      delay(10);
    }
  }
  lastNum = count;
}

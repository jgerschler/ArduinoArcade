#include "MeOrion.h"

Me7SegmentDisplay disp(PORT_6);
MeRGBLed led(PORT_3);

unsigned long previousMillis = 0;
unsigned long lastTime = 0;
unsigned long currentMillis;
int interval = 1000;
int lastNum = 0;
int i = 30;

void setup()
{
}

void loop()
{
  if(i < 0)
  {
    i = 30;
  }
  currentMillis = millis();
  disp.display(i);
  indicators(i/2, 20, 30, 40);
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    i--;
  }
}

void indicators(uint8_t count, uint8_t r, uint8_t g, uint8_t b)
{
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

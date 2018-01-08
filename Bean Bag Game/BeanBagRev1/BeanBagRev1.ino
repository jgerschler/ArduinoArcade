#include "MeOrion.h"

Me7SegmentDisplay disp(PORT_6);
MeRGBLed led(PORT_3);// can't combine with switch!
MeLimitSwitch switch1(PORT_4,SLOT1);
MeLightSensor lightSensor(PORT_8);


unsigned long previousMillis = 0;
unsigned long currentMillis;
int interval = 1000;
int i;
int score;
int lightValue;
uint8_t r;
uint8_t g; 
uint8_t b;

void setup()
{
  i = 30;
  score = 0;
  disp.display(score);
  for(int16_t x = 0; x < 15; x++)
  {
    led.setColorAt(x, 0, 100, 0);
    led.show();
    delay(1);
  }
}

void loop()
{
  if (switch1.touched())
  {
    previousMillis = millis();
    while (i >= 0)
    {
      currentMillis = millis();
      disp.display(score);
      indicators(i/2);
      lightValue = lightSensor.read();
      if (lightValue > 50)
      {
        score++;
      }
      if (currentMillis - previousMillis >= interval) 
      {
        previousMillis = currentMillis;
        i--;
      }
    }
    buzzerOn();
    for(int16_t x = 0; x < 3; x++)
    {
      for(int16_t x = 0; x < 15; x++)
      {
        led.setColorAt(x, 100, 0, 0);
        led.show();
        delay(1);
      }
      delay(150);
      for(int16_t x = 0; x < 15; x++)
      {
        led.setColorAt(x, 0, 0, 0);
        led.show();
        delay(1);
      }
      delay(150);
    } 
    buzzerOff();
    reset();
  }
}

void reset()
{
  i = 30;
  score = 0;
  previousMillis = 0;
  disp.display(score);
  for(int16_t x = 0; x < 15; x++)
  {
    led.setColorAt(x, 0, 100, 0);
    led.show();
    delay(1);
  }
  return;
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

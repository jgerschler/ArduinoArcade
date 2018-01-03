#include "MeOrion.h"

Me7SegmentDisplay disp(PORT_6);

unsigned long previousMillis = 0;
unsigned long lastTime = 0;
unsigned long currentMillis;
int interval = 1000;
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
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    i--;
  }
}

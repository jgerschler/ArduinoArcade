#include <Makeblock.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

unsigned char second = 31;
unsigned long previousMillis = 0;
unsigned long lastTime = 0;
unsigned long currentMillis;
const long interval = 500;
int ledState = LOW;
int lightValue = 0;
int gameScore = 0;
byte gameStart = 0;

//Me_LimitSwitch module can only be connected to PORT_3, PORT_4, PORT_6,PORT_7,PORT_8 of base shield or from PORT_3 to PORT_8 of baseboard.
Me7SegmentDisplay disp(PORT_6);
MeLightSensor lightSensor(PORT_8);
MeLimitSwitch limitSwitch1(PORT_4,SLOT1); //connecte to Me RJ25 Adapter SLOT1
MePort output(PORT_4);
MeRGBLed led(PORT_3);

void setup()
{
  Serial.begin(9600);
  Serial.println("Start.");
  disp.set();
  disp.init();
  led.setNumber(15);
}
void loop()
{
  disp.display(30);
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    }
    else {
      ledState = LOW;
    }
    output.dWrite2(ledState);
  }
  if(limitSwitch1.touched())
  {
    gameStart = 1;
    previousMillis = 0;
    gameLogic();  
  }
}

void gameLogic(){
  while (gameStart == 1) {
    lightValue = lightSensor.read();
    //Serial.println(lightValue);  
    if (lightValue > 50) {
      gameScore++;
      if (gameScore == 3) {
        buzzerOn();
        for(int t=0;t<15;t++){
          led.setColorAt(t, 0, 100, 0);
        }
        led.show();
        delay(1000);
        buzzerOff();
        for(int t=0;t<15;t++){
          led.setColorAt(t, 0, 0, 0);
        }
        led.show();
        gameStart = 0;
        gameScore = 0;
        lastTime = 0;
        previousMillis = 0;
        second = 31;
        return;
      }
      for (int i=0; i <= 2; i++) {
        buzzerOn();
        for(int t=0;t<15;t++){
          led.setColorAt(t, 0, 100, 0);
        }
        led.show();
        delay(50);
        buzzerOff();
        for(int t=0;t<15;t++){
          led.setColorAt(t, 0, 0, 0);
        }
        led.show();
        delay(50);
      }
    }
    if(millis()-lastTime>=1000){
      second --;
      if(second == 0)
      {
        buzzerOn();
        for(int t=0;t<15;t++){
          led.setColorAt(t, 100, 0, 0);
        }
        led.show();
        delay(1000);
        buzzerOff();
        for(int t=0;t<15;t++){
          led.setColorAt(t, 0, 0, 0);
        }
        led.show();
        gameStart = 0;
        gameScore = 0;
        lastTime = 0;
        previousMillis = 0;
        second = 31;
        return;
      }
      disp.display(second);
      lastTime = millis();
    }
  }  
}

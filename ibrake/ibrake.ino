/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "gTgniqSOA2EmQ0mymWVqp88Mu7mcjOIv";

Servo BrakeServo; // create servo object

// initial values
int closed = 100;
int open1 = 20;
int LED = 5;
int timer = 5;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "Telstra1C1A58-5G", "jbn49erdvqcj"); // add your wifi credentials here (use iPhone access point)
  BrakeServo.attach(12); // set up pin 12 as PWM
  pinMode(LED, OUTPUT);
  BrakeServo.write(open1); // open servo by default
 }

BLYNK_WRITE(V3) 
{
   timer = param.asInt(); // read slider for delay value in blynk app
}  
  
BLYNK_WRITE(V0) // assign pin V0 to servo control
{
  int i = param.asInt(); // read value from blink app
  int time = timer;
   if(i == 1)
   {
    BrakeServo.write(closed); // activate brake
   
    while (time != 0) // flash lights timer times
    {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    time--;
    }
   }
   else
   { 
    BrakeServo.write(open1); // deactivate brake
    delay(10);
   } 
}

BLYNK_WRITE(V2) // control the light 
{
  int j = param.asInt();
   if(j <= 0)
   {
    digitalWrite(LED, LOW);
   }
   else
   {
    digitalWrite(LED, HIGH);
    delay(10);
   } 
}
void loop()
{ 
    Blynk.run();
}

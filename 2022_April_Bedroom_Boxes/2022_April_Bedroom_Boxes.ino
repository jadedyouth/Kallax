#include <elapsedMillis.h>

#include <FastLED.h>

int switch_pin = 8;

byte mode;
byte counter;
byte prevmode;

byte hue;

#define NUM_LEDS 24
#define DATA_PIN 2

CRGB leds[NUM_LEDS];
elapsedMillis timer_0;
elapsedMillis timer_1;
elapsedMillis timer_2;


void setup() {
  pinMode(switch_pin, INPUT);
  FastLED.addLeds<WS2812,DATA_PIN,BRG>(leds,8);
   FastLED.addLeds<WS2812,3,BRG>(leds,8,16);
   FastLED.addLeds<WS2812,4,BRG>(leds,16,24);

  for(int i = 0; i < NUM_LEDS; i++) { leds[i] = CHSV(0, 0, 0); } FastLED.show();  

}

void loop() {



if (timer_0 > 2000 && counter < 2) {counter = 0; timer_0 = 0;}


if (mode != prevmode) {counter ++; prevmode = mode; timer_1 = 0;}

if (mode == 0) { for(int i = 0; i < NUM_LEDS; i++) { leds[i] = CHSV(0, 0, 0); } }
if (mode == 1) {
  
for(int i = 0; i < 8; i++) { leds[i] = CHSV(20, 255, 255); } 
for(int i = 8; i < 16; i++) { leds[i] = CHSV(20, 255, 255); } 
for(int i = 16; i < 24; i++) { leds[i] = CHSV(20, 255, 255); } 
  }

if (mode == 2) { 
  
  
  
  for(int i = 0; i < 2; i++) { leds[i] = CHSV(hue, 255, 255); }
  for(int i = 2; i < 4; i++) { leds[i] = CHSV(hue, 255, 255); }
  
  for(int i = 4; i < 6; i++) { leds[i] = CHSV(hue+ 30, 255, 255); }
  for(int i = 6; i < 8; i++) { leds[i] = CHSV(hue+ 30, 255, 255); }


  for(int i = 8; i < 10; i++) { leds[i] = CHSV(hue+ 90, 255, 255); }
  for(int i = 10; i < 12; i++) { leds[i] = CHSV(hue+ 90, 255, 255); }
  
  for(int i = 12; i < 14; i++) { leds[i] = CHSV(hue+ 50, 255, 255); }
  for(int i = 14; i < 16; i++) { leds[i] = CHSV(hue+ 50, 255, 255); }



  for(int i = 16; i < 18; i++) { leds[i] = CHSV(hue+ 120, 255, 255); }
  for(int i = 18; i < 20; i++) { leds[i] = CHSV(hue+ 120, 255, 255); }

  for(int i = 20 ; i < 22; i++) { leds[i] = CHSV(hue+ 30, 255, 255); }
  for(int i = 22; i < 24; i++) { leds[i] = CHSV(hue+ 30, 255, 255); }

  
if (timer_2 > 1000) {hue = hue + 60; timer_2 = 0;}




}

 if(digitalRead(switch_pin) == HIGH){
  mode = 0;

  if (timer_1 > 2000) {counter = 0;}
  }
 
  
  
  if(digitalRead(switch_pin) == LOW){
 if (counter < 2) {mode = 1;}

 if (counter >= 2) {mode = 2; }
  }



FastLED.show();
}

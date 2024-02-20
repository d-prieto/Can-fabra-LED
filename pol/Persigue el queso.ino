#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 8
CRGB leds[NUM_LEDS];
int ledActual = 1; //led central
bool pAlante = true;
int estadoEjeY=analogRead(A0);

void setup() {
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   Serial.begin(9600);

}

void loop() {
  Serial.println(estadoEjeY);
  //leds[] = CRGB::Purple;
  
   estadoEjeY = analogRead(A0);
  FastLED.clear();
  leds[ledActual] = CRGB::Purple;
  leds[ledActual +1] = CRGB::Purple;
  leds[ledActual -1] = CRGB::Purple;
  delay(50);
  FastLED.show();
  if (estadoEjeY<312) {
    ledActual--;
    
  }
  else {
    ledActual ++;
   
    }
  }

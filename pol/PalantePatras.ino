#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 8
CRGB leds[NUM_LEDS];
int ledActual = 1; //led central
bool pAlante = true;

void setup() {
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}

void loop() {
  FastLED.clear();
  leds[ledActual] = CRGB::Purple;
  leds[ledActual +1] = CRGB::Purple;
  leds[ledActual -1] = CRGB::Purple;
  delay(50);
  FastLED.show();
  if (pAlante) {
    ledActual++;
    if (ledActual >118 ){
      pAlante = false;
    }
  }
  else {
    ledActual --;
    if (ledActual <1 ){
      pAlante = true;
    }
  }
}

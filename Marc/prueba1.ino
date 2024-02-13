/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 180

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 8
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
int ledActual = 0;
void setup() { 
    delay(2000);
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

}

void loop() { 
  // Turn the LED on, then pause
  if( ledActual > 10) {
    leds[ledActual-10] = CRGB::Blue;
  }
  else{
    leds[ledActual+169] = CRGB::Blue;
  }
 
  if( ledActual > 20) {
    leds[ledActual -20] = CRGB::Violet;
  }
     else{
    leds[ledActual+159] = CRGB::Violet;
  }
  leds[ledActual] = CRGB::Red;
  FastLED.show();
  leds[19] = CRGB::Orange;
  leds[29] = CRGB::Yellow;
  leds[39] = CRGB::Green;
  leds[49] = CRGB::Blue;
  leds[59] = CRGB::Purple;
  leds[69] = CRGB::Blue;
  leds[79] = CRGB::Green;
  leds[89] = CRGB::Yellow;
  leds[99] = CRGB::Orange;
  delay(50);
  // Now turn the LED off, then pause
  leds[ledActual] = CRGB::Black;
  if( ledActual > 10) {
    leds[ledActual-10] = CRGB::Black;
  }
   else{
    leds[ledActual+169] = CRGB::Black;
  }
 if( ledActual > 20) {
    leds[ledActual -20] = CRGB::Black;
  }
    else{
    leds[ledActual+159] = CRGB::Black;
  }
    if( ledActual > 178) {
     ledActual = 0;
   }
  FastLED.show();
  delay(50);
  ledActual = ledActual +1;
  

}

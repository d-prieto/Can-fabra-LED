/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 120

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 8


// Define the array of leds
CRGB leds[NUM_LEDS];
int pepito = 0; 

void setup() { 
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.setBrightness(  64 );
}

void loop() { 
  // Turn the LED on, then pause
  leds[pepito] = CRGB::Green;
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(200);
  // Now turn the LED off, then pause
  leds[pepito] = CRGB::Black;
  leds[1] = CRGB::Blue;
  FastLED.show();
  pepito = pepito + 2;
  delay(300);
}

#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 11

CRGB leds[NUM_LEDS];
int colorIndex = 0;
// the setup function runs once when you press reset or power the board
void setup() {
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
 FastLED.setBrightness(1000);
 
}

void loop() {
      for( int i = 0; i < 16; i++) {
        leds[i] = ColorFromPalette( RainbowColors_p, colorIndex, 1000, LINEARBLEND);
        colorIndex += 5;
    }
      for( int i = 16; i < 119; i++) {
        leds[i] = ColorFromPalette( RainbowColors_p, colorIndex, 1000, LINEARBLEND);
        colorIndex += 5;
    FastLED.show();
    FastLED.delay(200);
}

  }



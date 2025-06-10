#include <FastLED.h>

#define DATA_PIN    3
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    180

CRGB leds[NUM_LEDS];
#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup() {
  // put your setup code here, to run once:
  delay(1000); // 1second delay for recovery

    FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
     FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    // Turn the LED on, then pause
   for (int i = 0; i< NUM_LEDS; i=i+1)  {
     leds[i].red = 12;
     leds[i].blue = 130;
     leds[i].green = 93;
     FastLED.show();

  }
  delay(1000);
  // Now turn the LED off, then pause
 

  for (int i = 0; i< NUM_LEDS; i=i+3)  {
     leds[i].red = 100;
     leds[i].blue = 30;
     leds[i].green = 3;
     FastLED.show();
      // delay(19);
  }

  delay(1000);

  for (int i = 0; i< NUM_LEDS; i=i+2)  {
     leds[i].red = 140;
     leds[i].blue = 70;
     leds[i].green = 200;
     FastLED.show();
      // delay(19);
  }

  delay(1000);

}

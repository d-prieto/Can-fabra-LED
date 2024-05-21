#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 11

CRGB leds[NUM_LEDS];

// the setup function runs once when you press reset or power the board
void setup() {
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
 FastLED.setBrightness(120);
}

void loop() {
  iluminarTodosLosLeds();
  delay(500);
  //Comienza la luz en 1023 y se va dividiendo entre dos hasta que llega a la led 0. 
  //Descenso geométrico
  for (int luz = 120; luz > 0; luz = luz / 2) {
      FastLED.setBrightness(luz); 
      iluminarTodosLosLeds();
     delay(100); 
  }
  
  //Comienza la luz en 1 y se va multiplicando entre dos hasta que llega a la led 1023.
  //Ascenso geométrico
  for (int luz = 120; luz < 1000; luz = luz * 2) {
      FastLED.setBrightness(luz); 
      iluminarTodosLosLeds();
     delay(100); 
  }
  //Comienza la luz en 1 y se va sumando diez hasta que llega a la led 1023.
  //Ascenso aritmético

  for (int luz = 1; luz < 1000; luz = luz + 10) {
      FastLED.setBrightness(luz); 
      iluminarTodosLosLeds();
     delay(100); 
  }
    //Comienza la luz en 1023 y se va restando diez hasta que llega a la led 0.
    //Descenso aritmético
   for (int luz = 120; luz > 0; luz = luz - 10) {
      FastLED.setBrightness(luz); 
      iluminarTodosLosLeds();
     delay(100); 
   }
  
}

void iluminarTodosLosLeds() {
  for (int i = 0; i < NUM_LEDS; i ++){
    leds[i] = CRGB::Blue;   
    }
  FastLED.show();
}

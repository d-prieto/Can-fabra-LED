#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    180
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

     delay( 3000 );


for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();


delay( 2500 );

for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

 delay( 2000 );

for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

 
 delay( 1500 );

for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();


 delay( 1000 );

for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

 
 delay( 750 );

 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

  delay( 500 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

  delay( 500 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

  delay( 500 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

  delay( 500 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

  delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

   delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

   delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

   delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

   delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();
    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Green;
  }
  else{ //impares
    leds[i] = CRGB::Red;
  }
 }
 FastLED.show();

    delay( 100 );
  
 for(int i = 0; i<NUM_LEDS; i++){
  if (i%4 == 0 ||i %4 ==1) {//pares
    leds[i] = CRGB::Red;
  }
  else{ //impares
    leds[i] = CRGB::Green;
  }
 }
 FastLED.show();
}

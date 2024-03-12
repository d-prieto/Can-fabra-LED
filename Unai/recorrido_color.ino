

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 180

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3
#define CLOCK_PIN 13


// Define the array of leds
CRGB leds[NUM_LEDS];
bool rebote = true;
int n=1 ;
void setup() { 
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  
     FastLED.setBrightness(30);

  pinMode(2, INPUT_PULLUP);
   Serial.begin(9600);
}

void loop() { 
  // Turn the LED on, then pause
  int aux=analogRead(A0);
  Serial.println(aux);
  aux = map (aux, 0, 1023, -3,3);
  Serial.println(aux);
  n=n+aux;
  if(n<1){
    n=1;  }
  if(n>NUM_LEDS-2) {
    n=NUM_LEDS-2;
  }
  
  leds[n] = CRGB::Cyan;
  FastLED.show();
  delay(50);

 
  if (aux>0){
    leds[n-1] = CRGB::Red;
    if (aux>1) {
     leds[n-2] = CRGB::Red; 
    }   
  }
  else
    if (aux<0)
    leds[n+1] = CRGB::Green;
      if (aux<-1) {
        leds[n+2] = CRGB::Green;
          if (aux<-2){
            leds[n+3] = CRGB::Green;
          }
      }
    
    
  FastLED.show();
  delay(10); 

  
  }
  
  

 
    


/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 160

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 8


// Define the array of leds
CRGB leds[NUM_LEDS];

int ledNave = 0;

//longs para la hora

long tiempoActual = 0;
long tiempoAnteriorQueActualizamosElLed = 0;
bool ledEncendido = true;

void setup() { 
     FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
     Serial.begin(9600);
   }

void loop() { 
  int estadoEjeY = analogRead(A0);
 // Serial.println(estadoEjeY);
  int espera = map(estadoEjeY, 0, 1023, 50, 270);
 // Serial.println(espera);
  
  tiempoActual = millis();
  Serial.println(tiempoActual);
  if (tiempoActual> (tiempoAnteriorQueActualizamosElLed + espera)) {
    tiempoAnteriorQueActualizamosElLed = tiempoActual;
    if (ledEncendido) {
        leds[ledNave] = CRGB::Red;
         FastLED.show();      
    }
    else {
        leds[ledNave-1] = CRGB::Black;
         FastLED.show();
    }

    ledEncendido = !ledEncendido;
    ledNave +=1;
  }

  
  if (ledNave > 178) {
    ledNave = 0;
  }
  
   
}

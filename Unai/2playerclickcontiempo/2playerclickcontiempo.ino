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


// Define the array of leds
CRGB leds[NUM_LEDS];

int ledNave = 0;
int ledNave2 = 0;

//longs para la hora

long tiempoActual = 0;
long tiempoAnteriorQueActualizamosElLed = 0;
bool ledEncendido = true;
int estadoBotonAnterior1 = 0;
int estadoBotonAnterior2 = 0;
int contadorClicks = 0;
int contadorClicks2 = 0;
int objetivoClicks = 1;
int objetivoClicks2 = 2;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
static uint8_t startIndex = 0;
long inicio =0;
long inicio2 =0;
  long tiempo;
  long tiempo2;

void setup() { 
     FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
     Serial.begin(9600);
     pinMode(5, INPUT);
     pinMode(3, INPUT);

     delay(500);
FastLED.clear();
FastLED.show();
delay(3000);
semaforo();
  delay(1000);
  SetupPurpleAndGreenPalette();
  currentBlending = LINEARBLEND;
  inicio = millis()- (2*millis());

  
}

void SetupPurpleAndGreenPalette()
{
    CRGB purple = CRGB(73, 255, 0 );
    CRGB green  = CRGB(197, 155,0 );
    CRGB black  = CRGB(255, 232, 0 );
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}   

void loop() { 
  
  
  int estadoBoton = digitalRead(5);
  int estadoBoton2 = digitalRead(3);
  //Serial.println(estadoBoton);
  int estadoEjeY = analogRead(A0);
 // Serial.println(estadoEjeY);
  int espera = map(estadoEjeY, 0, 1023, 50, 270);
 // Serial.println(espera);
  
  tiempoActual = millis();
  //Serial.println(tiempoActual);
  if (tiempoActual> (tiempoAnteriorQueActualizamosElLed + espera)) {
    iluminarFondo();
    tiempoAnteriorQueActualizamosElLed = tiempoActual;
    if (ledEncendido) {
        leds[ledNave] = CRGB::Red;
        leds[ledNave2] = CRGB::Blue;
        if (ledNave == ledNave2) {
          leds[ledNave2] = CRGB::Purple;
          tone(10, 20, 1000);
        }
         FastLED.show();      
    }
    else {
        leds[ledNave] = CRGB::Black;
        leds[ledNave2] = CRGB::Black;
         FastLED.show();
    }

    ledEncendido = !ledEncendido;
    
  }
  if(estadoBoton == HIGH && estadoBotonAnterior1!= estadoBoton ) {
    contadorClicks ++;
    
  }
  estadoBotonAnterior1 = estadoBoton;
  //player 2
  if(estadoBoton2 == HIGH && estadoBotonAnterior2!= estadoBoton2 ) {
    contadorClicks2 ++;

  }
  estadoBotonAnterior2 = estadoBoton2;
  if ( contadorClicks == objetivoClicks){
    leds[ledNave] = CRGB::Black;
    ledNave +=1;
    contadorClicks = 0;
    objetivoClicks = random(1,4);
  }
  if ( contadorClicks2 == objetivoClicks2){
    leds[ledNave2] = CRGB::Black;
    ledNave2 +=1;
    contadorClicks2 = 0;
    objetivoClicks2 = random(2,4);
  }
  if (ledNave > 179) {
    ledNave = 0;
    tone(10, 165, 1000);
    if(inicio>=0){
      tiempo= (millis()-inicio-tiempo)/1000;
      Serial.print("tiempo player 1 ");
      Serial.print(tiempo);
      Serial.print(" tiempo player 2 ");
      Serial.print(tiempo2);
    }else{
      inicio=(inicio+millis())/1000;
      Serial.print("tiempo player 1 ");
      Serial.print(inicio);
      Serial.println(" tiempo player 2 ");
      Serial.print(inicio2);
    }
  }
  if (ledNave2 > 179) {
    ledNave2 = 0;
    tone(10, 990, 1000);
        if(inicio2>=0){
      tiempo2= (millis()-inicio2-tiempo2)/1000;
      Serial.print("tiempo player 1 ");
      Serial.print(tiempo);
      Serial.println(" tiempo player 2 ");
      Serial.print(tiempo2);
    }else{
      inicio2=(inicio2+millis())/1000;
      Serial.print("tiempo player 1 ");
      Serial.print(inicio);
      Serial.println(" tiempo player 2 ");
      Serial.print(inicio2);
    }
  } 
}

void iluminarFondo() {
    int colorIndex = startIndex;
      for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, 60, currentBlending);
        colorIndex += 3;
    }
    startIndex --;
}

void semaforo()  {
  FastLED.clear();
   leds[4] = CRGB::Red;
  FastLED.show();
  delay(10);
    leds[5] = CRGB::Red;
    FastLED.show();
  delay(10);
    leds[6] = CRGB::Red;
    FastLED.show();
    tone(10, 670, 500);
    delay(1500);
    FastLED.clear();
    delay(10);
    leds[4] = CRGB::Red;
  FastLED.show();
  delay(10);
  leds[5] = CRGB::Red;
  FastLED.show();
  delay(10);
  leds[6] = CRGB::Black;
  FastLED.show();
  tone(10, 670, 500);
  delay(1500);
  FastLED.clear();
  delay(10);
   leds[4] = CRGB::Red;
  FastLED.show();
  delay(10);
  leds[5] = CRGB::Black;
  FastLED.show();
  delay(10);
  leds[6] = CRGB::Black;
  FastLED.show();
  tone(10, 670, 500);
  delay(1500);
   FastLED.clear();
   delay(10);
    leds[4] = CRGB::Green;
  FastLED.show();
  delay(10);
  leds[5] = CRGB::Green;
  FastLED.show();
  delay(10);
  leds[6] = CRGB::Green;
  FastLED.show();

  tone(10, 1000, 500);

  delay(600);
}

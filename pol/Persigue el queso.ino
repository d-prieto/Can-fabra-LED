#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 8
CRGB leds[NUM_LEDS];
int ledActual = 1; //led central
bool pAlante = true;
int estadoEjeY=analogRead(A0);
int queso=random(4,NUM_LEDS);
int Puntos=0;
void setup() {
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   Serial.begin(9600);

}

void loop() {
  Serial.println(estadoEjeY);
  //leds[] = CRGB::Purple;
  ComerQueso();
   estadoEjeY = analogRead(A0);
  FastLED.clear();
  leds[queso] = CRGB::Yellow;
  leds[ledActual] = CRGB::Purple;
  leds[ledActual +1] = CRGB::Purple;
  leds[ledActual -1] = CRGB::Purple;
  delay(50);
  FastLED.show();
  if (estadoEjeY<112) {
    ledActual--;
    
  }
  if(estadoEjeY<312) {
    ledActual --;
   
    }
    if(estadoEjeY>612) {
    ledActual ++;
   
    }
    if(estadoEjeY>812) {
    ledActual ++;
   
    }
  }


void ComerQueso(){

  if(queso==ledActual){
  MostrarPuntos();
  queso=random(4,NUM_LEDS);
}


void MostrarPuntos(){
  FastLED.clear();
  for(int a=0;a=Puntos;a++){
     leds[a] = CRGB::Yellow; 
  }
}

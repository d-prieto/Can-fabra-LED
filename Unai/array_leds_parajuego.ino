#include <FastLED.h>
#include "pitches.h"

#define NUM_LEDS 30
#define DATA_PIN 3
#define DATA_PIN2 4
CRGB matrix [2] [NUM_LEDS];
int duration = 100;  // 500 miliseconds
int x = 5;
int y = random(0,1);
int aux;
int aux2;
int upX,downX,sideY, othersideY;
int block1, block2;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads


//initialize an instance of class NewKeypad

void setup(){
  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(matrix[0], NUM_LEDS);  // GRB ordering is assumed
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(matrix[1], NUM_LEDS);
  FastLED.setBrightness(10);
  for(x=0; x< NUM_LEDS-1;x++)
    matrix[1][x]= CRGB::White;
  for(x=0; x< NUM_LEDS-1;x++)
    matrix[0][x]= CRGB::White;
  x=5;
  matrix[y][x]= CRGB:: Red;
  FastLED.show();
  pinMode(6, INPUT);
}
  
void loop(){
  upX=digitalRead(6);
  downX=digitalRead(7);
  sideY=digitalRead(8);
  if(upX==1)
    x+=1;
  if(downX==1)
    x-=1;
  if(sideY==1)
    y+=1;
  if(othersideY==1)
    y-=1;
  delay(100);
  actualizar();
 // bloque1()
  matrix[y][x]= CRGB:: Red;
  FastLED.show();
}
/*void bloque1(){
  delay(random(0,3000));


}*/
void actualizar(){
  if(x>NUM_LEDS){
    x-=NUM_LEDS;
  }
  if(y%2==0){
    y=0;
  }else{
    y=1;
  }
  aux=x;
  aux2=y;
  for(x=0; x< NUM_LEDS-1;x++)
    matrix[1][x]= CRGB::White;
  for(x=0; x< NUM_LEDS-1;x++)
    matrix[0][x]= CRGB::White;
  y=aux2;
  x=aux;
}
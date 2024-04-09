#include <FastLED.h>
#include "pitches.h"
#include <Keypad.h>
#define NUM_LEDS 180

CRGB leds[NUM_LEDS];
int led = 3;
int melody[] = {
  NOTE_C5};
int duration = 100;  // 500 miliseconds
int fullmelody[]={
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};
int megalo[]={
  NOTE_D5, NOTE_D5, NOTE_D6, NOTE_A5
};

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);

  
  
  FastLED.setBrightness(30);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    if(customKey=='1')
      tone(12, melody, duration);
      leds[1] = CRGB::Red;
    if(customKey=='2')
      tone(12, NOTE_D5, duration);
    if(customKey=='3')
      tone(12, NOTE_E5, duration);
    if(customKey=='4')
      tone(12, NOTE_F5, duration);
    if(customKey=='5')
      tone(12, NOTE_G5, duration);
    if(customKey=='6')
      tone(12, NOTE_A5, duration);
    if(customKey=='7')
      tone(12, NOTE_B5, duration);
    if(customKey=='8')
      tone(12, NOTE_C6, duration);
    if(customKey=='9')
      tone(12, NOTE_D6, duration);
    if(customKey=='0')
      tone(12, NOTE_E6, duration);
    
  }
}

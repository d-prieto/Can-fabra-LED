#include <Keypad.h>
#include <FastLED.h>
#define NUM_LEDS 178

#define DATA_PIN 12


// Define the array of leds
CRGB leds[NUM_LEDS];
 
const byte rowsCount = 4;
const byte columsCount = 4;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { 11, 10, 9, 8 };
const byte columnPins[columsCount] = { 7, 6, 5, 4 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 
void setup() {
   Serial.begin(9600);
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

}
 
void loop() {
    for (int i = 0; i < 178; i ++) 
   {    
    if (i % 2 == 0){
       leds[i] = CRGB::Blue; 
    }
    else 
    {
      leds[i] = CRGB::Green; 
    }
  delay(15);
  
  FastLED.show();
   }

  delay(500);
  // Now turn the LED off, then pause
  for (int i = 177; i >= 0; i = i -1) 
   {
      if (i % 2 == 0){
  leds[i] = CRGB::Purple;
    }
    else 
    {
      leds[i] = CRGB::Red; 
    }
    char key = keypad.getKey();
    if (key) {
      break;
    }
    
  delay (15);
  
    FastLED.show();
   }
  delay(500);
   char key = keypad.getKey();
   if (key) {
      Serial.println(key);
      tone(2,440, 100);
   }
}

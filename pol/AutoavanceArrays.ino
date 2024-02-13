#include <FastLED.h>
#define DATA_PIN 8
#define NUM_LEDS 120
int autoAvance[7] = {0,15,30,45,60,75,90};

CRGB leds[NUM_LEDS];

void setup() {

  // put your setup code here, to run once:
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
 Serial.begin(9600);
}
void loop(){  
    while (true){
  Serial.println(autoAvance[0]);
  autoAvance[0] = autoAvance[0]+3;
   autoAvance[1] = autoAvance[1]+3;
    autoAvance[2] = autoAvance[2]+3;
     autoAvance[3] = autoAvance[3]+3;
          leds[autoAvance[0]] = CRGB::Red;
           leds[autoAvance[0]+1] = CRGB::Red;
            leds[autoAvance[0]+2] = CRGB::Red;
             leds[autoAvance[1]] = CRGB::Blue;
                 leds[autoAvance[1]+1] = CRGB::Blue;
                   leds[autoAvance[1]+2] = CRGB::Blue;
                      leds[autoAvance[2]] = CRGB::Green;
                        leds[autoAvance[2]+1] = CRGB::Green; 
                        leds[autoAvance[2]+2] = CRGB::Green;
                     
                         leds[autoAvance[3]] = CRGB::Purple;
                        leds[autoAvance[3]+1] = CRGB::Purple; 
                        leds[autoAvance[3]+2] = CRGB::Purple;
                         FastLED.show();
                         delay(200);
                         leds[autoAvance[0]] = CRGB::Black;
           leds[autoAvance[0]+1] = CRGB::Black;
            leds[autoAvance[0]+2] = CRGB::Black;
             leds[autoAvance[1]] = CRGB::Black;
                 leds[autoAvance[1]+1] = CRGB::Blue;
                      leds[autoAvance[2]] = CRGB::Black;
                        leds[autoAvance[2]+1] = CRGB::Black; 
                        leds[autoAvance[2]+2] = CRGB::Black;
                     
                         leds[autoAvance[3]] = CRGB::Black;
                        leds[autoAvance[3]+1] = CRGB::Black; 
                        leds[autoAvance[3]+2] = CRGB::Black;
                        if (autoAvance[0]==119){
                          
                          FastLED.clear();
                          autoAvance[0]=0;
                        }
                         if (autoAvance[1]>119){
                        
                          FastLED.clear();
                          autoAvance[1]=0;
                        }
                         if (autoAvance[2]>119){
                          
                          FastLED.clear();
                          autoAvance[2]=0;
                        }
                         if (autoAvance[3]>119){
                          
                          FastLED.clear();
                          autoAvance[3]=0;
                        }
}
 }
                     

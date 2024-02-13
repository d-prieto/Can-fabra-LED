#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 8
CRGB leds[NUM_LEDS];
int i = 0;
int k = 0;
int pinBoton = 5;
int estadoAnteriorB = 0;
int estadoAnteriorJ = 0;
int vueltasCarrera = 2;
int vueltasA = 0;
int vueltasR = 0;
long vueltaAnteriorR = 0;
long vueltaActualR = 0;
long vueltaAnteriorA = 0;
long vueltaActualA = 0;
double segundos = 0;

void setup() {
  // put your setup code here, to run once:
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
      pinMode(pinBoton, INPUT);
      pinMode(13,INPUT_PULLUP);
      Serial.begin(9600);

}

void loop() {
 
 int estadoBoton = digitalRead(pinBoton);
 int estadoJoystik = digitalRead(13);
 Serial.println(estadoBoton);
 cronometrar();
  // put your main code here, to run repeatedly:
 if ( estadoBoton== HIGH &&( estadoAnteriorB== 0)){
   Serial.println(i);
      leds[i] = CRGB::Black;
      leds[i+1] = CRGB::Black;
      leds[i+2] = CRGB::Black;
       leds[i+3] = CRGB::Black;
     i =i +4;

    
      leds[i] = CRGB::Red;
      leds[i+1] = CRGB::Red;
      leds[i+2] = CRGB::Red;
       leds[i+3] = CRGB::Red; 
  
      }
 if ( estadoJoystik== LOW &&( estadoAnteriorJ== 1)){
    leds[k] = CRGB::Black;
      leds[k+1] = CRGB::Black;
      leds[k+2] = CRGB::Black;
      leds[k+3] = CRGB::Black;
       
       k =k +4;
  
      leds[k] = CRGB::Blue;
      leds[k+1] = CRGB::Blue;
      leds[k+2] = CRGB::Blue;
      leds[k+3] = CRGB::Blue;
 }
 if (k==i) {
   leds[k] = CRGB::Blue;
      leds[k+1] = CRGB::Red;
      leds[k+2] = CRGB::Blue;
      leds[k+3] = CRGB::Red;

 }
      
   
     ganador();
    FastLED.show();
    if (i>=120){
    i = 0;
   vueltasR = vueltasR ++;
    FastLED.clear();
}
 if (k==120){
    k = 0;
     vueltasA = vueltasA++;
    FastLED.clear();
}
estadoAnteriorB = estadoBoton;
   estadoAnteriorJ = estadoJoystik;
}
void cronometrar() {
  if (i == 0)
  {
    vueltaAnteriorR= millis();
  }
  if (i>=119) {
    vueltaActualR = millis();
    segundos = (double) ((vueltaActualR-vueltaAnteriorR)/1000);
    Serial.println("Vuelta Rojo");
    Serial.println(segundos);
  }
  if (k == 0)
  {
    vueltaAnteriorA= millis();
  }
  if (i>119) {
    vueltaActualA = millis();
    segundos = (double) ((vueltaActualA-vueltaAnteriorA)/1000);
    Serial.println("Vuelta Azul");
    Serial.println(segundos);
  }
}
void ganador() {
  int autoAvance = 0;

 // if ( vueltasR==vueltasCarrera){
    for (int i=0;i<=NUM_LEDS; i++){
       leds[i] = CRGB::Red;
        }
        while (true){
          leds[autoAvance] = CRGB::Red;
           leds[autoAvance+1] = CRGB::Red;
            leds[autoAvance+2] = CRGB::Red;
             leds[autoAvance+20] = CRGB::Blue;
                 leds[autoAvance+21] = CRGB::Blue;
                   leds[autoAvance+22] = CRGB::Blue;
                      leds[autoAvance+40] = CRGB::Green;
                        leds[autoAvance+41] = CRGB::Green; 
                        leds[autoAvance+42] = CRGB::Green;
                        if (autoAvance==80){
                          autoAvance=-40;
                        }
                     
          
        }
  //}
}

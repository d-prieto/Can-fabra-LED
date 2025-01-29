int duracionLed = 5000 ;
int cocheRojo=8;
int cocheAmarillo=9;
int pinLed2=10;
int peatonRojo=11;
int pinLed4=12;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(cocheRojo, OUTPUT);
  pinMode(cocheAmarillo, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(peatonRojo, OUTPUT);
  pinMode(pinLed4, OUTPUT);
}
void loop() {

  digitalWrite(pinLed2, HIGH);
  digitalWrite(peatonRojo, HIGH);
  delay(duracionLed);

 for (int i =0 ; i< 4; i = i+1) {
  digitalWrite(pinLed2, LOW);
  delay(duracionLed/30);
  digitalWrite(pinLed2, HIGH);
  delay(duracionLed/30);
 }
 
  digitalWrite(pinLed2, LOW);
  digitalWrite(cocheAmarillo, HIGH);
   for (int i =0 ; i< 19; i = i+1) {
  digitalWrite(cocheAmarillo, LOW);
  delay(duracionLed/50);
  digitalWrite(cocheAmarillo, HIGH);
  delay(duracionLed/50);
 }
  digitalWrite(cocheAmarillo, LOW);
  digitalWrite(peatonRojo, LOW);
  digitalWrite(cocheRojo, HIGH);
  digitalWrite(pinLed4, HIGH);
  delay(duracionLed);
// parpadeo verde 1
/*
  digitalWrite(pinLed4, LOW);
  delay(duracionLed/6);
  digitalWrite(pinLed4, HIGH);
  delay(duracionLed/6);
 */
 for (int i =0 ; i< 4; i = i+1) {
  digitalWrite(pinLed4, LOW);
  delay(duracionLed/30);
  digitalWrite(pinLed4, HIGH);
  delay(duracionLed/30);
 }
  digitalWrite(cocheRojo, LOW);
  digitalWrite(pinLed4, LOW);
 
 
}

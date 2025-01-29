// the setup function runs once when you press reset or power the board
int duracionLed = 500;

void setup() {
 for (int pin =8 ; pin< 13; pin = pin+1) {
  pinMode(pin, OUTPUT);
 }
}

void loop (){
   for (int pin =8 ; pin< 13; pin = pin+1) {
  digitalWrite(pin, LOW);
  delay(duracionLed);
  digitalWrite(pin, HIGH);
  delay(duracionLed);
 }

}

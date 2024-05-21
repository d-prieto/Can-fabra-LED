/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(11, OUTPUT);
}

void loop() {
  //Comienza la luz en 1023 y se va dividiendo entre dos hasta que llega a la led 0. 
  //Descenso geométrico
  for (int luz = 1023; luz > 0; luz = luz / 2) {
     analogWrite(11, luz);  
     delay(100); 
  }
  //Comienza la luz en 1 y se va multiplicando entre dos hasta que llega a la led 1023.
  //Ascenso geométrico
  for (int luz = 1; luz < 1023; luz = luz * 2) {

  analogWrite(11, luz);   
  delay(100); 
  }
  //Comienza la luz en 1 y se va sumando diez hasta que llega a la led 1023.
  //Ascenso aritmético

  for (int luz = 1; luz < 1023; luz = luz + 10) {

  analogWrite(11, luz);  
  delay(20); 
  }
    //Comienza la luz en 1023 y se va restando diez hasta que llega a la led 0.
    //Descenso aritmético
   for (int luz = 1023; luz > 0; luz = luz - 10) {

  analogWrite(11, luz);   // turn the LED on (HIGH is the voltage level)
  delay(10); 
   }
  
}

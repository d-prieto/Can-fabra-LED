
#include <Servo.h>

Servo myservo; 

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  int valorSensor = analogRead(A0);
  float voltaje = (valorSensor/1024.0) *5.0;
  Serial.println(valorSensor);
  Serial.println(voltaje);
   float temperatura = (voltaje -.5) * 100;
  int angulo = map(temperatura, 21, 30, 0, 180);
  Serial.println(temperatura);
  myservo.write(angulo);
  delay(550);
}

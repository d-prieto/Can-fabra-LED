void setup() {
  // put your setup code here, to run once:
tone(10, 880, 500);
delay(200);
noTone(200);
tone(10, 880, 250);
delay(200);
noTone(200);
tone(10, 880, 250);
delay(200);
noTone(200);
tone(10, 830.61, 250);
delay(200);
noTone(200);
tone(10, 659.26, 250);
delay(200);
noTone(200);
tone(10, 783.99, 250);
delay(200);
noTone(200);
tone(10, 698.46, 250);
delay(200);
noTone(200);
tone(10, 659.26, 200);
delay(200);
noTone(200);
}
void loop() {
  // put your main code here, to run repeatedly:
for (int frecuencia = 830.61; frecuencia <1450,98; frecuencia = frecuencia * 1.20){
  tone(10, frecuencia, 100);
  delay(100);
noTone(100);
  delay(100);
}
for (int frecuencia = 600; frecuencia > 295; frecuencia = frecuencia -20){
  tone(10, frecuencia, 100);
  delay(100);

}

}


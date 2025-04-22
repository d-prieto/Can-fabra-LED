void setup() {
int freq = 300;
int freq2 = 1000;

while(freq < 1000){
  tone(9,freq,20);
  delay(20);
  freq = freq + 20;
  }
while(freq2 > 300){
  tone(9,freq2,20);
  delay(20);
  freq2 = freq2 - 20;
  }
}

void loop() {
  }

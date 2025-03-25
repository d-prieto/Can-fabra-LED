#include <Wire.h>


#define DISPLAY_ADDRESS1 0x71 //This is the default address of the OpenSegment with both solder jumpers open


int minutos = 0;//el minuto de cuando subes el programa
int horas = 19;//la hora de cuando subes el programa
long tiempoActual = 0;
long tiempoAnterior =0;
void setup() 
{
 
  Wire.begin(); //Join the bus as master

  //By default .begin() will set I2C SCL to Standard Speed mode of 100kHz
  //Wire.setClock(400000); //Optional - set I2C SCL to High Speed Mode of 400kHz

  Serial.begin(9600); //Start serial communication at 9600 for debug statements
  Serial.println("OpenSegment Example Code");

  //Send the reset command to the display - this forces the cursor to return to the beginning of the display
  Wire.beginTransmission(DISPLAY_ADDRESS1);
  Wire.write('v');
  Wire.endTransmission();
}

void loop() 
{ 
 tiempoActual = millis();
 if(tiempoActual == 60000){
  minutos++;
 } if(minutos == 60){
  horas++;
  minutos = 0;
 }if(horas == 24){
  horas = 0;
 }
 Serial.println ("horas = ");
 Serial.print (horas);
 Serial.println ("minutos = ");
 Serial.print(minutos);
 
  
  
  i2cSendValue(); //Send the four characters to the display
  
 
}

//Given a number, i2cSendValue chops up an integer into four values and sends them out over I2C
void i2cSendValue()
{
  Wire.beginTransmission(DISPLAY_ADDRESS1); // transmit to device #1
  Wire.write(horas / 10); //Send the left most digit
 horas %= 10; //Now remove the left most digit from the number we want to display
  Wire.write(horas %10);
 // horas %= ;
  Wire.write(minutos / 10);
  minutos %= 10;
  Wire.write(minutos); //Send the right most digit
  
  Wire.endTransmission(); //Stop I2C transmission
}

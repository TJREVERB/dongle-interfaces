// [sourcecode language="cpp"]

// NOTE: If running on Linux and during code upload you experience the error:
// "avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied"
// Go to your terminal and type the following command:
// "sudo chmod a+rw /dev/ttyACM0"
// Re-upload the code and the problem should be resolved.

#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
// int state = 0;

void setup() 
{
  // pinMode(13, OUTPUT);
  Serial.begin(9600); // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);
  
  // define callbacks for i2c communication
  
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  
  Serial.println("Ready!");
}

void loop() 
{
  delay(100);
}

// callback for received data
void receiveData(int byteCount)
{
  if(Wire.available())
  {
    number = Wire.read();
    Serial.print("Data received: ");
    Serial.println(number);
  }
}
/*
void receiveData(int byteCount)
{
  while(Wire.available()) 
  {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);
    
    if(number == 1)
    {
      if(state == 0)
      {
        digitalWrite(13, HIGH); // set the LED on
        state = 1;
      }
      else
      {
        digitalWrite(13, LOW); // set the LED off
        state = 0;
      }
    }
  }
}
*/
// callback for sending data
void sendData()
{
  Wire.write(number);
}

// [/sourcecode]

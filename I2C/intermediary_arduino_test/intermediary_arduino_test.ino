#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial one(10,11);
#define SLAVE_ADDRESS 0x08
void setup() {
  // put your setup code here, to run once:
  one.begin(4800);
  Serial.begin(9600);
  
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(sendToArduino);
  Wire.onRequest(readFromArduino);
  Serial.println("I2C Ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void sendToArduino(int byteCount){
  one.write("0");
  int data = 0;
  while(Wire.available()){
      data = Wire.read(); 
  }
  one.write(data);
}

void readFromArduino(){
  one.write("1");
  one.listen();
  int size_of_array = one.read();
  char data[size_of_array];
  for (int x = 0; x<size_of_array; x++){
    data[x] = one.read();
  }
  Wire.write(data);
}

//char copyArray(char data[], int count){
//  char[] newArray = new char[count];
//  for (int x = 0; x<count-1; x++){
//    copyArray[x] = newArray[x];
//  }
//
//  return newArray;
//}

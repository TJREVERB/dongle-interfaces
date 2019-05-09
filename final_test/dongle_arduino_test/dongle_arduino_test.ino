#include <Wire.h>
#include <SoftwareSerial.h>
#define SLAVE_ADDRESS 0x08

SoftwareSerial gps(10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

Wire.begin(SLAVE_ADDRESS);
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

gps.begin(4800);

Serial.println("I2C Ready!");
delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void receiveData(int byteCount){
  int cmd = Wire.read();
  if (cmd == 1){
    sendToGPS();
  }
  else{
    readFromGPS();
  }
  
}

void sendData(){
  delay(100);
}

void sendToGPS(){
  Serial.println("Sending to GPS");
  gps.write("Turn On");
  Serial.println("Sent");
  Serial.println("");
}

void readFromGPS(){
  Serial.println("Listening from GPS");
  gps.write("Send Data");
  gps.listen();
  int data = gps.read();
  Wire.write(data);
  Serial.println("Sent to Pi");
}

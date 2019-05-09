#include <Wire.h>
#define SLAVE_ADDRESS 0x04
void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData(10));
  Wire.onRequest(requestData());
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void receiveData(int numBytes){
  while (Wire.available())
  {
    Serial.println(Wire.read());    
  }

void requestData(){
  
  Wire.send("Data Received");  
}

}

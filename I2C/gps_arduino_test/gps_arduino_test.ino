#include <SoftwareSerial.h>
SoftwareSerial one(10,11);
void setup() {
  // put your setup code here, to run once:
one.begin(4800);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  int cmd = one.read();
  String data = "";
  if (cmd == 0){
    one.listen();
    while (one.available()){
      data = data + one.read();
    }
    Serial.println(data);
  }
  else{
    char lengthOfData = data.length();
    char toSend[lengthOfData];
    data.toCharArray(toSend, lengthOfData);
    one.write(lengthOfData);
    for (int x = 0; x<lengthOfData; x++)
      one.write(toSend[x]);
  
  }
}

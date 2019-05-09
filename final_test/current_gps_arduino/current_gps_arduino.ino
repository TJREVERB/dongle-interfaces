#include <SoftwareSerial.h>
SoftwareSerial dongle(10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dongle.begin(4800);
Serial.println("SoftWare Serial Ready!");

}

void loop() {
  // put your main code here, to run repeatedly:
  dongle.listen();
  int val_received = dongle.read();
  if (val_received == ("Turn On"))
    Serial.println("Received Command to Turn On: GPS = ON");
  else{
    Serial.println("Received Command to Send Data");
    dongle.write('0');
  }
}

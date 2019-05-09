import time
import smbus2
from smbus2 import SMBusWrapper
address = 8
bus = smbus2.SMBus(1)
time.sleep(2)

while True:
    message = raw_input("Enter a message to send:")
    to_send = message.encode("utf-8")
    data_received = ""
    bus.write_byte_data(address, 1, 255)
    time.sleep(1)
    while True:
        data_received = bus.read_byte(address)
        if data_received != None:
            break
        time.sleep(1)
    print(data_received)
    


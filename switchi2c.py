from time import sleep
from smbus2 import SMBusWrapper
address = 0x08

sleep(2)

while True:
	message_to_send = input("Enter a Message to Send:")
	data = message_to_send.encode("utf-8")
	with SMBusWrapper(1) as bus:
		bus.write_i2c_block_data(address, 0x13, data)
 

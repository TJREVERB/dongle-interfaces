import time
import smbus2 
from smbus2 import SMBusWrapper
address = 0x08
time.sleep(2)

while True:
	with SMBusWrapper(1) as bus:
		val_received = bus.read_byte(address)
		print(val_received)
		time.sleep(1)

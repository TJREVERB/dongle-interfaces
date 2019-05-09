import smbus2
import time
from smbus2 import SMBusWrapper
address = 0x08
time.sleep(2)
count = 0
while True:
    with SMBusWrapper(1) as bus:
        bus.write_i2c_block_data(address, 0x01, [count])
	count = count + 1
        time.sleep(1)

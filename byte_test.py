import smbus
import time
from datetime import datetime
import struct
import subprocess

bus = smbus.SMBus(1)
time.sleep(1)
address = 0x08


def main():
    while True:
        command = input("Enter SEND (1) or DATA_REQUEST (2): ")
        if command == "SEND" or command == 1:
            send_command()
            break
        elif command == "DATA_REQUEST" or command == 2:
            send_request()
            break
        else:
            print("Try again.")
        time.sleep(1)


def send_command():
    to_send = 1 # struct.pack("hhl", 1, 2, 3)
    # command = 1
    # to_send = command.encode("utf-8")
    count = 0
    before_send = datetime.now()
    while True:
	flag = 0
	while flag == 0:
	    try:
       		bus.write_byte(address, to_send)
        	flag = 1
	    except:
	        subprocess.call(['i2cdetect', '-y', '1'])
	        flag = 0
	count += 1
        # now = datetime.now()
        # if (now - before_send).total_seconds() >= 1.0:
        #     break
	print "\t" + count
	if count >= 500:
	    break
	
    now = datetime.now()
    diff = (now - before_send).total_seconds() 
    print "Byte rate: " + str(count/(diff)/8) + " bits/sec"

    # call method on intermediate pi and wait for a response @max


def send_request():
    to_send = 2
    bus.write_byte(address, to_send)
    bus.read_byte(address)
    # call method on intermediate pi and wait for a response @max


if __name__ == "__main__":
    main()

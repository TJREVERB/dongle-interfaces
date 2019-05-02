import smbus
import time

bus = smbus.SMBus(0)
address = 0x04

def main():
    while (True):
        var = input("Enter a Number to Send:")
        writeBytes(var)
        time.sleep(1)
        returnVar = readBytes()
        print(returnVar)
        time.sleep(1)

def readBytes():
    value = bus.read_byte(address)
    return value

def writeBytes(value):
    bus.write_byte(address, value)

if __name__ == "__main__":
    main()
import smbus
import time

bus = smbus.SMBus(1)
address = 0x04

def main():
    while (True):
        var = input("Enter a number to send (-1 to exit): ")
        if(var=="-1"):
            break
        writeBytes(int(var))
        print("Sending: ", var)
        time.sleep(1)

        returnVar = readBytes()
        print("Recieved: ", returnVar)
        time.sleep(1)

def readBytes():
    value = bus.read_byte(address)
    return value

def writeBytes(value):
    bus.write_byte(address, value)

if __name__ == "__main__":
    main()

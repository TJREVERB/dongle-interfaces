import smbus
import time


bus = smbus.SMBus(1)
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
    to_send = [1,2]
    # command = 1
    # to_send = command.encode("utf-8")
    bus.write_i2c_block_data(address, 2, to_send)
    # call method on intermediate pi and wait for a response @max

def send_request():
    to_send = 2
    bus.write_byte(address, to_send)
    time.sleep(3)
    val_received = bus.read_byte(address)
  #  while(val_received == None):
  #      val_received = bus.read_byte_data(address)
    ASCII_to_char = chr(val_received)
    print(ASCII_to_char)
    # call method on intermediate pi and wait for a response @max

if __name__ == "__main__":
    main()
    

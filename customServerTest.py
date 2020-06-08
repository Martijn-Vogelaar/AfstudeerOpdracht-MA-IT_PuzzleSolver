import socket
import sys
HOST = '192.168.125.1'
PORT = 2020

controlGripper = 0
readCapacitive = 1
readInductive = 2
controlSlider = 3

open = 1
close = 0

unknownMessage = 5

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    my_bytes = bytearray()
    if len(sys.argv) > 1:
        if sys.argv[1] == "controlGripper" :
            my_bytes.append(controlGripper)
            if sys.argv[2] == "open":
                my_bytes.append(open)
            else: 
                my_bytes.append(close)
        elif sys.argv[1] == "readCapacitive":
            my_bytes.append(readCapacitive)
        elif sys.argv[1] == "readInductive":
            my_bytes.append(readInductive)
            my_bytes.append(int(sys.argv[2]))
        elif sys.argv[1] == "controlSlider":
            my_bytes.append(controlSlider)
            if sys.argv[2] == "open":
                my_bytes.append(open)
            else: 
                my_bytes.append(close)
        else:
            my_bytes.append(unknownMessage)
    else:
        my_bytes.append(unknownMessage)
    
    print(my_bytes)
    s.sendall(my_bytes)
    data = s.recv(1024)

print('Received', repr(data))

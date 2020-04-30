import socket
import sys
HOST = '192.168.125.1'
PORT = 2020

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(sys.argv[1].encode())
    data = s.recv(1024)

print('Received', repr(data))

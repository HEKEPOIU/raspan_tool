import socket

HOST = '192.168.50.90'
PORT = 9999

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

while True:
    data = s.recv(1024)
    print("server send : %s " % str(data, "utf-8"))

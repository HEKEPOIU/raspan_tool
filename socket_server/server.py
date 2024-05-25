import socket
import threading
import time

def handle_client(connect: socket, addr, delay: float = 0.5) -> None:
    while True:
        try:
            connect.send(bytes("hello!\n", "utf-8"))
            time.sleep(delay)
        except Exception as e:
            print(e)
            print("[*] Client %s disconnected" % str(addr))
            break
        connect.close()



bind_ip = "0.0.0.0"
bind_port = 9999
delay_time = 0.1

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # solution for "[Error 89] Address already in use". Use before bind()
server.bind((bind_ip, bind_port))

server.listen(5)

print("[*] Listening on %s:%d" % (bind_ip, bind_port))

try:
    while True:
        print("Waiting for client")
        conn, addr = server.accept()
        print("Client:", addr)
        
        t = threading.Thread(target=handle_client, args=(conn, addr, delay_time))
        t.start()
    
except KeyboardInterrupt:
    print("Stopped by Ctrl+C")
finally:
    if server:
        server.close()
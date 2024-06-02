import socket
import threading


class SocketServer:
    def __init__(self, bind_ip: str = "0.0.0.0", bind_port: int = 9999, delay_time: float = 0.1):
        self.bind_ip = bind_ip
        self.bind_port = bind_port
        self.delay_time = delay_time
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.data = None
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server.bind((self.bind_ip, self.bind_port))
        self.server.listen(5)
        print("[*] Listening on %s:%d" % (self.bind_ip, self.bind_port))

    def wait_for_client(self, handle: callable, ser) -> None:
        while True:
            try:
                conn, addr = self.server.accept()
                print(f"[*] Connection accepted from {addr}")
                t = threading.Thread(target=handle, args=(conn, addr, self.delay_time, ser))
                t.start()
            except Exception as e:
                print(e)
                pass

    def set_data(self, data:bytes) -> None:
        self.data = data


    def __del__(self):
        self.server.close()
        print("Server closed")
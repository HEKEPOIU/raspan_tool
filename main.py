import serial
import socket
import cmd_argument.arg_config as arg_config
import socket_server.server as server
import time
import threading


def _handle_client(conn: socket, addr, delay_time: float, ser) -> None:
    while True:
        try:
            mess = ser.readline()
            mess_list = str(mess)[2:-5].split(' ')
            for mess_data in mess_list:
                if mess_data.isnumeric():
                    # print(mess_data)
                    if int(mess_data) > 700:
                        print("hit!!")
            conn.send(mess)
            # print(mess_list)
        except Exception as e:
            print(e)
            print("[*] Client %s disconnected" % str(addr))
            break
    conn.close()

# default serial port
serialPort = "/dev/ttyACM0"
baudRate = 19200
delay_time = 0.1




if __name__ == '__main__':
    arg = arg_config.ArgConfig().get_args()
    if arg.serial:
        serialPort = arg.serial

    server = server.SocketServer(delay_time=delay_time)
    ser = serial.Serial(serialPort, baudRate, timeout=0.5)
    t = threading.Thread(target=server.wait_for_client, args=(_handle_client,ser))
    t.start()
    print("参数设置：串口=%s ，波特率=%d" % (serialPort, baudRate))
    t.join()
        
    ser.close()

    
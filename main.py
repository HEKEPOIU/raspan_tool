import serial


# serialPort = "/dev/ttyUSB0"
serialPort = "/dev/ttyACM0"
baudRate = 19200

ser = serial.Serial(serialPort, baudRate, timeout=0.5)

print("参数设置：串口=%s ，波特率=%d" % (serialPort, baudRate))


while 1:
    mess = str(ser.readline())[2:-5].split(' ')
    print(mess)

ser.close()
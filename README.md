# Raspan_Tool

---

## Implementation

This Project use Arduino UNO send data through Serial to raspberry pi, and use wifi connection to create an socket TCP Server, and the nano with wifi module on Car as Client to get data from server.

So That me can use the analog joystick, limit switcher to Control the car move(motor) and Shoot(razer).

if your razer hit the Arduino UNO side light sensor, buzzer will buz.

---

## Dependency

python3(3.10.6) not test in other version.
Arduino IDE

---

## How To Use

### Raspberry Pi

install Dependency and Build python venv

```sh
    git clone https://github.com/HEKEPOIU/raspan_tool.git
    cd raspan_tool
    sh prepare_env.sh # use sh script to install python and create venv.
```

Start Server

```sh
    sh start_server.sh # Start the server.
```

Download Arduino IDE And Upload the main.ino to Arduino UNO.

and change wifi_client.ino WIFI ssid and password to you wifi and upload to Arduino nano.


Keep Connect the UNO in PC, and unplug the nano.

Finally We wait nano connect to sever, so that we can control the car in UNO.

**_NOTE:_**  You should keep Raspberry Pi and nano in same WIFI

---

## How To Plug the pin

Please see the source code.

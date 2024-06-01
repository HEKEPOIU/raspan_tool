#!/bin/sh

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
getopt "serial" opt

serial=$opt

source venv/bin/activate

python3 main.py --serial $serial

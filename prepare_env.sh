#!/bin/sh

# 定義 PATH
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

sudo apt update
sudo apt install python3
sudo apt install python3-venv

python3 -m venv venv
SCRIPT_DIR=$(dirname "$0")
. "$SCRIPT_DIR/venv/bin/activate"

pip install -r requirement.txt

exit 0

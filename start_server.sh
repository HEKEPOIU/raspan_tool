#!/bin/sh

# 定義 PATH
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

# 處理命令行選項
ARGS=$(getopt -o s: --long serial: -n 'parse-options' -- "$@")
if [ $? != 0 ]; then
    echo "解析選項失敗." >&2
    exit 1
fi
eval set -- "$ARGS"

# 將選項及其參數提取到變量中
while true; do
    case "$1" in
    -s | --serial)
        serial="$2"
        shift 2
        ;;
    --)
        shift
        break
        ;;
    *)
        break
        ;;
    esac
done

# 獲取當前腳本所在的目錄
SCRIPT_DIR=$(dirname "$0")
# 使用絕對路徑啟動虛擬環境
. "$SCRIPT_DIR/venv/bin/activate"

echo $serial

python3 main.py -serial "$serial"

exit 0

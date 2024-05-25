import argparse 


class ArgConfig:
    def __init__(self):
        self.parser = argparse.ArgumentParser(description='argparse tutorial')
        self.parser.add_argument('-serial', type=str, help='Your arduino serial port')

    def get_args(self):
        return self.parser.parse_args()

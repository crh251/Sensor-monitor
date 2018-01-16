import serial
import socket
import time
import logging

logging.basicConfig(
    level=logging.DEBUG,
    format='%(asctime)s %(levelname)s %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S',
    filename='sensor.log',
    filemode='a+')


def open(cc2530):
    cc2530.open()


cc2530 = serial.Serial()
cc2530.port = '/dev/ttyUSB0'
cc2530.baudrate = 115200
while True:
    try:
        open(cc2530)
        break
    except Exception:
        logging.info('waiting 10 second...')
        time.sleep(10)

udpClient = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

HOST = '1**.1**.1**.2**'
PORT = 6666
ADDR = (HOST, PORT)

print('start working...')
while True:
    logging.info("waiting serial's data...")
    data = cc2530.readline()
    logging.info(data)
    udpClient.sendto(data, ADDR)

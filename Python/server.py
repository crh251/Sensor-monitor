import socket
import pymysql
import logging
import time

logging.basicConfig(
    level=logging.DEBUG,
    format='%(asctime)s %(levelname)s %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S',
    filename='sensor.log',
    filemode='a+')

logging.info('waiting 10 second for mysql...')
time.sleep(10)

udpSerSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

HOST = ''
PORT = 6666
ADDR = (HOST, PORT)
BUFFSIZE = 1024

logging.info('start working...')

udpSerSock.bind(ADDR)

logging.info("Bind UDP on %d..." % PORT)

conn = pymysql.connect(
    host='127.0.0.1',
    port=3306,
    user='***',
    passwd='***',
    db='sensor')
with conn.cursor() as cursor:
    while True:
        logging.info('waiting receive...')
        data, addr = udpSerSock.recvfrom(BUFFSIZE)
        data = data.decode('utf-8')

        # Temperature:20 Humidity:38 Dust:64.2
        Temperature, Humidity, Dust = data.split()
        Temperature = list(Temperature.split(':'))[1]
        Humidity = list(Humidity.split(':'))[1]
        Dust = list(Dust.split(':'))[1]
        logging.info(Temperature, Humidity, Dust)
        sql = "INSERT INTO `sensor_data`  VALUES (%s, %s, %s, now())"
        cursor.execute(sql % (Temperature, Humidity, Dust))
        conn.commit()

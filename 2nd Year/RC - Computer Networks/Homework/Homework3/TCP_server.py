import socket
import logging
import time

logging.basicConfig(format = u'[LINE:%(lineno)d]# %(levelname)-8s [%(asctime)s]  %(message)s', level = logging.NOTSET)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto=socket.IPPROTO_TCP)

port = 10000
adresa = '198.10.0.2'
server_address = (adresa, port)
sock.bind(server_address)
sock.listen(10)

try:
    while True:
        print("Waiting...")
        conn, address = sock.accept()
        while True:
            data = conn.recv(1024)
        conn.close()
finally:
    sock.close()
    logging.info('Socket closed')

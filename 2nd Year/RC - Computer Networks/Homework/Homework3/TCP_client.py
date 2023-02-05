import socket
import logging
import time

logging.basicConfig(format = u'[LINE:%(lineno)d]# %(levelname)-8s [%(asctime)s]  %(message)s', level = logging.NOTSET)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto=socket.IPPROTO_TCP)

port = 10000
adresa = '198.10.0.2'
server_address = (adresa, port)
image = "poza_client.png"

try:
    logging.info('Handshake cu %s', str(server_address))
    sock.connect(server_address)
    file = open(image, 'rb')
    msg = file.read()

    while True:
        sock.sendall(msg)
        data = sock.recv(1000)

finally:
    logging.info('closing socket')
    sock.close()

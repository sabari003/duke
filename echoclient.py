# import socket
# UDP_IP_ADDRESS="127.0.0.1" #


# UDP_PORT_NUMBER=6789
# Message=("Hello Server")
# bytesToSend = str.encode(Message)
# clientSock = socket.socket (socket.AF_INET, socket.SOCK_DGRAM)
# clientSock.sendto(bytesToSend ,(UDP_IP_ADDRESS,UDP_PORT_NUMBER))   
# messagefromserver=clientSock.recvfrom(1024)
# print(messagefromserver)

import socket
UDP_IP_ADDRESS="10.1.24.53"
UDP_PORT_NUMBER=678
Message=("Hello Server")
bytesToSend = str.encode(Message)
clientSock = socket.socket (socket.AF_INET, socket.SOCK_DGRAM)
clientSock.sendto(bytesToSend ,(UDP_IP_ADDRESS,UDP_PORT_NUMBER))   
messagefromserver=clientSock.recvfrom(1024)
print(messagefromserver)
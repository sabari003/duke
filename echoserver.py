"""import socket
UDP_IP_ADDRESS ="127.0.0.1" #10.1.24.53
UDP_PORT_NO=6789
serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))
print ("haiiiii helllo .. how are u ... i think ! server is listening")
while True:
 data, addr = serverSock.recvfrom(1024)
 print("message",data)
 serverSock.sendto(data,addr)
"""

#modified for remote connection                                                                                                                                                                                                                                                                                                                                                     
import socket
UDP_IP_ADDRESS ="10.1.24.47"
UDP_PORT_NO=678
serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))
print ("haiiiii helllo .. how are u ... i think ! server is listening")
while True:
 data, addr = serverSock.recvfrom(1024)
 print("message",data)
 serverSock.sendto(data,addr)

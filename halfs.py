import socket
localIP="127.0.0.1"
localPort=20000
buffersize=1024
msgFromServer="hello client"
bytesToSend =str.encode(msgFromServer)
TCPServerSocket=socket.socket(family=socket.AF_INET,type=socket.SOCK_STREAM)
TCPServerSocket.bind ((localIP,localPort))
TCPServerSocket.listen(1)
print("server listening")
TCPServerSocket,address=TCPServerSocket.accept()
while True:
   msg =TCPServerSocket.recv(2048).decode()
   print(">>",msg)
   message=input(">>")
   TCPServerSocket.send(message.encode())
   if(message =='q'):
     TCPServerSocket.close()



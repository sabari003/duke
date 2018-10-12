import socket
msgfromClient="hello server"
bytesToSend=str.encode(msgfromClient)
bufferSize=1024
TCPClientSocket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
TCPClientSocket.connect(("127.0.0.1",20000))
while True:
    msg=input(">>")
    TCPClientSocket.send(msg.encode())
    message=TCPClientSocket.recv(2048)
    print(">>",message.decode())
    if(msg=='q'):
      TCPClientSocket.close()


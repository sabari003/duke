###vkml
import socket
import threading
import time
tLock=threading.Lock()
shutdown=False
def receving(name,sock):
	while not shutdown:
		try:
			tLock.acquire()
			while True:
				data,addr=sock.recvfrom(1024)
				print(data)
		except:
			pass
		finally:
			tLock.release()
host=socket.gethostname()
port=0
server=(host,7000)
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((host,port))
s.setblocking(0)
rT=threading.Thread(target=receving,args=("RecvThread",s))
rT.start()

alias=input("Name:")
ali=str.encode(alias+":")
message=input(alias+"->")
msg=str.encode(message)
while 'q' not in str(msg):
	if "''" not in str(msg):
		d=(ali+msg)
		s.sendto(d,server)
	tLock.acquire()
	message=input(alias+"->")
	msg=str.encode(message)
	tLock.release()
	time.sleep(2)
	
shutdown=True
rT.join()
s.close()


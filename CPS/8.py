#client
import socket

s = socket.socket()
port = 12346
s.connect(('127.0.0.1'),port))
print(s.recv(1024).decode())
s.close()


#server
import socket

s = socket.socket()
port = 12346
s.bind(('',port))
print("socket blinded to %s" %(port))
s.listen(5)
print("server is ready to accept the connection")

while True:
	c,addr = s.accept()
	print("got connection from ",addr)
	c.send('Thank you for connecting'.encode())
	c.close()
	break

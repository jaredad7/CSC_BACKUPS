#Connect to vortex and get the data
#Send the sum of data back to the server
from socket import *
from struct import *
s = socket(AF_INET, SOCK_STREAM)
s.connect(("vortex.labs.overthewire.org", 5842))
num = 0
for i in range(4):
	data = s.recv(4)
	num += unpack("<I", data)[0]
s.send(pack("<I",(num & 0xFFFFFFFF)))
print(s.recv(2048))
s.close()

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("www.baidu.com", 80))
s.send(b"GET /index.html HTTP/1.0 \r\n")
data = s.recv(10000)
print(data)
s.close()


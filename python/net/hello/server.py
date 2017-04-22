#python3

import socket

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind((socket.gethostname(), 8090))
serversocket.listen(5)

while True:
    (clientsocket, address) = serversocket.accept()
    ct = client_thread(clientsocket)
    ct.run()





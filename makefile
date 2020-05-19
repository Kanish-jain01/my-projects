a.exe: server.o client.o
	gcc server.o client.o
server.o: server.c
	gcc -c server.c
client.o: client.c
	gcc -c client.c

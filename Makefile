
CC=g++
CFLAGS=-std=c++11
LFLAGS= -wall -lpthread
LDFLAGS=-lrt -lpcap
all:
	$(CC) $(CFLAGS) isabot.cpp -o isabot $(FLAGS) $(LDFLAGS)

# $make clean
clean:
	rm -f *.o
	rm isabot-sniffer


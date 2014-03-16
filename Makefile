#############
#Makefile for Dns_server
#############

all: Dns_Server
INCLUDE = ./include
LIBRARYDIR = ./lib
CC = g++
CFLAGS = -Wall

Dns_Server: main.o DnsServer.o
	$(CC) -o Dns_Server  -L$(LIBRARYDIR) main.o DnsServer.o -llucifer -lmuduo_base -lmuduo_net -lpthread

main.o: main.cc  DnsServer.h
	$(CC) -c -I$(INCLUDE) -L$(LIBRARYDIR) $(CFLAGS) main.cc -lmuduo_base -lmuduo_net -lpthread

DnsServer.o: DnsServer.cc
	$(CC) -c -I$(INCLUDE) -L$(LIBRARYDIR) $(CFLAGS) DnsServer.cc -llucifer

clean:
	-rm -f *.o
install:
	

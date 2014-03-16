#
#liblucifer.o:static library file 
#


LIB = lucifer
INCLUDE = ../
CC = g++ 
CFLAGS = -O2 -Wall
AR = ar

$(LIB): UdpServer.o
	$(AR) -rv liblucifer.a UdpServer.o

UdpServer.o: Session.h UdpServer.cc
	$(CC) -c -I$(INCLUDE) $(CFLAGS) UdpServer.cc

clean:
	rm *.a *.o

install:
	mv *.a ../../lib

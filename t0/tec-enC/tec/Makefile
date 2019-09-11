CC=gcc
CFLAGS=-std=c99 -W -Wall 

OBJ=autobus.o ps_standard.o

all: lib 

obj: ${OBJ}

lib: libtec.a 

clean:
	rm -f *.o

cleanall: clean
	rm -f *.a *.so

autobus.o: autobus.c autobus.h __internes.h

ps_standard.o: ps_standard.c ps_standard.h __internes.h

libtec.a: ${OBJ}
	ar -r $@ ${OBJ}


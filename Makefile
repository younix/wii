CFLAGS=-std=c99 -pedantic -Wall

.PHONY: all clean
all: in out
clean:
	rm -f in out *.o

in: in.o
	gcc -o $@ in.o

out: out.o
	gcc -o $@ out.o

.SUFFIXES: .c .o
.c.o:
	gcc $(CFLAGS) -c -o $@ $<

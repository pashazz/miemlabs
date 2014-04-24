all: binarywriter  binaryreader kr1

binint.o: binint.c binint.h
	gcc --std=c99 -ggdb -c binint.h binint.c

bindouble.o: bindouble.c bindouble.h
	gcc --std=c99 -ggdb -c bindouble.h bindouble.c

kr1: bindouble.o kr1_v1.c
	gcc --std=c99 -ggdb -o kr1_v1 bindouble.o kr1_v1.c

binarywriter: binint.o bindouble.o binarywriter.c binarywriter.h
	gcc --std=c99 -ggdb -o binarywriter binint.o bindouble.o binarywriter.h binarywriter.c


binaryreader: binint.o bindouble.o binaryreader.c
	gcc --std=c99 -ggdb -o binaryreader binint.o bindouble.o binaryreader.c

clean:
	rm -f binint.o bindouble.o problem binarywriter *.gch binaryreader

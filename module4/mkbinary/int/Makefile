all: binarywriter  binaryreader kr1

binint.o: binint.c binint.h
	gcc --std=c99 -ggdb -c binint.h binint.c


binarywriter: binint.o  binarywriter.c binarywriter.h
	gcc --std=c99 -ggdb -o binarywriter binint.o  binarywriter.h binarywriter.c


binaryreader: binint.o  binaryreader.c
	gcc --std=c99 -ggdb -o binaryreader binint.o  binaryreader.c

kr1:
	gcc --std=gnu99 -ggdb -o kr1_v2 binint.o kr1_v2.c
	gcc --std=c99 -ggdb -o kr1_v4 binint.o kr1_v4.c

clean:
	rm -f binint.o  binarywriter *.gch binaryreader kr1_v2 kr1_v4

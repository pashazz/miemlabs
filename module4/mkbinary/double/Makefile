all: binarywriter  binaryreader kr1


bindouble.o: bindouble.c bindouble.h
	gcc --std=c99 -ggdb -c bindouble.h bindouble.c

kr1: bindouble.o kr1_v1.c kr1_v3.c
	gcc --std=gnu99 -ggdb -o kr1_v3 bindouble.o kr1_v3.c
	gcc --std=c99 -ggdb -o kr1_v1 bindouble.o kr1_v1.c

binarywriter:  bindouble.o binarywriter.c binarywriter.h
	gcc --std=c99 -ggdb -o binarywriter bindouble.o binarywriter.h binarywriter.c


binaryreader: bindouble.o binaryreader.c
	gcc --std=c99 -ggdb -o binaryreader bindouble.o binaryreader.c

clean:
	rm -f  bindouble.o binarywriter *.gch binaryreader kr1_v1 kr1_v3

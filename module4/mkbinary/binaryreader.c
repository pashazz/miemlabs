//binaryreader.c  -> test created binary files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "bindouble.h"

void showUsage(const char* progname);


int main(int argc, char* argv[])
{
  if (argc == 2)
    {
      FILE* fd;
      if (fd = fopen(argv[1], "r"))
        {
          printBinaryData(fd);
          fclose(fd);

          return 0;
        }
      else
        {
          fprintf(stderr,"fopen falied with error: %s\n",  strerror(errno));
          return errno;
        }
    }
  else
    {
      showUsage(argv[0]);
      return -1;
    }
}

void showUsage(const char* progname)
{
  printf("BinaryReader is the part of assignment 9\n");
  printf("\tUsage: %s <filename>\n", progname);
  printf("\tReads binary files containing integers (created by BinaryWriter)\n");
}

#include "binarywriter.h"

int main(int argc, char* argv[])
{
  //check argv
  if (argc == 2) //first arg is filename
    {
      return writeToFile(argv[1]);
    }
  else
    {
      showUsage(argv[0]);
      return 1;
    }
}

int writeToFile(const char *filename)
{
  FILE *fd = fopen(filename, "wb");
  //read portion from stdin
  int eof;
  size_t bufsize;
  for(;;)
    {
      MyDataType *buf = readStdin(&eof, &bufsize);
      size_t wr = writeObj(bufsize, buf, fd);
      if (wr != bufsize)
        {
          fclose(fd);
          return -1;
        }
      printf("%d objects has been written successfully \n", wr);
      if (eof)
        break;
    }

  fclose(fd);
  return 0;
}

MyDataType* readStdin(int *eof, size_t *bufsize)
{
  *eof = 0;
  MyDataType *buf = calloc(INTBUFSIZE, sizeof(MyDataType));
  for (int i = 0; i < INTBUFSIZE; ++i)
    {
      int nobj  = scanf(MYFORMAT, buf+i);
      if (nobj == EOF)
        {
          *eof = 1;
          if (i != INTBUFSIZE - 1)
            {
              buf = realloc(buf, (i+1)*sizeof(MyDataType));
              *bufsize = i;
            }
          else
            *bufsize = INTBUFSIZE;
          return buf;
        }
    }
  *bufsize = INTBUFSIZE;
  return buf;
}

void showUsage(const char* progname)
{
  printf("BinaryWriter is part of assignment 8\n\n");
  printf("USAGE:\n");
  printf("\t %s <file name to write objects>\n", progname);
}

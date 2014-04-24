#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "bindouble.h"


void showUsage(const char*);//name of program
FILE* openFile(const char *fileName);
void perform(double *objs, size_t size, FILE *fd);

int main(int argc, char* argv[])
{
  /*
   n: number of write operations to the end of file
   argv[1]: filename
  */
  if (argc == 2)
    {
      FILE *fd = openFile(argv[1]);
      if (!fd)
        return errno;
      size_t size;
      double *data = readObj(&size, fd);
      perform(data, size, fd);
      free(data);
      fclose(fd);
    }
  else
    {
      showUsage(argv[0]);
      return -1;
    }
}

void showUsage(const char* progname)
{
  printf("usage: %s <file>\n", progname);
}

void perform(double* objs, size_t size, FILE *fd)
{ //warning: non-portable
  int count  = 0;//count of positives
  for(size_t i = 0; i<size; ++i)
    {
      if(objs[i] > 0)
        {
          count++;
        }
    }
  if (size == 0)
    return;

  if (count == 0)
    { //copy last element to 1st position
      rewind(fd);
      fwrite(objs+(size-1), sizeof(double), 1, fd); //-1 => fd
      if (size>1)
        fwrite(objs+1, sizeof(double), size-1, fd); //2..n elems => fd
    }
  else
    {
      long offset = -(count*sizeof(double));
      fseek(fd, offset, SEEK_END);
      ftruncate(fileno(fd), ftell(fd));
    }
}
FILE* openFile(const char *fileName)
{
  FILE* fd = fopen(fileName, "r+");
  if (!fd)
    {
      fprintf(stderr, "openFile: I/O Error: %s", strerror(errno));
    }
  return fd;
}

#include <string.h>
#include <errno.h>
#include "binint.h"
void showUsage(const char*);//name of program
FILE* openFile(const char *fileName);
void perform(int *objs, size_t size, FILE *fd);

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
      int *data = readObj(&size, fd);
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

void perform(int* objs, size_t size, FILE *fd)
{
  int count  = 0;//count of odds
  for(size_t i = 0; i<size; ++i)
    {
      if(objs[i] % 2 == 1)
        {
          count++;
        }
    }
  if (size == 0)
    return;

  if (count == 0)
    { //write last element
      rewind(fd);
      fwrite(objs+(size-1), sizeof(int), 1, fd); //last => fd
      if (size>2)
        fwrite(objs+1, sizeof(int), size-2, fd); //2..n-1 elems => fd
      if (size>1)
        fwrite(objs, sizeof(int), 1, fd); //1st -> last pos.
    }
  else
    { //we are at the end
      int x = 0;
      for (int i = 0; i<count; i++)
        fwrite(&x, sizeof(int), 1, fd);
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

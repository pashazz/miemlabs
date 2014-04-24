#include <string.h>
#include <errno.h>
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
{
  int count  = 0;//count of negatives
  double sum_neg = 0.0;
  for(size_t i = 0; i<size; ++i)
    {
      if(objs[i] < 0)
        {
          count++;
          sum_neg += objs[i];
        }
    }
  if (size == 0)
    return;

  if (count == 0)
    { //write 0 as 1st element
      rewind(fd);
      fwrite(&count, sizeof(double), 1, fd); //0 => fd
      if (size>1)
        fwrite(objs+1, sizeof(double), size-1, fd); //2..n elems => fd
    }
  else
    { //we are at the end
      sum_neg = sum_neg/count;
      fwrite(&sum_neg, sizeof(double), 1, fd);
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

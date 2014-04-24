/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #9
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

#include "problem.h"
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
  /*
   n: number of write operations to the end of file
   argv[1]: filename
  */
  if (argc == 3)
    {
      int n = atoi(argv[2]);
      if (n < 1)
        {
          fprintf(stderr, "invalid argument 2\n");
          return -1;
        }
      FILE *fd = openFile(argv[1]);
      if (!fd)
        return errno;
      writeObjects(sumSquaresOf(fd), n, fd);
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
  printf("This is the program to solve the whole problem\n");
  printf("Usage:\n\t%s <filename> <n>\n", progname);
  printf("\n\t<filename> - file name to read and write (existing)");
  printf("\n\t<n> - how much sums of the squares we should write to the end of file\n");
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

int sumSquaresOf(FILE *fd)
{
  int s = 0;
  size_t size;
  int *data = readInt(&size, fd);
  for (size_t i = 0; i < size; i++)
    {
      s += data[i]*data[i];
    }
  free(data);
  return s;
}

void writeObjects(int obj, int n, FILE* fd)
{
  int *data = calloc(n, sizeof(int));
  for (size_t i = 0; i < n; i++)
    data[i] = obj;

  int written  = writeInt(n, data, fd);
  free(data);
  printf("%d objects has been written\n", written);
}

/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #9
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

#include "binint.h"
size_t  write (size_t n, MyDataType* data, FILE* file)
{
  size_t written = fwrite(data, sizeof(MyDataType), n, file);
  if (written != n)
    //call to strerror to determine the error
    fprintf(stderr, "writeInt: I/O Error: %s\n", strerror(errno));

  clearerr(file);
  return written;
}

MyDataType* read (size_t *size, FILE *file)
{
  *size = INTBUFSIZE;
 MyDataType* data = calloc(INTBUFSIZE, sizeof(MyDataType));

  for (size_t pos = 0;;)
    {
      pos = fread(data, sizeof(MyDataType), INTBUFSIZE, file);
      if (feof(file))
        {
          if (pos < *size)
            {
              data = realloc(data, pos*sizeof(MyDataType));
              *size = pos;
            }
          clearerr(file);
          break;
        }
      else if (ferror(file))
        {
          fprintf(stderr, "readInt: I/O Error: %s\n", strerror(errno));
          *size = 0;
          clearerr(file);
          return NULL;
        }
      else //there's more
        {
          *size += INTBUFSIZE;
          data = realloc(data, (*size)*sizeof(MyDataType));
        }
    }
  return data;
}

void printBinaryData (FILE* fd)
{
  size_t size;
  MyDataType *data = read(&size, fd);
  for (size_t i = 0; i < size; ++i)
    {
      printf(MYFORMAT, data[i]);
      printf(" ");
    }
  free(data);
  printf("\n");
}

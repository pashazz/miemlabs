#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//var1 #1
FILE* openFile(const char*); //open file for reading
FILE* tempFile(char*); //create temporary file and open it for writing
void printUsage(const char* progname);
char* getLine(int *size, FILE *fd); //get line from file

#define BUFFERSIZE 100
int main(int argc, char** argv)
{
  if (argc != 2)
    {
      printUsage(argv[0]);
      return -1;
    }
  FILE *f = openFile(argv[1]);
  if (!f)
    return 1;
  char *tempname;
  tempname = calloc(256, sizeof(char));

  FILE *temp = tempFile(tempname);
  if (!temp)
    return 1;
  int size;
  char *srcLine = getLine(&size, f);
  if (!srcLine)
    {
      printf("Empty file\n");
      return -1;
    }

  char *destLine = calloc(size, sizeof(char));
  int srcIndex = 0, destIndex = 0;
  while(srcLine[srcIndex] != '\0')
    {
      if (isdigit(srcLine[srcIndex]))
        {
          destLine[destIndex] = '*';
          srcIndex++;
          destIndex++;
          while (srcLine[srcIndex] != '0' && isdigit(srcLine[srcIndex]))
            srcIndex++;
        }
      else
        {
          destLine[destIndex] = srcLine[srcIndex];
          srcIndex++;
          destIndex++;
        }
    }
  if(fputs(destLine, temp) == EOF)
    {
      fprintf(stderr, "Failed to write to temporary file. Exiting.\n");
      return 1;
    }

  free(srcLine);
  free(destLine);

  while(srcLine = getLine(&size, f))
    {
      fputs(srcLine, temp);
      free(srcLine);
    }
  fclose(f);
  fclose(temp);
  remove(argv[1]);
  if (rename(tempname, argv[1]) == -1)
    {
      fprintf(stderr, "Failed to rename %s to %s: %s", tempname, argv[1], strerror(errno));
      return 1;
    }
  return 0;
}

void printUsage(const char* progname)
{
  printf("Usage: %s <filename>\n", progname);
}

char* getLine(int *size, FILE *fd)
{
  int len = 0;
  char *line = calloc(BUFFERSIZE, sizeof(char));
  len = BUFFERSIZE;
  if (fgets(line, len, fd) == NULL) //EOF
    {
      free(line);
      return NULL;
    }
  else
    {
      int n = strlen(line);
      if (line[n-1] == '\n')
        {
          len = n+1;
          if (len != BUFFERSIZE)
            line = realloc(line, len*sizeof(char));
        }
      else
        {
          for (;;)
            {

              char* concatline = calloc(BUFFERSIZE, sizeof(char));
              if (fgets(concatline, BUFFERSIZE, fd) == NULL) //EOF
                {
                  free(concatline);
                  break;
                }
              int concatsize = strlen(concatline); //we've already got \0 into account
              len += concatsize;
              line = realloc(line, len*sizeof(char));
              strcat(line, concatline);
              if (concatline[concatsize - 1] == '\n')
                {
                  free(concatline);
                  break;
                }
              else
                free(concatline);
            }
        }
      *size = len;
      return line;
    }
}

FILE* openFile(const char *name)
{
  FILE *f = fopen(name, "r");
  if (errno == ENOENT)
    {
      fprintf(stderr, "openFile: no such file: %s\n", name);
      return NULL;
    }
  else if (errno == EACCES)
    {
      fprintf(stderr, "openFile: permission denied: %s\n", name);
      return NULL;
    }
  return f;
}

FILE *tempFile(char *fname)
{
  /* //check TEMP environment variable (mostly windows)
  char* tempenv;
  if (!(tempenv = getenv("TEMP")))
    //check TMPDIR (POSIX-complaint)
    if (!(tempenv = getenv("TMP")))
      //force to /tmp
      tempenv = "/tmp";
  strcat(fname, tempenv);
  strcat(fname, "/");
  strcat(fname, "miemkr");
  */
  strcat(fname, "temp");
  FILE *f = fopen(fname, "w");
   if (errno == EACCES)
    {
      fprintf(stderr, "openFile: permission denied: %s\n", fname);
      return NULL;
    }
  return f;
}

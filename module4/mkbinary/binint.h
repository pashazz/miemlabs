#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define INTBUFSIZE 10
#define MYFORMAT "%d"
typedef int MyDataType;
/** write
 *
 * writes a number of binary int objects into a file
 * returns a number of written objects
 */
size_t  write (size_t n, MyDataType* data, FILE *file);

/** read
 *
 * reads all the binary int objects into data array from a file,
 * storing the number of objects in size (not null)
 *
 * returns array of objects
 */
MyDataType* read(size_t *size,  FILE *file);

/** printBinaryData
 *
 *  print binary data from fd to stdin
 */

void printBinaryData (FILE* fd);

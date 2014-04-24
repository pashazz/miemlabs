/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #9
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

//problem.h is here

#include <stdio.h>
#include <stdlib.h>
#include "binint.h"
#include <math.h>

/** writeObjects
 *
 * Write n objects obj into binary stream fd
 */
void writeObjects(int obj, int n, FILE* fd);

/** showUsage
 *
 * print usage info
 */
void showUsage(const char* progname);

/** openFile
 *
 * open file for reading and writing;
 */
FILE* openFile(const char *fileName);

/** sumSquaresOf
 *
 * returns sum of squares of objects of file fd
 */
int sumSquaresOf(FILE *fd);

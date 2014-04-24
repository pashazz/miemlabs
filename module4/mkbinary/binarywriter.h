/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #9
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

#include <stdio.h>
#include <stdlib.h>
#include "binint.h"

/** writeToFile
 *
 * write binary intstream to file specified by filename
 * return exit code (-1 if IO error)
 */
int writeToFile(const char *filename);

/** showUsage
 *
 * show usage %)
 */

void showUsage(const char* progname);

/** readStdin
 *
 * read INTBUFSIZE portion of stdin. bufsize = INTBUFSIZE if not EOF
 */
MyDataType* readStdin(int *eof, size_t *bufsize);

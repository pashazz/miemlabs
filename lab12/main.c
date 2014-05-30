/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #N
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

#include "linkedlist.h"

int main()
{
  Polynomial *p = createPolynomial(NULL, 0);
  if (!p)
    {
      printf("No polynomial entered. Exiting\n");
      return -1;
    }
  printf("Input: ");
  printPolynomial(p);
  printf("Enter the coefficient for removing: ");
  int coeff;
  scanf("%d", &coeff);
  p = removeCoefficient(coeff, p);
  printf("Result: ");
  printPolynomial(p);
  return 0;
}

/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #12
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
  struct linked_list * next;
  unsigned int degree;
  int coeff;
};

typedef struct linked_list Polynomial;


void printPolynomial(Polynomial* pol);
Polynomial* createPolynomial(unsigned int *coeffs, int coeffsCount);
void cleanPolynomial(Polynomial* pol);
Polynomial* removeCoefficient(int coefficient, Polynomial* pol);

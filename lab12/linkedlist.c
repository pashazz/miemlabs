#include "linkedlist.h"
#include <string.h>

void printPolynomial(Polynomial* pol)
{
  static int nosign = 1;
  if (!pol)
    {
      printf("\n");
      nosign = 1;
      return;
    }
  char format[10];
  memset(format, '\0', 10);
  if (pol->coeff == 1)
    {
      if (!nosign)
        strcat(format, " + ");
      if (pol->degree == 0)
        strcat(format, "1");
    }
  else if (pol->coeff == -1)
    {
      strcat(format, " - ");
      if (pol->degree == 0)
        strcat(format, "1");
    }
  else
    {
      if (nosign)
        strcat(format, "%d");
      else
        strcat(format, " %+d");
    }
  if (pol->degree == 1)
    strcat(format, "x");
  else if (pol->degree > 1)
    strcat(format, "x^%d");

  switch(pol->coeff)
    {
    case 1: case -1:
      printf(format, pol->degree);
      break;
    default:
      printf(format, pol->coeff, pol->degree);
    }

  nosign = 0;
  printPolynomial(pol->next);
}

Polynomial* createPolynomial(unsigned int *coeffs, int coeffsCount)
{
  Polynomial* pol = malloc(sizeof(struct linked_list));
  int input;
  printf("Enter the degree of polynomial (negative to stop): ");

  if ((!scanf("%d", &input)) || input < 0)
    {
      free(pol);
      if (coeffs)
        free(coeffs);
      return NULL;
    }
  if (!coeffs)
    {
      coeffs = calloc(1, sizeof(int));
      coeffsCount = 1;
    }
  else
    {
      for (int i = 0; i < coeffsCount; ++i)
        if (coeffs[i] == input)
          {
            printf("This degree has already entered. Enter another degree\n");
            free(pol);
            return createPolynomial(coeffs, coeffsCount);
          }
      coeffs = realloc(coeffs,++coeffsCount*sizeof(int));
    }

  coeffs[coeffsCount-1] = input;
  pol->degree = input;
  printf("Enter the coefficient[%d] (0 to stop):", pol->degree);

  if ((!scanf("%d", &input)) || input == 0)
    {
      free(pol);
      if (coeffs)
        free(coeffs);
      return NULL;
    }
  pol->coeff = input;
  pol->next = createPolynomial(NULL, 0);
  return pol;
}

void cleanPolynomial(Polynomial* pol)
{
  Polynomial* p_next = pol->next;
  free(pol);
  if (p_next)
    cleanPolynomial(p_next);
}


Polynomial* removeCoefficient(int coefficient, Polynomial* pol)
{
  while(pol) //set start of the new list
    {
      if (pol->coeff != coefficient)
        break;
      else
        {
          Polynomial* p_next = pol->next;
          free(pol);
          pol = p_next;
        }
    }
  if (!pol)
    return NULL;

  Polynomial* p = pol;
  Polynomial* p_prev;
  while(p_prev = p, p = p->next)
    {
      if(p->coeff == coefficient)
        {
          Polynomial* p_next = p->next;
          p_prev->next = p_next;
          free(p);
          p = p_prev;
        }
    }
  return pol;
}

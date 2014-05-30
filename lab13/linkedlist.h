/* Moscow Institute of Electronics and Mathematics
   The Faculty of Applied Mathematics

   Assignment #13
   Language: C99
   Compiler: gcc

   Student: Pavel Borisov
   Group: Applied Informatics 11
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  struct Node* prev;
  struct Node* next;
  char* word;
};

typedef struct Node Word;

Word* createLinkedListFromInput();

void freeWord(Word* w);
void freeAll(Word *w);

void printSentence(Word *w); //print the sentence

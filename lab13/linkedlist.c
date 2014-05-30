#include "linkedlist.h"

Word* createLinkedListFromInput()
{
  Word *head = malloc(sizeof(Word));
  head->next = NULL;
  head->prev = NULL;

  Word *prevWord = head->prev;
  Word *currWord = head;
  //gather the input
  char *line = NULL;
  int nbytes = 0;
  getdelim(&line, &nbytes, '.', stdin); //this one will gather all input before but '.'
  int currSym = 0;
  while(1)
    {
      char *text;
      sscanf(line+currSym, "%ms", &text);
      currSym += strlen(text);
      currWord->word = text;

      //remove whitespace
      while (line[currSym] == ' ' || line[currSym] == '\n' || line[currSym] == '\t') currSym++;

      if (line[currSym] == '\0')
        {
          text[strlen(text) - 1] = '\0'; //remove unusual dot.
          break;
        }
      //double-linked list;
      prevWord = currWord;
      currWord = malloc(sizeof(Word));
      prevWord->next = currWord;
      currWord->prev = prevWord;
      currWord->next = NULL;
    }
  free(line);
  return head;
}

void freeWord(Word *w)
{
  free(w->word);
  free(w);
 }

void freeAll(Word *w)
{
  Word* w_next = w->next;
  if (w_next)
    freeAll(w_next);

  freeWord(w);
}

void printSentence(Word *w)
{
  printf("%s", w->word);
  if (w->next)
    {
      printf(" ");
      printSentence(w->next);
    }
  else
    printf(".\n");
}

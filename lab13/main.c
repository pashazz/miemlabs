#include "linkedlist.h"

Word* insertWordCopyBeforeMaxLength(Word *w);

Word* maxLength(Word *w);


int main()
{
  printf("Enter the sentence, ending with .\n");
  Word *sent = createLinkedListFromInput();
  printf("You have entered:\n");
  printSentence(sent);
  printf("Result:\n");
  sent = insertWordCopyBeforeMaxLength(sent);
  printSentence(sent);
  return 0;
}


Word *maxLength(Word *w)
{
  Word *maxlenWord = w;
  int length = strlen(maxlenWord->word);
  Word *currWord = w->next;
  while(currWord)
    {
      int curlen = strlen(currWord->word);
      if (curlen > length)
        {
          length = curlen;
          maxlenWord = currWord;
        }
      currWord = currWord->next;
    }
  return maxlenWord;
}

Word * insertWordCopyBeforeMaxLength(Word *w)
{
  Word* maxWord = maxLength(w);
  Word* newWord = malloc(sizeof(Word));
  char *text = calloc(strlen(maxWord->word)+1, sizeof(char));
  strcpy(text, maxWord->word);
  newWord->word = text;

  newWord->prev = maxWord->prev;
  newWord->prev->next = newWord;

  newWord->next = maxWord;
  maxWord->prev = newWord;
  if (newWord->prev) //not first
    return w;
  else //first
    return newWord;
}

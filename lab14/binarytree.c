#include "binarytree.h"

BstNode*  makeTree(FILE* fd)
{
  char *rootWord = (char*) calloc(WORDSIZE, sizeof(char));
  if (!fscanf(fd, "%s", rootWord))
    return NULL;
  BstNode *root = createNodeFromWord(rootWord);

  while(1)
    {
      char *word = (char*) calloc(WORDSIZE, sizeof(char));
      if (fscanf(fd, "%s", word) == 1)
        insertNode(root, word);
      else
        break;
    }
  return root;
}

void insertNode (BstNode *root, char *word)
{
  int n = strcmp(word, root->word);
  if (n == 0)
    root->numberOfOcc++;
  else if (n < 0)
    {
      if (!root->left)
        root->left = createNodeFromWord(word);
      else
        insertNode(root->left, word);
    }
  else if (n > 0)
    {
      if (!root->right)
        root->right = createNodeFromWord(word);
      else
        insertNode(root->right, word);
    }
}

BstNode* createNodeFromWord(char *word)
{
  BstNode *node = (BstNode*) malloc(sizeof(BstNode));
  node->word = word;
  node->numberOfOcc = 1;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void preorder(BstNode *root, int level) //DLR
{
  if (!root)
    return;
  printWord(root, level);
  preorder(root->left, level+1);
  preorder(root->right, level+1);
}

void inorder(BstNode *root, int level) //LDR
{
  if (!root)
    return;
  inorder(root->left, level+1);
  printWord(root, level);
  inorder(root->right, level+1);
}

void postorder(BstNode *root, int level)
{
  if (!root)
    return;
  postorder(root->left, level+1);
  postorder(root->right, level+1);
  printWord(root, level);
}


void printWord (BstNode *word, int level)
{
  for(int i = 0; i < level; ++i)
    printf("  ");
  printf("%s (%d)\n", word->word, word->numberOfOcc);
}

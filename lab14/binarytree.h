#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDSIZE 21
 struct Node{
   char* word;
   int numberOfOcc;
   struct Node *left;
   struct Node *right;
};
typedef struct Node BstNode;

BstNode*  makeTree(FILE *fd);
void insertNode(BstNode *root, char *word);
BstNode* createNodeFromWord(char *word);

//Print with various methods
//Data; Left; Right
void preorder(BstNode *root, int level);

//Left; Data; Right;
void inorder(BstNode *root, int level);

//Left; Right; Data;
void postorder(BstNode *root, int level);

void printWord(BstNode *word, int level);

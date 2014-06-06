#include "binarytree.h"

int main(int argc, char **argv)
{
  if (argc != 2)
    {
      fprintf(stderr, "%s: wrong commandline\n", argv[0]);
      return -1;
    }

  FILE *fd = fopen(argv[1], "r");
  if (!fd)
    {
      perror("Failed to open file");
      return -2;
    }
  BstNode *root = makeTree(fd);
  fclose(fd);
  printf("Preorder:\n\n");
  preorder(root, 0);

  printf("\nInorder: \n\n");
  inorder(root, 0);

  printf("\nPostorder: \n\n");
  postorder(root, 0);
  return 0;
}

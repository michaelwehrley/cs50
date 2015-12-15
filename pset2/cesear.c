// jharvard@appliance (~/Dropbox/pset2): ./caesar 13
// Be sure to drink your Ovaltine!
// Or fher gb qevax lbhe Binygvar!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
  if (argc != 2) {
    printf("%s\n", "Whoops! Please add your cesear key.");
    return 1;
  } else {
    int count;
    int cipher;

    cipher = atoi(argv[1]);
    if (cipher == 0 || cipher < 0)
    {
      printf("Try again: A cesear key must be a positive integer.\n");
    }
    else
    {
      int k = cipher % 26;

      // fix this someday when I understand life.
      char phrase[1000] = "";

      scanf("%[^\n]s", phrase);
      count = strlen(phrase);
      for (int i = 0; i < count; ++i)
      {
        if (isalpha(phrase[i]))
        {
          // upper
          // lower
          printf("%c", phrase[i] + k);
        }
        else
        {
          printf("%c", phrase[i]);
        }
      }
      printf("\n");
      return 0;
    }
  }
}

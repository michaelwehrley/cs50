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
    printf("%s\n", "Please add your cesear key");
    return 1;
  } else {
    int count;
    int k = atoi(argv[1]);
    char phrase[1000] = "Single";

    scanf("%[^\n]s", phrase);
    count = strlen(phrase);
    for (int i = 0; i < count; ++i)
    {
      printf("%c", phrase[i] + k);
    }
    printf("\n");
    return 0;
  }
}

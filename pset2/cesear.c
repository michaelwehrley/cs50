// jharvard@appliance (~/Dropbox/pset2): ./caesar 13
// Be sure to drink your Ovaltine!
// Or fher gb qevax lbhe Binygvar!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int const ALPHABET_LENGTH = 26;

char decoded_char(char input, int upper_bound);

int main(int argc, char const *argv[])
{
  int const NECESSARY_INPUTS = 2;
  if (argc != NECESSARY_INPUTS) {
    printf("%s\n", "Whoops! Please add your cesear key.");
  } else {
    int cipher = atoi(argv[1]);
    // fix this someday when I understand life.
    char phrase[1000] = "";
    if (cipher > 0) {
      int k;
      int length;

      k = cipher % ALPHABET_LENGTH;
      scanf("%[^\n]s", phrase);
      length = strlen(phrase);
      for (int i = 0; i < length; ++i) {
        char c;

        if (isalpha(phrase[i])) {
          int const ASCII_UPPER_Z = 90;
          int const ASCII_LOWER_Z = 122;
          char coded_char;

          coded_char = phrase[i] + k;
          if (isupper(phrase[i]))
          {
            c = decoded_char(coded_char, ASCII_UPPER_Z);
          }
          else
          {
            c = decoded_char(coded_char, ASCII_LOWER_Z);
          }
        }
        else
        {
          c = phrase[i];
        }
        printf("%c", c);
      }
      printf("\n");
    }
    else
    {
      printf("Try again: A cesear key must be a positive integer.\n");
    }
  }
}

char decoded_char(char input, int upper_bound) {
  if (input > upper_bound) {
    return input - ALPHABET_LENGTH;
  } else {
    return input;
  }
}

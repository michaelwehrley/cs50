// jharvard@appliance (~/Dropbox/pset2): ./vigenere bacon
// Meet me at the park at eleven am
// Negh zf av huf pcfx bt gzrwep oz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int const argc, char const *argv[])
{
  int const NECESSARY_INPUTS = 2;
  if (argc != NECESSARY_INPUTS) {
    printf("%s\n", "Whoops! Please add your vigenere cipher word.");
  } else {
    printf("%s\n", argv[1]);
    char const* cipher = argv[1];
    int cipher_length = strlen(cipher);
    // printf("%d\n", cipher_length);
    // printf("%s\n", cipher);
    // printf("%c ", *(cipher));
    // printf("%p\n", &cipher[0]);
    // printf("%c ", *(cipher + 1));
    // printf("%p\n", &cipher[1]);
    // printf("%c ", *(cipher + 2));
    // printf("%p\n", &cipher[2]);
    // printf("%c ", *(cipher + 3));
    // printf("%p\n", &cipher[3]);
    // printf("%c ", *(cipher + 4));
    // printf("%p\n", &cipher[4]);

    // char* phrase; ?
    // char* phrase = ""; ?
    char phrase[1000] = "";
    scanf("%[^\n]s", phrase);
    int phrase_length = strlen(phrase);
    for (int i = 0; i < phrase_length; ++i)
    {
      int change;
      char letter;
      if (isupper(phrase[i])) {
        // change = cipher[i % cipher_length] - '@';
        change = cipher[i] - '@';
        letter = phrase[i] + change;
        if (isupper(letter)) {
          printf("%c", letter);
        } else {
          printf("%c", letter - 26);
        }
      } else {
        printf("%d", i % cipher_length);
        // change = cipher[i % cipher_length] - '`';
        change = cipher[i] - '`';
        letter = phrase[i] + change;
        if (islower(letter)) {
          printf("%c", letter);
        } else {
          printf("%c", letter - 26);
        }
      }
    }
    printf("\n");
  }
  return 0;
}

// jharvard@appliance (~/Dropbox/pset2): ./vigenere bacon
// Meet me at the park at eleven am
// Negh zf av huf pcfx bt gzrwep oz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int const argc, char const *argv[])
// find length of pointer value
{
  int const NECESSARY_INPUTS = 2;
  if (argc != NECESSARY_INPUTS) {
    printf("%s\n", "Whoops! Please add your vigenere cipher word.");
  } else {
    // determine cipher word length
    int cipher_length = 0;
    int i = 0;
    while (*(argv[1] + i)) {
      cipher_length++;
      i++;
    }

    char message[] = "";
    scanf("%[^\n]s", message);
    int message_length = strlen(message);
    printf("%d\n", message_length);

    for (int i = 0; i < message_length; ++i)
    {
      int change;
      int j;
      char letter;

      if (i < cipher_length) {
        j = i;
      } else {
        j = i % cipher_length;
      }

      change = *(argv[1] + j) - 'a' + 1;
      if (isupper(message[i])) {
        letter = message[i] + change;
      } else {
        letter = message[i] + change;
      }
      printf("%c", letter);
    }
    printf("\n");
  }
  return 0;
}

// cipher_positionharvard@appliance (~/Dropbox/pset2): ./vigenere bacon
// Meet me at the park at eleven am
// Negh zf av huf pcfx bt gzrwep oz

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calc_cipher_length(char const *ptr);
int cipher_position(int position, int const cipher_length);

int main(int const argc, char const *argv[]) {
  int const NECESSARY_INPUTS = 2;
  int const ALPHABET_LENGTH = 'z' - 'a' + 1;
  if (argc != NECESSARY_INPUTS) {
    printf("%s\n", "Whoops! Please add your vigenere cipher word.");
  } else {
    int cipher_length = calc_cipher_length(argv[1]);

    // `char message[] = "";` conflicts with address of `cipher_length`
    char message[1000] = "";
    scanf("%[^\n]s", message);
    int message_length = strlen(message);
    int j = 0;
    for (int i = 0; i < message_length; i++) {
      int letter;
      if (isupper(message[i])) {
        int position = cipher_position(j, cipher_length);
        int change = *(argv[1] + position) - 'a';
        letter = message[i] + change;
        if (letter > 'Z') {
          letter = letter - ALPHABET_LENGTH;
        }
        j++;
      } else if (islower(message[i])) {
        int position = cipher_position(j, cipher_length);
        int change = *(argv[1] + position) - 'a';
        letter = message[i] + change;
        if (letter > 'z') {
          letter = letter - ALPHABET_LENGTH;
        }
        j++;
      } else {
        letter = message[i];
      }
      printf("%c", letter);
    }
    printf("\n");
  }
  return 0;
}

int calc_cipher_length(char const *ptr) {
  int length = 0;
  while (*(ptr + length)) {
    length++;
  }
  return length;
}

int cipher_position(int position, int const cipher_length) {
  if (position < cipher_length) {
    position = position;
  } else {
    position = position % cipher_length;
  }
  return position;
};

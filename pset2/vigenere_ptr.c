// cipher_positionharvard@appliance (~/Dropbox/pset2): ./vigenere bacon
// Meet me at the park at eleven am
// Negh zf av huf pcfx bt gzrwep oz

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calc_cipher_length(char const* ptr);
int cipher_position(int position, int const cipher_length);
int set_letter(
  char const* arg,
  int* position,
  char const message_letter,
  char const upper_bound,
  int* letter);

int const ALPHABET_LENGTH = 'z' - 'a' + 1;

int main(int const argc, char const* argv[]) {
  int const NECESSARY_INPUTS = 2;
  if (argc != NECESSARY_INPUTS) {
    printf("%s\n", "Whoops! Please add your vigenere cipher word.");
  } else {
    int cipher_length = calc_cipher_length(argv[1]);

    // `char message[] = "";` conflicts with address of `cipher_length`
    char message[1000] = "";
    scanf("%[^\n]s", message);
    int message_length = strlen(message);
    int p = 0;
    for (int i = 0; i < message_length; i++) {
      int letter;
      if (isupper(message[i])) {
        int position = cipher_position(p, cipher_length);
        set_letter(argv[1], &position, message[i], 'Z', &letter);
        p++;
      } else if (islower(message[i])) {
        int position = cipher_position(p, cipher_length);
        set_letter(argv[1], &position, message[i], 'z', &letter);
        p++;
      } else {
        letter = message[i];
      }
      printf("%c", letter);
    }
    printf("\n");
  }
  return 0;
}

int calc_cipher_length(char const* ptr) {
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
}

int set_letter(
  char const* arg,
  int* position,
  char const message_letter,
  char const upper_bound,
  int* letter) {
  int const change = *(arg + *position) - 'a';
  *letter = message_letter + change;
  if (*letter > upper_bound) {
    *letter = *letter - ALPHABET_LENGTH;
  }
  return;
}

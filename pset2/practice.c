// jharvard@appliance (~/Dropbox/pset2): ./caesar 13
// Be sure to drink your Ovaltine!
// Or fher gb qevax lbhe Binygvar!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
  int char_to_i = 'j';
  printf("int: %i, char: %c\n", (int) char_to_i, char_to_i);
  int number_to_char = 126;
  printf("char: %c, int: %d\n", (char) number_to_char, number_to_char);

  printf("sizeof(char) in bytes: %lu\n", sizeof(char));
  printf("sizeof(int) in bytes: %lu\n", sizeof(int));
  printf("sizeof(float) in bytes: %lu\n", sizeof(float));
  printf("sizeof(long int) in bytes: %lu\n", sizeof(long));
  printf("sizeof(short int) in bytes: %lu\n", sizeof(short));

  int number = 5;
  char number_char = '5';
  char letter = 'y';

  int *ptr_number;
  ptr_number = &number;
  char *ptr_number_char;
  ptr_number_char = &number_char;
  char *ptr_letter;
  ptr_letter = &letter;

  printf("number: %i\n", number);
  printf("&number: %p\n", &number);
  printf("*ptr_number: %i\n", *ptr_number);

  printf("number_char: %c\n", number_char);
  printf("&number_char: %p\n", &number_char);
  printf("*ptr_number_char: %d\n", *ptr_number_char);

  printf("letter: %c\n", letter);
  printf("&letter: %p\n", &letter);
  printf("*ptr_letter: %d\n", *ptr_letter);

  return 0;
}

// Write, in a file called initials.c, a program that prompts a user for their name (using GetString to obtain their name as a string) and then outputs their initials in uppercase with no spaces or periods, followed by a newline (\n) and nothing more. You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus single spaces between words. Folks like Joseph Gordon-Levitt, Conan O’Brien, and David J. Malan won’t be using your program.

// So that we can automate some tests of your code, your program must behave per the examples below. Assumed that the underlined text is what some user has typed.

// jharvard@appliance (~/Dropbox/pset2): ./initials
// Zamyla Chan
// ZC
// jharvard@appliance (~/Dropbox/pset2): ./initials
// robert thomas bowden
// RTB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  // char *initials = malloc(3 * sizeof(char));
  printf("What is your name?\n");
  char name[100];
  char *pname;
  pname = &name[0];
  // scanf("%[^\n]s", pname);
  scanf("%[^\n]s", &name[0]);
  int count = strlen(pname);
  // int count = strlen(name);
  // printf("%d\n", count);
  for (int i = 0; i < count; ++i)
  {
    // printf("%c\n", name[i]);
    // printf("%c\n", pname[3]);
    // printf("%s\n", &pname[i]); // why?
    // kate
    // ate
    // te
    // e
    printf("%c\n", *(pname + i));
  }
  printf("%s\n", &pname[0]);
  printf("%s\n", &name[1]);
  printf("%s\n", name);
}
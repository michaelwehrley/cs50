// Write, in a file called initials.c, a program that prompts a user for their name (using GetString to obtain their name as a string) and then outputs their initials in uppercase with no spaces or periods, followed by a newline (\n) and nothing more. You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus single spaces between words. Folks like Joseph Gordon-Levitt, Conan O’Brien, and David J. Malan won’t be using your program.

// So that we can automate some tests of your code, your program must behave per the examples below. Assumed that the underlined text is what some user has typed.

// jharvard@appliance (~/Dropbox/pset2): ./initials
// Zamyla Chan
// ZC
// jharvard@appliance (~/Dropbox/pset2): ./initials
// robert thomas bowden
// RTB

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  char *pname;
  int count;

  printf("What is your name?\n");
  scanf("%[^\n]s", pname);
  count = strlen(pname);
  printf("%c", toupper(*(pname)));
  for (int i = 0; i < count; ++i)
  {
    if (*(pname + i) == ' ')
    {
      // 1 is the next character
      printf("%c", toupper(*((pname + i + 1))));
    }
  }
  printf("\n");
}

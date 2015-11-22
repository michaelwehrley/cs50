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
  int i = 0;
  char *name;
  char initials[] = "";

  printf("What is your name?\n");
  scanf("%[^\n]s", name);
  int length = strlen(name);

  name[0] = toupper(name[0]);
  initials[0] = toupper(name[0]);
  while (i < length)
  {
    // printf("string: %c\n", toupper(name[i]));
    if (isspace(name[i])) // change to ascii?
    {
      initials[0] = toupper(name[0]);
    }
    i++;
  }
  printf("%s\n", name);
  printf("%s\n", initials);
}
// Super Mario Brothers
// Write, in a file called mario.c in your ~/Dropbox/pset1 directory, a program that recreates this half-pyramid using hashes (#) for blocks. However, to make things more interesting, first prompt the user for the half-pyramid’s height, a non-negative integer no greater than 23. (The height of the half-pyramid pictured above happens to be 8.) If the user fails to provide a non-negative integer no greater than 23, you should re-prompt for the same again. Then, generate (with the help of printf and one or more loops) the desired half-pyramid. Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window, as in the sample output below, wherein underlined text represents some user’s input.

// jharvard@appliance (~/dropbox/pset1): ./mario
// height: 8
//        ##
//       ###
//      ####
//     #####
//    ######
//   #######
//  ########
// #########
// Note that the rightmost two columns of blocks must be of the same height. No need to generate the pipe, clouds, numbers, text, or Mario himself.

// By contrast, if the user fails to provide a non-negative integer no greater than 23, your program’s output should instead resemble the below, wherein underlined text again represents some user’s input. (Recall that GetInt will handle some, but not all, re-prompting for you.)

// jharvard@appliance (~/Dropbox/pset1): ./mario
// Height: -2
// Height: -1
// Height: foo
// Retry: bar
// Retry: 1
// ##

#include <stdio.h>
#define FIRST_ROW_WITH_BLOCKS 1;

void display_row(int height);

int main(void)
{
  int height;
  do
  {
    printf("height: ");
    scanf(" %d", &height);
  }
  while (height < 1 || height > 23);

  display_row(height);
}

void display_row(int height)
{
  int i, row = FIRST_ROW_WITH_BLOCKS;
  while (row < height)
  {
    for (i = 1; i < (height - row); i++)
    {
      printf(" ");
    }

    for (i = 0; i < (row + 1); i++)
    {
      printf("#");
    }
    printf("\n");
    row++;
  }
}

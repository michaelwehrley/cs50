// http://cdn.cs50.net/2016/x/psets/3/pset3/pset3.html
// https://manual.cs50.net/library/#Mac_OS
// http://stackoverflow.com/questions/21958734/c-in-xcode-cs50-h-issues

#include <stdio.h>
#include "cs50.h"

int main(void) {
  printf("Input number... \n");
  int x = GetInt();
  printf("You typed the number %d\n", x);
  return 0;
}
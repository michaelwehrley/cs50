// jharvard@appliance (~/Dropbox/pset1): ./greedy
// O hai! How much change is owed?
// 0.41
// 4
// By nature of floating-point values, that user could also have inputted just .41. (Were they to input 41, though, they’d get many more coins!)

// Of course, more difficult users might experience something more like the below.

// jharvard@appliance (~/Dropbox/pset1): ./greedy
// O hai! How much change is owed?
// -0.41
// How much change is owed?
// -0.41
// How much change is owed?
// foo
// Retry: 0.41
// 4

#include  <stdio.h>
#define QUARTER 0.25
#define DIME 0.10
#define NICKEL 0.05
#define PENNY 0.01
// #define COIN_TYPES = 4;

int main(void) {
  float change_owed;
  int COIN_TYPES = 4;
  int num_quarters = 0;
  int num_dimes = 0;
  int num_nickels = 0;
  int num_pennies = 0;
  float coins[4] = { QUARTER, DIME, NICKEL, PENNY };
  int coin_count[4] = { num_quarters, num_dimes, num_nickels, num_pennies };

  printf("O hai! How much change is owed?\n");
  scanf(" %f", &change_owed);
  
  
  for (int i = 0; i < COIN_TYPES; i++)
  {
    coin_count[i] = change_owed/coins[i];
    printf("%i\n", coin_count[i]);
    change_owed = change_owed - coin_count[i] * coins[i];
    printf("%f\n", change_owed);
  }
  printf("%i\n", coin_count[0] + coin_count[1] + coin_count[2] + coin_count[3]);
}
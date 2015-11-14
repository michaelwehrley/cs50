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
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main(void) {
  int COIN_TYPES = 4;
  int LOWER_CHANGE_BOUND = 0;
  int UPPER_CHANGE_BOUND = 10;
  int CENTS_PER_DOLLAR = 100;
  float change_owed;
  int coin_count[4];
  int coins[4] = { QUARTER, DIME, NICKEL, PENNY };

  do
  {
    printf("O hai! How much change is owed?\n");
    scanf("%f", &change_owed);
  } while ((change_owed < LOWER_CHANGE_BOUND) || (change_owed > UPPER_CHANGE_BOUND));

  change_owed = change_owed * CENTS_PER_DOLLAR;  
  
  for (int i = 0; i < COIN_TYPES; i++)
  {
    coin_count[i] = change_owed/coins[i];
    change_owed = change_owed - coin_count[i] * coins[i];
  }
  printf("%i\n", coin_count[0] + coin_count[1] + coin_count[2] + coin_count[3]);
}
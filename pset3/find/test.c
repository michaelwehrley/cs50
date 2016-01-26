#include <stdio.h>
#include <stdlib.h>

int sort(int values[], int n);
void show(int values[], int n);

int main(int argc, char const *argv[])
{
  int myArray[2] = {2, 1};
  sort(myArray, 2);
  return 0;
}

int sort(int values[], int n) {
  // TODO: implement an O(n^2) sorting algorithm
  int sorted_value = values[0];
  int i = 0;
  while(i < n) {
    int new_value = values[i];
    if (new_value < sorted_value) {
      int* p_new_value = &new_value;
      int* p_sorted_value = &sorted_value;
      int first_value = sorted_value;
      printf("value_a: %i\n", *p_sorted_value);
      printf("value_b: %i\n", *p_new_value);
      *p_sorted_value = new_value;
      *p_new_value = first_value;
      printf("value_a: %i\n", *p_sorted_value);
      printf("value_b: %i\n", *p_new_value);
    }
    i++;
  };
  // show(values, n);
  printf("0: %i\n", values[0]);
  printf("1: %i\n", values[1]);
  return 0;
}

void show(int values[], int n) {
  int i = 0;
  while(i < n) {
    printf("%i\n", values[i]);
    i++;
  }
}

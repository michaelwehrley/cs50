#include <stdio.h>

int sort(int values[], int n);
void show(int values[], int n);
void swap(int* p_new_value, int* p_sorted_value);

int main(int argc, char const *argv[])
{
  int myArray[2] = { 2, 1 };
  sort(myArray, 2);
  return 0;
}

int sort(int values[], int n) {
  // TODO: implement an O(n^2) sorting algorithm
  show(values, n);
  int i = 0;
  while(i < n) {
    if (values[i] < values[0]) {
      swap(&values[i], &values[0]);
    }
    i++;
  };
  show(values, n);
  return 0;
}

void show(int values[], int n) {
  int i = 0;
  while(i < n) {
    printf("%i\n", values[i]);
    i++;
  }
}

void swap(int* p_new_value, int* p_sorted_value) {
  int temp = *p_new_value;

  printf("value_a: %i\n", *p_sorted_value);
  printf("value_b: %i\n", *p_new_value);
  *p_new_value = *p_sorted_value;
  *p_sorted_value = temp;
  printf("value_a: %i\n", *p_sorted_value);
  printf("value_b: %i\n", *p_new_value);
}

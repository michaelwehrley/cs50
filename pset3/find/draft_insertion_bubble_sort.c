#include <stdio.h>

int sort(int values[], int n, int* count);
void show(int values[], int n);
void swap(int* p_new_value, int* p_sorted_value);

int main(int argc, char const *argv[])
{
  int const size = 10;
  int myArray[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  // int myArray[size] = { 9,1,2,3,4,5,6,7,8,0 };
  int i = 0;
  int count = 1;
  int* p_count = &count;
  while(i < size) {
    // improve so it only goes through once...
    sort(myArray, size, p_count);
    i++;
    *p_count = *p_count + 1;
  }
  printf("count: %d\n", *p_count);
  return 0;
}

int sort(int values[], int n, int* p_count) {
  // TODO: implement an O(n^2) sorting algorithm
  int i = 0;
  while(i < n) {
    if (i != 0 && values[i] < values[i - 1]) {
      swap(&values[i], &values[i - 1]);
    }
    show(values, n);
    *p_count = *p_count + 1;
    i++;
  };
  return 0;
}

void show(int values[], int n) {
  int i = 0;
  while(i < n) {
    printf("%i", values[i]);
    i++;
  }
  printf("\n");
}

void swap(int* p_new_value, int* p_sorted_value) {
  int temp = *p_new_value;

  *p_new_value = *p_sorted_value;
  *p_sorted_value = temp;
}

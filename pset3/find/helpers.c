/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <stdio.h>
#include <math.h>

#include "cs50.h"

#include "helpers.h"

void bubble_sort(int values[], int n);
void swap(int* p_new_value, int* p_sorted_value);

void show(int values[], int n) {
  printf("showing values: [");
  int i = 0;
  while(i < n) {
    printf("%i, ", values[i]);
    i++;
  }
  printf("]\n");
}

/**
 * Returns true if value is in array of n values, else false.
 */

bool divide_and_conquer(int value, int n, int values[]) {
  show(values, n);
  int half = n / 2;
  if (half == 0) {
    return false;
  } else if (value < values[half]) {
    printf("%c\n", 'd');
    printf("%i\n", half);
    return divide_and_conquer(value, half, values);
  } else if (value == values[half]) {
    return true;
  } else {
    printf("%c\n", 'u');
    int quarter = half / 2;
    int middle = half + quarter;
    printf("%i\n", middle);
    return divide_and_conquer(value, middle, values);
  }
}

bool search(int value, int values[], int n) {
  // TODO: implement a searching algorithm
  sort(values, n);
  return divide_and_conquer(value, n, values);
}

// bool search(int value, int values[], int n) {
//   // TODO: implement a searching algorithm
//   int i = 0;
//   while(i < n) {
//     if (values[i] == value) {
//       return true;
//     }
//     i++;
//   }
//   return false;
// }

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
  // TODO: implement an O(n^2) sorting algorithm
  int i = 0;
  while(i < n) {
    // improve so it only goes through once...
    bubble_sort(values, n);
    i++;
  }
  return;
}

void bubble_sort(int values[], int n) {
  // TODO: implement an O(n^2) sorting algorithm
  int i = 0;
  while(i < n) {
    if (i != 0 && values[i] < values[i - 1]) {
      swap(&values[i], &values[i - 1]);
    }
    i++;
  };
  return;
}

void swap(int* p_new_value, int* p_sorted_value) {
  int temp = *p_new_value;

  *p_new_value = *p_sorted_value;
  *p_sorted_value = temp;
  return;
}

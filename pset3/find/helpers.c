/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <math.h>

#include "cs50.h"

#include "helpers.h"

void bubble_sort(int values[], int n);
void swap(int* p_new_value, int* p_sorted_value);
bool divide_and_conquer(int n, int value, int values[], int* p_lower_position, int* p_upper_position);

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n) {
  // TODO: implement a binary searching algorithm
  int lower_position = 0;
  int* p_lower_position = &lower_position;
  int upper_position = n - 1;
  int* p_upper_position = &upper_position;
  return divide_and_conquer(n, value, values, p_lower_position, p_upper_position);
}

bool divide_and_conquer(int n, int value, int values[], int* p_lower_position, int* p_upper_position) {
  int delta = (*p_upper_position - *p_lower_position) / 2;
  int half = *p_upper_position - delta;
  if (value == values[half]) {
    return true;
  } else if (half == 1 || half == (n - 1)) {
    return false;
  } else if (value < values[half]) {
    *p_upper_position = half;
  } else if (value > values[half]) {
    *p_lower_position = half;
  }
  return divide_and_conquer(n, value, values, p_lower_position, p_upper_position);
}

bool linear_search(int value, int values[], int n) {
  // TODO: implement a linear searching algorithm
  int i = 0;
  while(i < n) {
    if (values[i] == value) {
      return true;
    }
    i++;
  }
  return false;
}

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

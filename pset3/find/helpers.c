/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include "cs50.h"

#include "helpers.h"

void bubble_sort(int values[], int n);
void swap(int* p_new_value, int* p_sorted_value);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n) {
  // TODO: implement a searching algorithm
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

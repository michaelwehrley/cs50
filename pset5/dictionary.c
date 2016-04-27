/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */

bool check(const char* word)
{
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

// TODO

typedef struct node {
  char word[LENGTH + 1];
  struct node* next;
}
node;

typedef struct alpha_node {
  char letter;
  struct node* next;
}
alpha_node;

bool load(const char* dictionary)
{
  // create array of struct pointers
  // remember to free it, can use alloca() instead
  // allocate enough memory for entire hashtable
  alpha_node* hashtable = malloc(sizeof(alpha_node) * 26);
  // alpha_node* hashtable[26];

  for (int i = 97; i < 123; i++) {
    hashtable[i].letter = (char) i;
    printf("Value of hashtable[%c]\n", hashtable[i].letter);
  }

  // do {
  //   node* new_node_ptr = malloc(sizeof(node));
  //   a = fscanf(file, "%s", new_node_ptr->word);
  //   printf("a: %d\n", a);
  // } while (a != EOF);
    // fclose(file);
  //   return true;
  // }
  return true;
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}

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
  struct node* next_node_ptr;
}
node;

bool load(const char* dictionary)
{
  char* hashtable[500]; // allocate enough memory for entire hashtable

  FILE* file = fopen(dictionary, "r");
  if (file == NULL) {
    return 1;
  }

  int a;
  for (int i = 0; i < 26; i++) {
    hashtable[i] = NULL;
  }

  do {
    node* new_node_ptr = malloc(sizeof(node));
    a = fscanf(file, "%s", new_node_ptr->word);
    printf("a: %d\n", a);
  } while (a != EOF);
    fclose(file);
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

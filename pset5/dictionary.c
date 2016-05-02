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
bool load(const char* dictionary)
{
  char block[LENGTH + 1];

  typedef struct node {
    // char word[LENGTH + 1];
    char* word_ptr;
    struct node* next;
  }
  node;

  FILE* file = fopen(dictionary, "r");
  if (file == NULL) {
    printf("something went wrong and file could not be opened");
    return 1;
  }
  // fread(&block, sizeof(char), (LENGTH + 1), file); // keeps 45 bytes - WHY?
  // fread(&block, (LENGTH + 1), sizeof(char), file); // read all 45 bytes
  fread(&block, strlen(block) + 1, 1, file);
  node* new_node = malloc(sizeof(node));
  // new_node->word_ptr = malloc(sizeof(char) * (LENGTH + 1));
  printf("block: %s\n", block);
  new_node->word_ptr = block;
  printf("new_node->word_ptr2: %s\n", new_node->word_ptr);
  // free(new_node);
  // fclose(file);
  return false;
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

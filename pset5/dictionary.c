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
  typedef struct node {
    char word[LENGTH + 1];
    struct node* next;
  }
  node;

  FILE* file = fopen(dictionary, "r");
  if (file == NULL) {
    printf("something went wrong and file could not be opened");
    return 1;
  } else {
    char* buffer_ptr = malloc(sizeof(char));
    *buffer_ptr = 'a';
    printf("&buffer_ptr %p\n", &buffer_ptr);

    char buffer[1];
    int i = 0;
    node new_node;

    // while (!feof(file)) {
    while (fread(&buffer, sizeof(char), 1, file) == 1) {
      printf("&buffer: %p\n", &buffer);
      printf("&buffer[0]: %p\n", &buffer[0]);

      if (buffer[0] != '\n') {
        new_node.word[i] = buffer[0];
        printf("buffer: %c\n", buffer[0]);
        printf("i: %d\n", i);
        printf("new_node.word[i]: %c\n", new_node.word[i]);
        printf("new_node.word: %s\n", new_node.word);

        i = i + 1;
      } else {
        // create_new_node(file);
      }
    }
    return true;
  }
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

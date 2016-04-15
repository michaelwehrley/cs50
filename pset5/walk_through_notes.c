// linked list
typedef struct node {
  // LENGTH is max length of any word + the '\n'
  // We are creating and array here - grabing the needed memory.
  char word[LENGTH + 1];
  struct node* text;
}
node;

node* node1 = malloc(sizeof(node)); // at this point in memory - specify the size of node piece of memory
node* node2 = malloc(sizeof(node));
(*node1).word = "Hello"; // node1->word = "Hello";
node1->next = node2; // why not &node2;
node1->word = "World";

// hash table
typedef struct node {
  char word[LENGTH + 1]; // LENGTH is max length of any word
  struct node* text;
}
node;

node* hashtable[500];

node* new_node = malloc(sizeof(node));
fscanf(file, "%s", new_node->word)

// traversing linked lists
node* cursor = head;
while (cursor != NULL) {
  // do something
  // cursor = (*cursor).next;
  cursor = cursor->next;
}

// Tries

typedef struct node
{
  bool is_word;
  struct node* children[27];
}
node;

node* root; // 'root' is my first node.
// Example: "fox"
// f:
root->children[5];
// o:
root->children[5]->children[15];
// x:
root->children[5]->children[15]->children[23];

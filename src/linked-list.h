#include <stdbool.h>

#include "definitions.h"

#ifndef _LIST
#define _LIST

typedef struct Node {
  struct Node* next;
  position* value;
} Node;

typedef struct {
  Node *first;
  Node *last;
} List;

List* init_list(); 

bool is_empty(List* list);

bool includes(List* list, position* value);

void push_back(List* list, position* value); 

void delete_start(List* list);

#endif

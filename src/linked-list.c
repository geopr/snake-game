#include <stdlib.h>
#include <stdbool.h>

#include "linked-list.h"
#include "utils.h"

List* init_list() {
  List* list = malloc(sizeof(List));
  list->first = NULL;
  list->last = NULL;
  return list;
}

Node* create_node(position* value) {
  Node* node = malloc(sizeof(Node));
  node->next = NULL;
  node->value = value;
  return node;
}

bool is_empty(List* list) {
  return list->first == NULL && list->last == NULL;
}

bool includes(List* list, position* value) {
  Node* current = list->first;

  while (current != NULL) {
    if (are_positions_equal(current->value, value)) {
      return true;
    }

    current = current->next;
  }

  return false;
}

bool handle_empty(List* list, position* value) {
  if (is_empty(list)) {
    Node* node = create_node(value);

    list->first = node;
    list->last = node;

    return true;
  }

  return false;
}

void push_back(List* list, position* value) {
  if (handle_empty(list, value)) return;

  Node* node = create_node(value);
  list->last->next = node;
  list->last = node;
}

void delete_start(List* list) {
  if (is_empty(list)) return;

  if (list->first == list->last) {
    list->first = NULL;
    list->last = NULL;
    return;
  }

  Node* next_first = list->first->next;

  free(list->first);

  list->first = next_first;
}

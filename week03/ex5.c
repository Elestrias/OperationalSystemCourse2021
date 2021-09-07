#include <stdio.h>
#include <stdlib.h>

struct doubleLinkedNode {
  int value;
  struct doubleLinkedNode *next;
  struct doubleLinkedNode *previous;
};

void print_list(struct doubleLinkedNode *head) {
  int flag = 0;
  while (head->next != NULL) {
    if (flag) {
      printf("%d", head->value);
    }
    flag = 1;
    head = head->next;
  }
}

void insert_node(int value, struct doubleLinkedNode *previous_node) {
  struct doubleLinkedNode *new_node =
      (struct doubleLinkedNode *)malloc(sizeof(struct doubleLinkedNode));
  new_node->value = value;
  if (previous_node->next != NULL) {
    struct doubleLinkedNode *nextNext = previous_node->next;
    previous_node->next = new_node;
    new_node->previous = previous_node;
    new_node->next = nextNext;
    previous_node->previous = new_node;
  }
  previous_node->next = new_node;
  new_node->previous = previous_node;
  new_node->next = NULL;
}

void delete_node(struct doubleLinkedNode *searched_node) {
  struct doubleLinkedNode *previous = searched_node->previous;
  if (searched_node->next == NULL) {
    previous->next = NULL;
    free(searched_node);
  } else {
    struct doubleLinkedNode *nextNext = searched_node->next;
    previous->next = nextNext;
    nextNext->previous = previous;
    free(searched_node);
  }
}
int main() {
  struct doubleLinkedNode *list = malloc(sizeof(struct doubleLinkedNode));
  struct doubleLinkedNode *head = list;
  head->previous = NULL;
  head->next = NULL;
  for (int i = 0; i < 10; ++i) {
    insert_node(i, head);
    head = head->next;
  }
  struct doubleLinkedNode *need = list->next->next->next;
  print_list(list);
  delete_node(need);
  printf("\n");
  print_list(list);
  return 0;
}
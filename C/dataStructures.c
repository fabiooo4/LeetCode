#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKCHAR_EMPTY CHAR_MIN

// nodes
typedef struct nodeChar {
  char value;
  struct nodeChar *next;
} nodeChar;

typedef struct nodeInt {
  int value;
  struct nodeInt *next;
} nodeInt;
//

// linked list
void printList(nodeInt *head) {
  nodeInt *tmp = head;

  while (tmp != NULL) {
    printf("%d ", tmp->value);
    tmp = tmp->next;
  }
}

nodeInt *addNode(int n) {
  nodeInt *newNode = malloc(sizeof(nodeInt));
  if (newNode == NULL) {
    return NULL;
  }

  newNode->value = n;
  newNode->next = NULL;

  return newNode;
}
//

// char stack
typedef nodeChar *stackChar;

bool stackCharPush(stackChar *stack, char value) {
  nodeChar *newNode = malloc(sizeof(nodeChar));
  if (newNode == NULL) {
    return false;
  }

  newNode->value = value;
  newNode->next = *stack;
  *stack = newNode;

  return true;
}

char stackCharPop(stackChar *stack) {
  if (*stack == NULL) {
    return STACKCHAR_EMPTY;
  }

  char result = (*stack)->value;
  nodeChar *tmp = *stack;
  *stack = (*stack)->next;
  free(tmp);
  return result;
}

char stackCharTop(stackChar *stack) {
  if (*stack == NULL) {
    return STACKCHAR_EMPTY;
  }

  return (*stack)->value;
}
//

// int stack
typedef nodeInt *stackInt;

bool stackIntPush(stackInt *stack, int value) {
  nodeInt *newNode = malloc(sizeof(nodeInt));
  if (newNode == NULL) {
    return false;
  }

  newNode->value = value;
  newNode->next = *stack;
  *stack = newNode;

  return true;
}

char stackIntPop(stackInt *stack) {
  if (*stack == NULL) {
    return STACKCHAR_EMPTY;
  }

  char result = (*stack)->value;
  nodeInt *tmp = *stack;
  *stack = (*stack)->next;
  free(tmp);
  return result;
}

char stackIntTop(stackInt *stack) {
  if (*stack == NULL) {
    return STACKCHAR_EMPTY;
  }

  return (*stack)->value;
}
//

int main() {
  nodeInt *list;
  nodeInt *head = NULL;

  for (long i = 0; i < 256; i++) {
    list = addNode(i);
    list->next = head;
    head = list;
  }

  printf("[ ");
  printList(head);
  printf("]\n");

  return 0;
}

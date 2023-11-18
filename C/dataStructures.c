#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKCHAR_EMPTY CHAR_MIN

// linked list node
typedef struct node {
  char value;
  struct node *next;
} node;
//

// char stack
typedef node *stackChar;

bool stackCharPush(stackChar *stack, char value) {
  node *newNode = malloc(sizeof(node));
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
  node *tmp = *stack;
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
typedef node *stackInt;

bool stackIntPush(stackInt *stack, int value) {
  node *newNode = malloc(sizeof(node));
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
  node *tmp = *stack;
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
  stackChar s1 = NULL;

  stackCharPush(&s1, '1');
  stackCharPush(&s1, '2');
  stackCharPush(&s1, '3');
  stackCharPush(&s1, '4');
  stackCharPush(&s1, '5');

  printf("s1 = %c\n", stackCharTop(&s1));

  return 0;
}

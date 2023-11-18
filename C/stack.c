#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY CHAR_MIN

typedef struct node {
  char value;
  struct node *next;
} node;

typedef node *stack;

bool push(stack *stack, char value) {
  node *newNode = malloc(sizeof(node));
  if (newNode == NULL) {
    return false;
  }

  newNode->value = value;
  newNode->next = *stack;
  *stack = newNode;

  return true;
}

char pop(stack *stack) {
  if (*stack == NULL) {
    return STACK_EMPTY;
  }

  char result = (*stack)->value;
  node *tmp = *stack;
  *stack = (*stack)->next;
  free(tmp);
  return result;
}

int main() {
  stack s1 = NULL;
  char t;

  push(&s1, '1');
  push(&s1, '2');
  push(&s1, '3');
  push(&s1, '4');
  push(&s1, '5');

  while ((t = pop(&s1)) != STACK_EMPTY) {
    printf("s1 = %c\n", t);
  }

  return 0;
}

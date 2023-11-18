#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

bool isValid(char *s) {
  stack open = NULL;

  for (int i = 0; i < (int)strlen(s); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      push(&open, s[i]);
    } else {
      if (open == NULL || (s[i] == ')' && open->value != '(') ||
          (s[i] == ']' && open->value != '[') ||
          (s[i] == '}' && open->value != '{')) {
        printf("String is not valid\n");
        return false;
      }
      pop(&open);
    }
  }

  if (open != NULL) {
    printf("String is not valid\n");
    return false;
  } else {
    printf("String is valid\n");
    return true;
  }
}

int main() {
  char *s[14];
  *s = ")";
  isValid(*s);
}

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

nodeInt *createNode(int n) {
  nodeInt *newNode = malloc(sizeof(nodeInt));
  if (newNode == NULL)
    return NULL;

  newNode->value = n;
  newNode->next = NULL;

  return newNode;
}

void pushNode(nodeInt **head, int n) {
  nodeInt *newNode = malloc(sizeof(nodeInt));
  newNode->value = n;
  newNode->next = *head;

  *head = newNode;
}

void appendNode(nodeInt **head, int n) {
  nodeInt *newNode = malloc(sizeof(nodeInt));
  nodeInt *last = *head;

  if (newNode == NULL)
    return;

  newNode->value = n;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = newNode;
  return;
}

nodeInt *addNodeAtHead(nodeInt **head, nodeInt *nodeToInsert) {
  nodeToInsert->next = *head;
  *head = nodeToInsert;

  return nodeToInsert;
}

nodeInt *findNode(nodeInt *head, int n) {
  nodeInt *tmp = head;

  while (tmp != NULL) {
    if (tmp->value == n) {
      return tmp;
    }
    tmp = tmp->next;
  }
  return NULL;
}

void deleteNode(nodeInt **head, int n) {
  nodeInt *tmp = *head;
  nodeInt *prev;

  if (tmp == NULL)
    return;

  if (tmp != NULL && tmp->value == n) {
    *head = tmp->next;
    free(tmp);
  }

  while (tmp != NULL && tmp->value != n) {
    prev = tmp;
    tmp = tmp->next;
  }

  prev->next = tmp->next;
  free(tmp);
}

void insertAfterNode(nodeInt *nodeToInsertAfter, nodeInt *newNode) {
  newNode->next = nodeToInsertAfter->next;
  nodeToInsertAfter->next = newNode;
}

nodeInt *swapNodes(nodeInt *node1, nodeInt *node2) {
  nodeInt *tmp = node2->next;

  node2->next = node1;
  node1->next = tmp;

  return node2;
}

int listSize(nodeInt *head) {
  nodeInt *tmp = head;
  int count = 0;

  while (tmp != NULL) {
    count++;
    tmp = tmp->next;
  }

  return count;
}

void sortList(nodeInt **head) {
  nodeInt **h = head;
  bool swapped;
  int size = listSize(*h);

  if (*head == NULL)
    return;

  for (int i = 0; i < size; i++) {
    h = head;
    swapped = 0;

    for (int j = 0; j < size - i - 1; j++) {
      nodeInt *node1 = *h;
      nodeInt *node2 = node1->next;

      if (node1->value > node2->value) {
        *h = swapNodes(node1, node2);
        swapped = 1;
      }

      h = &(*h)->next;
    }

    if (swapped == 0)
      break;
  }
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
  nodeInt *head = NULL;

  for (long i = 0; i < 5; i++) {
    pushNode(&head, i);
  }

  printf("[ ");
  printList(head);
  printf("]\n");

  sortList(&head);

  printf("[ ");
  printList(head);
  printf("]\n");

  return 0;
}

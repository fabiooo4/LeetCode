#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

void printList(ListNode *head) {
  ListNode *tmp = head;

  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
}

void appendNode(ListNode **head, int n) {
  ListNode *newNode = malloc(sizeof(ListNode));
  ListNode *last = *head;

  if (newNode == NULL)
    return;

  newNode->val = n;
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *output = NULL;

  while (list1 != NULL && list2 != NULL) {
    if (list1->val < list2->val) {
      appendNode(&output, list1->val);
      list1 = list1->next;
    } else {
      appendNode(&output, list2->val);
      list2 = list2->next;
    }
  }

  /* If one list finished iterating before the other then add the unfinished one
  to the end of the list. */
  if (list1 != NULL) {
    while (list1 != NULL) {
      appendNode(&output, list1->val);
      list1 = list1->next;
    }
  }

  if (list2 != NULL) {
    while (list2 != NULL) {
      appendNode(&output, list2->val);
      list2 = list2->next;
    }
  }

  return output;
}

int main() {
  int list1[] = {1, 3, 5};
  int list2[] = {5, 6};

  ListNode *head1 = NULL;
  ListNode *head2 = NULL;

  // Assign list1 to head1
  for (int i = 0; i < (int)(sizeof(list1) / sizeof(int)); i++) {
    appendNode(&head1, list1[i]);
  }

  // Assign list2 to head2
  for (int i = 0; i < (int)(sizeof(list2) / sizeof(int)); i++) {
    appendNode(&head2, list2[i]);
  }

  printf("[ ");
  printList(head1);
  printf("]");
  printf("\n");

  printf("[ ");
  printList(head2);
  printf("]");
  printf("\n");

  printf("[ ");
  printList(mergeTwoLists(head1, head2));
  printf("]");
  printf("\n");
  return 0;
}

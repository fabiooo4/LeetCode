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

  if (list1 == NULL && list2 == NULL) {
    return NULL;
  }

  if (list1 == NULL) {
    return list2;
  }

  if (list2 == NULL) {
    return list1;
  }

  while (list1 != NULL && list2 != NULL) {
    printf("%d < %d\n", list1->val, list2->val);
    if (list1->val < list2->val) {
      appendNode(&output, list1->val);
      list1 = list1->next;
    } else if (list1->val == list2->val) {
      appendNode(&output, list1->val);
      appendNode(&output, list2->val);
      list1 = list1->next;
      list2 = list2->next;
    } else {
      appendNode(&output, list2->val);
      list2 = list2->next;
    }

    if (list2 == NULL && list1 != NULL) {
      appendNode(&output, list1->val);
      list1 = list1->next;
    }
  }

  return output;
}

int main() {
  int list1[] = {5, 6};
  int list2[] = {1, 3, 4};

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

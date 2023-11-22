#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

bool addAfterNode(struct ListNode *list, int val) {
  struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
  if (newNode == NULL) {
    return false;
  }
  newNode->val = val;
  newNode->next = list->next;
  list->next = newNode;

  return 1;
}

void printList(struct ListNode *list) {
  struct ListNode *temp = list;
  printf("[ ");
  while (temp != NULL) {
    printf("%d ", temp->val);
    temp = temp->next;
  }
  printf("]");
  printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *output;
  return output;
}

int main() {
  struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));

  addAfterNode(list1, 2);
  addAfterNode(list1, 3);

  printList(list1);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
} Node;

/**
 * @brief insert or create a node
 *
 * @param el
 * @param l
 * @return Node*
 */
Node* _insert(int el, Node* next) {
    Node* node;
    node = (struct Node*)malloc(sizeof(struct Node));

    node->data = el;
    node->next = next;

    return (Node*) node;
}

/**
 * @brief Proxy method to determine previous
 *
 * @param el
 * @param next
 * @return Node*
 */
Node* insert(int el, Node* next) {
  Node* node = _insert(el, next);

  Node* previousNode = NULL;
  Node* currNode = node;

  // set previous
  while (currNode != NULL) {
    currNode->previous = previousNode;
    previousNode = currNode;
    currNode = currNode->next;
  }

  return node;
}

void freeList(struct Node* n)
{
   struct Node* tmp;

   while (n != NULL)
    {
       tmp = n;
       n = n->next;
       free(tmp);
    }

}

/**
 * @brief print a list data structure
 *
 * @param n
 */
void printList(struct Node* n)
{
    while (n != NULL) {
        printf("(%d)", n->data);
        if (n->previous != NULL) {
          printf(" parent : %d", n->previous->data);
        }
        n = n->next;
        printf("\n");
    }
}

/**
 * @brief List test case
 */
void list() {
  printf("Single case ;\n");
  Node* head = insert(2, NULL);
  printList(head);
  freeList(head);

  printf("\nMultiple case ;\n");
  Node* head1 = insert(
    1,
    insert(
      2,
      insert(3, NULL)
    )
  );
  printList(head1);
  freeList(head1);
}

#endif

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

// Use typedef to make this type available globally
struct TreeNode
{
  int data;
  struct TreeNode *right;
  struct TreeNode *left;
} TreeNode;

/**
 * @brief Create a Tree Node object
 *
 * @param data
 * @return struct TreeNode*
 */
struct TreeNode *createTreeNode(int data)
{
  struct TreeNode *node =
      (struct TreeNode *)malloc(sizeof(struct TreeNode));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

/**
 * @brief Shift output
 *
 * @param start
 * @param end
 */
void shiftPrint(int start, int end) {
  for (int i = start; i <= end; i++) {
    printf("\t");
  }
}

/**
 * @brief Pretty print tree
 *
 * @param node
 * @param level
 */
void printNode(
  struct TreeNode *node,
  int level,
  int depth,
  int pos,
  bool both
) {
  if (node != NULL) {
    if (!both) {
      shiftPrint(level, depth);
      shiftPrint(1, pos);
    }

    printf("(%d)", node->data);

    if (!both) {
      printf("\n");
    }

    both = NULL != node->left && NULL != node->right;

    if (NULL == node->left && NULL == node->right) {
      return;
    }

    shiftPrint(level, depth);
    shiftPrint(1, pos);
    printf("/ \\");

    if (node->right != NULL) {
      pos += 2;
    }
  } else {
    return;
  }

  ++level;

  if (level <= depth) {
    printf("\n");
    
    if (both) {
      shiftPrint(1, pos);
    }

    printNode(node->left, level, depth, pos, both);
    printNode(node->right, level, depth, pos, both);
  }
}

/**
 * @brief Proxy method for recursive print node
 *
 * @param node
 * @param depth
 * @param level
 */
void printTree(struct TreeNode *node)
{
  int depth = 0;
  struct TreeNode* tmpNode = node;

  while(tmpNode->right != NULL || tmpNode->left != NULL) {
    if (tmpNode->right != NULL) {
      tmpNode = tmpNode->right;
    } else if (tmpNode->left != NULL) {
      tmpNode = tmpNode->left;
    } else {
      continue;
    }

    depth++;
  }

  free(tmpNode);
  printf("tree depth : %d\n", depth);
  printNode(node, 0, depth, 0, false);
}

int binarytree()
{
  // TODO : input node
  struct TreeNode *node1 = createTreeNode(1);
  struct TreeNode *node2 = createTreeNode(2);
  struct TreeNode *node3 = createTreeNode(3);
  struct TreeNode *node4 = createTreeNode(4);
  struct TreeNode *node5 = createTreeNode(5);
  struct TreeNode *node6 = createTreeNode(6);
  struct TreeNode *node7 = createTreeNode(7);
  // struct TreeNode *node8 = createTreeNode(8);
  // struct TreeNode *node9 = createTreeNode(9);

  node1->left = node2;
  node2->right = node3; // node 3 is in depth 3
  node3->right = node4;
  node4->left = node5;
  node5->right = node6;
  node5->left = node7;
  //node6->right = node8;
  // node7->left = node9;

  printTree(node1);

  free(node1);
  free(node2);
  free(node3);
  free(node4);

  return 0;
}

#endif

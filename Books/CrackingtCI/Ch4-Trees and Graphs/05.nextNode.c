/*Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in 
a binary search tree where each node has a link to its parent*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *parent;
	struct node *right;
	struct node *left;
};

struct node *insertNode(struct node *node, int data, struct node *parent) { 
  if (node == NULL) {
    node = (struct node *) malloc(sizeof(struct node));
    node->parent = node;
    node->data = data;
    node->right = NULL;
    node ->left = NULL; 
    return node; 
  } 
  else { 
    if (data <= node->data) node->left = insertNode(node->left, data, node); 
    else node->right = insertNode(node->right, data, node);
  } 
  return node;
} 

int main(){
  int i;
  struct node *root;
  root = NULL;

  for(i=0;i<10;i++) root = insertNode(root, i, NULL);

  return 0;
}
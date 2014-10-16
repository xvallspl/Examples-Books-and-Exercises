/*Given a binary search tree, design an algorithm which creates a linked list of all the
 nodes at each depth (i e , if you have a tree with depth D, you’ll have D linked lists)*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node *right;
  struct node *left;
};

struct node *insertNode(struct node *node, int data) { 
  if (node == NULL) {
    node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->right = NULL;
    node ->left = NULL; 
    return(node); 
  } 
  else { 
    if (data <= node->data){
      node->left = insertNode(node->left, data); 
    }else{
      node->right = insertNode(node->right, data);
    }
  } 
  return node;
} 

int main(){
  int i;
  struct node *root;
  root = NULL;

  for(i=0;i<10;i++)
      insertNode(root, i);
}

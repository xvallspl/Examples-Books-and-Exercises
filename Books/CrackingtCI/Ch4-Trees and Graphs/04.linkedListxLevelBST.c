/*Given a binary search tree, design an algorithm which creates a linked list of all the
 nodes at each depth (i e , if you have a tree with depth D, you’ll have D linked lists)*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node *right;
  struct node *left;
};

struct nodeList{
  int data;
  struct nodeList *next;
};

struct listOfLists{
  struct nodeList *head;
  struct listOfLists *next;
};

void generateListPerLevel(struct node *treeNode, struct listOfLists **list){
  struct nodeList *node;

  if((*list) == NULL){
    (*list) = (struct listOfLists *) malloc(sizeof(struct listOfLists));
    (*list)->next = NULL;
    (*list)->head = (struct nodeList *) malloc(sizeof(struct nodeList));
    (*list)->head->data = node->data;
    (*list)->head->next = NULL;
  }else{
    while(node->next!=NULL) node = node->next;

    node->next = (struct nodeList *) malloc(sizeof(struct nodeList));
    node = node->next;
    node->data = treeNode->data;
    node->next = NULL;

    generateListPerLevel( treeNode->left, &(*list)->next);
    generateListPerLevel( treeNode->right, &(*list)->next);
  }
}

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
  struct listOfLists *listOfLevels;
  listOfLevels = NULL;

  for(i=0;i<10;i++) insertNode(root, i);

  generateListPerLevel( root, &listOfLevels);

  return 0;
}

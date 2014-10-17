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

struct listOfLists * generateListPerLevel(struct node *treeNode, struct listOfLists **list){
  struct nodeList *node;
  if((*list) == NULL){
    (*list) = (struct listOfLists *) malloc(sizeof(struct listOfLists));
    (*list)->next = NULL;
    (*list)->head = (struct nodeList *) malloc(sizeof(struct nodeList));
    (*list)->head->data = treeNode->data;
    (*list)->head->next = NULL;
    if(treeNode->left)  generateListPerLevel(treeNode->left, &(*list)->next);
    if(treeNode->right) generateListPerLevel(treeNode->right, &((*list)->next));
  }else{
    node = (*list)->head;
    while(node->next!=NULL) node = node->next;

    node->next = (struct nodeList *) malloc(sizeof(struct nodeList));
    node = node->next;
    node->data = treeNode->data;
    node->next = NULL;

    if(treeNode->left)  generateListPerLevel(treeNode->left, &((*list)->next));
    if(treeNode->right) generateListPerLevel(treeNode->right, &((*list)->next));
  }
  return(*list);
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

void printLists(struct listOfLists *listOfLevels){
  struct nodeList *p;

  while(listOfLevels!=NULL){
    p = listOfLevels->head;
    while(p!=NULL){
      printf("%d ", p->data);
      p = p->next;
    }
    printf("\n");
    listOfLevels = listOfLevels->next;
  }
}

int main(){
  int i, j;
  struct node *root, *root2;
  root = NULL;
  root2 = NULL;
  struct listOfLists *listOfLevels1, *listOfLevels2;
  listOfLevels1 = NULL;
  listOfLevels2 = NULL;

  for(i=0;i<10;i++) root = insertNode(root, i);
  listOfLevels1 = generateListPerLevel(root, &listOfLevels1);
  
  for(i=0;i<10;i++) root2 = insertNode(root2, rand()%10);
  listOfLevels2 = generateListPerLevel(root2, &listOfLevels2);
  
  printLists(listOfLevels1);
  printf("\n");
  printLists(listOfLevels2);

  return 0;
}

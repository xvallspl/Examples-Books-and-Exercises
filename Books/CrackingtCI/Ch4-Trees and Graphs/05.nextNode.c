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

struct node * theirLeftMostChild(struct node *node){
	if(node==NULL) return NULL;
	while(node->left != NULL) node = node->left;
	return node;
}

struct node *theirSuccessor(struct node *node){
	//in-order: left, N, right
	if(node!=NULL){
		struct node *parent, *succ;
		parent = node->parent;
		if(parent==NULL || node->right!=NULL){
			succ = theirLeftMostChild(node->right);
		}else{
			while(parent!=NULL){
				if(parent->left==node) break;
				node = parent;
				parent = parent-> parent;
			}
			succ = parent;
		}
		return succ;
	}
	return NULL;
}


int main(){
  int i;
  struct node *root, *succ, *n;
  root = NULL;

  for(i=0;i<10;i++) root = insertNode(root, rand()%10, NULL);
  n=root->left->right; //just to try, may not always work 
  succ = theirSuccessor(n);
  return 0;
}
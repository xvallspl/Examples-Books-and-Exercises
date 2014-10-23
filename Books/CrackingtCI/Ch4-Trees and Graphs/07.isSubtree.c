
#include <stdlib.h>
#include <stdio.h>


struct node{
	int data;
	struct node *right;
	struct node *left;
};
//Finds first appearance
struct node *findNode(struct node *root, int data){
	if (root == NULL) return NULL;
	if(root->data!= data){
		struct node *finding;
		finding = findNode(root->right, data);
		return (finding->data == data) ? finding: findNode(root->left, data);
	}
	return root;
}
//Suposing just one appearance
int isSubtree(struct node *rootBig, struct node *rootSmall){
	struct node *start;
	start = findNode( rootBig, rootSmall->data);
	return checkSubTree(rootBig, start)
}

int checkSubTree(struct node *rootBig, struct node *rootSmall){
	if(rootBig==NULL && rootSmall==NULL) return 1;
	if(rootBig->data != rootSmall->data) return 0;
	else{
		return checkSubTree(rootBig->right, rootSmall->right) && 
			     checkSubTree(rootBig->left, rootSmall->left);
	}
}


/*You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds 
of nodes. Create an algorithm to decide if T2 is a subtree of T1.*/


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

int theirContainsTree(struct node *t1, struct node *t2) {
	if (t2 == NULL) 
		return 1; // The empty tree is always a subtree
	else 
		return theirSubTree(t1, t2);
}
int theirSubTree(struct node *r1, struct node *r2) {
	
	if (r1 == NULL) return 0; // big tree empty & subtree still not found.
	if (r1->data == r2->data) {
		if (theirMatchTree(r1,r2))
			return 1;
	}
	return (theirSubTree(r1->left, r2) || theirSubTree(r1->right, r2));
}

int theirMatchTree(struct node *r1, struct node *r2) {
	
	if (r2 == NULL && r1 == NULL)
		 return 1; // nothing left in the subtree
	if (r1 == NULL || r2 == NULL)
		 return 0; // big tree empty & subtree still not found
	if (r1->data != r2->data) 
		return 0; // data doesn’t match
	return (theirMatchTree(r1->left, r2->left) &&
			 theirMatchTree(r1->right, r2->right));
	}
}

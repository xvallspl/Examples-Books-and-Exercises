
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node *findNode(struct node *root, int data){
	if (root == NULL) return NULL;
	if(root->data!= data){
		struct node *finding;
		finding = findNode(root->right, data);
		return (finding->data == data) ? finding: findNode(root->left, data);
	}
	return root;
}


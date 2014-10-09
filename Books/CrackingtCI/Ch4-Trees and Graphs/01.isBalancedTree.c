#include <stdlib.h>
#include <stdio.h>

int cNode;

struct node{
	int data;
	struct node *right;
	struct node *left;
};


int isBalanced(struct node *tree){
	return (branchLength(tree)==-1)? 0 : 1; 
}

int branchLength(struct node *tree){
	int a, b;
	a = (tree->right!=NULL)? branchLength(tree) : 0;
	b = (tree->left!=NULL) ? branchLength(tree) : 0;	
	
	if( a == -1 || b == -1){
		return -1;
	}

	if(a == 0 && b == 0){
		return 1;
	}

	if( -1>(a-b) || (a-b)>1){
		return -1;
	}else{
		return max(a,b);
	}
}

void setTree(struct node **tree, int n){
	if(n>=2){
		(*tree)->data = n;
		n--;
		printf("%d\n", n);
		(*tree)->right = (struct node *) malloc(sizeof(struct node));
		(*tree)->left  = (struct node *) malloc(sizeof(struct node));
		setTree(&(*tree)->right, n/2);
		setTree(&(*tree)->left, n/2);
	}else{
		(*tree)->right=NULL;
		(*tree)->left=NULL;
	}
}

int main(){

	struct node *tree1,*tree2,*root1, *root2;
	int i, n;

	tree1 = (struct node *) malloc(sizeof(struct node));
	root1= tree1;
	tree2 = (struct node *) malloc(sizeof(struct node));
	root2= tree2;
	
	n=11;
	setTree(&tree1, n);
	setTree(&tree2, n);
}
#include <stdlib.h>
#include <stdio.h>

int cNode;

struct node{
	int data;
	struct node *right;
	struct node *left;
};


int isBalanced(struct node *tree){
	int a, b, max;
	a = (tree->right != NULL) ? isBalanced(tree->right) : -1;
	b = (tree->left  != NULL) ? isBalanced(tree->left) : -1;	
	
	if(a == 0 || b == 0){
		return 0;
	}

	if( a == -1 && b == -1){
		return 1;
	}

	a = (a == -1) ? a+1 : a;
	a = (b == -1) ? b+1 : b;
	max=(a>b)?a:b;
	return (abs(a-b)>1) ? 0 : max;
}

void setBalancedTreeExample(struct node **tree, int n){
	if(n>=2){
		(*tree)->data = n;
		n--;
		(*tree)->right = (struct node *) malloc(sizeof(struct node));
		(*tree)->left  = (struct node *) malloc(sizeof(struct node));
		setBalancedTreeExample(&(*tree)->right, n/2);
		setBalancedTreeExample(&(*tree)->left, n/2);
	}else{
		(*tree)->data = n;
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
	setBalancedTreeExample(&tree1, n);
	setBalancedTreeExample(&tree2, n);
	while(tree1->right!=NULL) tree1=tree1->right;
	tree1->right=(struct node *) malloc(sizeof(struct node));
	tree1->right->data=25;
	tree1=tree1->right;
	tree1->right=(struct node *) malloc(sizeof(struct node));
	tree1->right->data=50;
	printf("isBalanced applied to a non-balanced tree: %d\n", isBalanced(root1));
	printf("isBalanced applied to a balanced tree: %d\n", isBalanced(root2));


}
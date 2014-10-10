#include <stdlib.h>
#include <stdio.h>

int cNode;

struct node{
	int data;
	struct node *right;
	struct node *left;
};


int myIsBalanced(struct node *tree){
	int a, b, max;
	a = (tree->right != NULL) ? myIsBalanced(tree->right) : -1;
	b = (tree->left  != NULL) ? myIsBalanced(tree->left) : -1;	
	
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

int maxDepth(struct node *tree){
	int rightMaxLength, leftMaxLength;
	if(tree==NULL){
		return 0;
	}
	rightMaxLength = maxDepth(tree->right);
	leftMaxLength  = maxDepth(tree->left);
	return 1 + ((rightMaxLength > leftMaxLength) ? rightMaxLength : leftMaxLength);
}

int minDepth(struct node *tree){
	int rightMinLength, leftMinLength;
	if(tree==NULL){
		return 0;
	}
	rightMinLength = minDepth(tree->right);
	leftMinLength  = minDepth(tree->left);
	return 1 + ((rightMinLength > leftMinLength) ? leftMinLength : rightMinLength);

}

int theirIsBalanced(struct node *root){
	return (maxDepth(root) - minDepth(root)) <= 1;
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
	printf("My isBalanced applied to a non-balanced tree: %d\n", myIsBalanced(root1));
	printf("My isBalanced applied to a balanced tree: %d\n", myIsBalanced(root2));
	printf("Book's isBalanced applied to a non-balanced tree: %d\n", theirIsBalanced(root1));
	printf("Book's isBalanced applied to a balanced tree: %d\n", theirIsBalanced(root2));
}

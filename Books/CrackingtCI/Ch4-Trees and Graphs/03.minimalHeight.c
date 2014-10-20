// Given a sorted (increasing order) array, write an algorithm to create a binary tree with
// minimal height

#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

void mySetTree(int *array, struct node **tree, int n){
	int *rightArray, *leftArray, i;
	(*tree)->data=array[0];
	
	if((--n)<2){
		if(n==1){
			(*tree)->right = (struct node *) malloc(sizeof(struct node));
			(*tree)->right->data=array[1];

		}
		else{
			(*tree)->right=NULL;
		}
		(*tree)->left=NULL;
		return;
	}
		
	rightArray = malloc(sizeof(int)*n/2);
	leftArray = malloc(sizeof(int)*(n-n/2));
	(*tree)->right = (struct node *) malloc(sizeof(struct node));
	(*tree)->left  = (struct node *) malloc(sizeof(struct node));
	
	for(i=0;i<n/2;i++){
		rightArray[i] = array[i+1];
	}

	for(i=0;i<(n-n/2);i++){
		leftArray[i] = array[n/2+i+1];
	}	

	mySetTree(rightArray, &(*tree)->right, n/2);
	mySetTree(leftArray, &(*tree)->left, (n-n/2));

	free(leftArray);
	free(rightArray);
}

struct node *addToTree(int *array, int start, int end){
	if (end<start) return NULL;
	int mid;
	struct node *n;
	mid = (start+end)/2;
	n = (struct node *) malloc(sizeof(struct node));
	n->data = array[mid];
	n->left = addToTree(array, start, mid-1);
	n->right = addToTree(array, mid+1, end);
	return n;

}

struct node *theirSetTree(int *array, int n){
	return addToTree(array, 0, n-1);
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

int main(){
	int *array, n, i;
	struct node *tree, *root, *root2;
	n=10;
	array = (int *) malloc(n*sizeof(int));
	tree = (struct node *) malloc(sizeof(struct node));
	root =tree;

	for(i=0;i<n;i++){
		array[i] = i;
	}

	mySetTree(array, &tree, n);
	root2 = theirSetTree(array, n);
	printf("If my tree is balanced, It has minimum height. Is it balanced? %d\n", theirIsBalanced(root));
	printf("If their tree is balanced, It has minimum height. Is it balanced? %d\n", theirIsBalanced(root));

}

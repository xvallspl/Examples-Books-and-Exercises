// Given a sorted (increasing order) array, write an algorithm to create a binary tree with
// minimal height

#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

void set_tree(int *array, struct node **tree){
	int *rightArray, *leftArray, i, n;
	n = sizeof(array)/sizeof(array[1]);
	(*tree)->data=array[1];
	
	if((--n)==0) return;	
	
	rightArray = malloc(sizeof(int)*n/2);
	leftArray = malloc(sizeof(int)*(n-n/2));
	(*tree)->right = (struct node *) malloc(sizeof(struct node));
	(*tree)->left  = (struct node *) malloc(sizeof(struct node));
	
	for(i=0;i<n/2;i++){
		rightArray[i] = array[i];
	}

	for(i=0;i<(n-n/2);i++){
		leftArray[i] = array[n/2+i];
	}	

	set_tree(rightArray, &(*tree)->right);
	set_tree(leftArray, &(*tree)->left);

	free(leftArray);
	free(rightArray);
	return;
}

int main(){
	int *array, n, i;
	struct node *tree, *root;
	n=10;
	array = malloc(sizeof(int)*n);
	tree = (struct node *) malloc(sizeof(struct node));
	root =tree;

	for(i=0;i<n;i++){
		array[i] = i;
	}

	set_tree(array, &tree);
}

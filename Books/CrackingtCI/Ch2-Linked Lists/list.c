#include <stdlib.h>

struct node{
	int x;
	struct node* next;
};

void printList(struct node* n){
	while(n->next!=NULL){
		printf("%d, ", n->x );
		n=n->next;
	}
	printf("%d", n->x );
}

void deleteList(struct node* n){
	struct node *aux;
	while(n->next!=NULL){
		aux=n;
		n=n->next;
		free(aux);
	}
	free(n);	
}

struct node * createIntList(int start, int end){
	struct node *first, *nextNode, *aux;
	int i;
	first = (struct node *) malloc(sizeof(struct node));
	aux   = (struct node *) malloc(sizeof(struct node));
	first->x = start;
	first->next=aux;
	aux->x = start+1;
	for( i=start+2; i<end; i++){
		nextNode = (struct node *) malloc(sizeof(struct node));
		nextNode->x=i;
		aux->next=nextNode;
		aux=aux->next;
	}
	aux->next = NULL;

	return first;
}

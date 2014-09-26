#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node* next;
};

void printList(struct node* n){
	while(n->next!=NULL){
		printf("%d, ", n->x );
		n=n->next;
	}
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

void myRemoveRepeated(struct node* n){
	struct node *runner, *first, *aux;
	first=n;
	n=n->next;
	while(n->next!=NULL){
		runner=first;
		while(runner!=n){
			if(runner->x == n->x){
				aux->next = runner->next;
				runner=runner->next;
				free(aux);
			}else{
				aux=runner;
				runner=runner->next;
			}
		}
		n=n->next;
	}	
}


int main(){
	struct node *first, *nextNode, *aux;
	int i;
	first = (struct node *) malloc(sizeof(struct node));
	aux = (struct node *) malloc(sizeof(struct node));
	first->x = 0;
	first->next=aux;
	aux->x=5;
	for( i=2; i<10; i++){
		nextNode = (struct node *) malloc(sizeof(struct node));
		nextNode->x=i;
		aux->next=nextNode;
		aux=aux->next;
	}
	aux->next=NULL;
	printList(first);
	printf("\n");
	myRemoveRepeated(first);
	printList(first);
	printf("\n");
	//deleteList(first);
}
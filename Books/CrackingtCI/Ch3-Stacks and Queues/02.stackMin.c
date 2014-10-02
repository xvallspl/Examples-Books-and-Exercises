// How would you design a stack which, in addition to push and pop, also has a function 
// min which returns the minimum element? Push, pop and min should all operate in 
// O(1) time

#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
	struct node *min;
};

typedef struct node Stack;


void pop(struct node **top){
	if(*top!=NULL){
	struct node *aux;
	aux=*top;
	*top=(*top)->next;
	free(aux);
	}
}


void push(struct node **top, int data){
	struct node *aux;
	aux = (struct node *) malloc(sizeof(struct node));
	aux->data = data;
	if(*top!=NULL){
		aux->next = *top;
		aux->min = (data < (*top)->min->data)? aux : (*top)->min;
	}else{
		aux->next = NULL;
		aux->min = aux;
	}
	*top = aux;
}

int min(struct node *top){
	if(top!=NULL){
		return top->min->data;
	}
	return -1; //error code
}

int main(){

	struct node *top;
	top=NULL;
	push(&top,10);
	push(&top, 2);
	printf("Stacked: %d, %d\n", top->data,top->next->data);
	push(&top, 3);
	printf("Minimum after pushing a 3: %d\n", min(top));
	pop(&top);
	printf("Minimum after popping: %d\n", min(top));
	push(&top, 1);
	printf("Minimum after pushing a 1: %d\n", min(top));


	return 0;
}
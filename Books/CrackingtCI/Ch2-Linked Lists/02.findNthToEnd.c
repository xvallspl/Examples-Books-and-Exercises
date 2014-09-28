// Implement an algorithm to find the nth to last element of a singly linked list

#include <stdio.h>
#include "list.c"


struct node *myFindNToEnd(struct node *first, int n){
	struct node *aux, *aux2;
	int i, count;
	aux  = first;
	aux2 = first;
	count=1;

	while(aux->next!=NULL){
		aux=aux->next;
		count++;
	}

	for(i=0;i<(count-n);i++){
		aux2=aux2->next;
	}

	return aux2;
}

struct node *theirFindNToEnd(struct node *first, int n){
	
	if(first == NULL || n < 1){
		return NULL;
	}

	struct node *p1, *p2;
	int i, count;
	p1  = first;
	p2 = first;

	for (i=0;i<n-1; ++i){ // skip n-1 steps ahead
		if(p2 == NULL){   
			return NULL;  // not found since list size < n
		}
		p2 = p2->next;
	}

	while(p2->next!=NULL){
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}

int main(){
	struct node *first, *start;
	
	first = createIntList(0, 10);

	printList(first);
	printf("\n");
	start = myFindNToEnd(first, 5);
	printList(start);
	printf("\n");
	start = theirFindNToEnd(first, 5);
	printList(start);
	printf("\n");
	//deleteList(first);
}

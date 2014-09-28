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

int main(){
	struct node *first, *start;
	
	first = createIntList(0, 10);

	printList(first);
	printf("\n");
	start = myFindNToEnd(first, 5);
	printList(start);
	printf("\n");
	//deleteList(first);
}
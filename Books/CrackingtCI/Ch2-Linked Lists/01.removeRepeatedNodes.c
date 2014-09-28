#include <stdio.h>
#include "list.c"

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
	struct node *first;
	first = createIntList(0, 10);
	first->next->x=5;

	printList(first);
	printf("\n");
	myRemoveRepeated(first);
	printList(first);
	printf("\n");
	//deleteList(first);
}

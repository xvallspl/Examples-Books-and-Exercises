// Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node

#include <stdio.h>
#include "list.c"

void myDeletePointedNode(struct node *p){
	struct node *next_node;
	next_node = p->next;

	p->x = next_node->x;
	p->next = next_node->next;

	free(next_node);
}

int theirDeleteNode(struc node *n){
	if( n == NULL || n->next == NULL){
		return -1;
	}

	struct node *next;
	
	next = n->next;
	n->x = next->x;
	n->next = next->next;
	
	free(next_node);

	return 1;
}

int main(){
	struct node *first, *pointer;
	
	first = createIntList(0, 10);

	printList(first);
	printf("\n");
	pointer = first->next->next;
	myDeletePointedNode(pointer);
	printList(first);
	printf("\n");
	//deleteList(first);
}

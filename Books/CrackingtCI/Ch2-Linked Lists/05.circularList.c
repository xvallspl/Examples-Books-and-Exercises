//Given a circular linked list, implement an algorithm which returns node at the beginning of the loop

#include <stdio.h>
#include "list.c"

struct node * myLoopFinder(struct node *head){
	struct node *p1, *p2;
	int count, i;
	p1 = head;
	while(p1->next!=NULL){		
		p1 = p1->next;
		count++;
		p2=head;
		for(i = 0; i<count; i++){
			if(p2 == p1){
				return p2;
			}
			p2 = p2->next;
		}
	}
	return NULL;
}

struct node * theirLoopFinder(struct node *head){
	struct node *p1, *p2;
	p1 = head;
	p2 = head;

	// Find meeting point
	while(p2->next!=NULL){
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1==p2){
			break;
		}
	}

	// Error check - there is no meeting point, and therefore no loop
	if(p2->next == NULL){
		return NULL;
	}

	/* Move n1 to Head. Keep n2 at Meeting Point. Each are k steps 
	* from the Loop Start. If they move at the same pace, they must
	* meet at Loop Start. */ 
	p1 = head;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next; 
	}
	// Now n2 points to the start of the loop.
	return p2;
}

int main(){
	struct node *first, *p1, *p2;
	int i;
	
	first = createIntList(0, 10);
	p1 = first;	
	for(i = 0; i<5; i++){
		p1 = p1->next;
	}
	p2=p1;
	while(p1->next != NULL){
		p1 = p1->next;
	}
	p1->next=p2;
	printf("Starting loop at: %d\n", p2->x);
	p1 = myLoopFinder(first);
	printf("I retrieve the start of the loop at: %d\n", p1->x);
	p1 = theirLoopFinder(first);
	printf("They retrieve the start of the loop at: %d\n", p1->x);
	//deleteList(first);
}

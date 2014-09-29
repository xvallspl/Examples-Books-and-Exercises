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
	return head;
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
	printf("Retrieved loop at: %d\n", p1->x);
	//deleteList(first);
}

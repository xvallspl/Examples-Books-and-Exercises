// You have two numbers represented by a linked list, where each node contains a single digit The digits are stored in reverse order, such that the 1’s digit is at the head of the list Write a function that adds the two numbers and returns the sum as a linked list
// EXAMPLE
// Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
// Output: 8 -> 0 -> 8

#include <stdio.h>
#include "list.c"
#include <math.h>

//supposing both numbers have the same digits

struct node * mySum(struct node *n1, struct node *n2){
	struct node *first, *next;
	int d, res, i;

	first = (struct node *) malloc(sizeof(struct node));
	next = first;
	res=0;
	d = 1;
	printf("%d\n", n1->x);
	while(n1->next!=NULL){
		res += (n1->x + n2->x) * 1;
		next -> x = res/d % 10;
		next->next = (struct node *) malloc(sizeof(struct node));
		next = next->next;
		n1 = n1->next;
		n2 = n2->next;
		d*=10;
	}

	res += (n1->x + n2->x) * d;
	next->x = res/d % 10;
	next->next = NULL;

	return first;
}

struct node * intToList(int n, int digits){
	struct node *first, *next; 
	int exponent,i;
	
	exponent = 0;
	first = (struct node *) malloc(sizeof(struct node));
	next = first;
	for(i=0;i<digits-1;i++)
	{
		next -> x = n % 10;
		n = n / 10;
		exponent++;
		next->next = (struct node *) malloc(sizeof(struct node));
		next=next->next;
	}
	next->x = n% (int) pow(10, exponent);
	next->next = NULL;

    return first;
}

int main(){
	struct node *n1, *n2, *res;
	
	n1 = intToList(111, 3);
	n2 = intToList(108, 3);

	printList(n1);
	printf(" + ");
	printList(n2);
	printf("\n");
	res = mySum(n1, n2);
	printList(res);
	printf("\n");
	//deleteList(first);
}
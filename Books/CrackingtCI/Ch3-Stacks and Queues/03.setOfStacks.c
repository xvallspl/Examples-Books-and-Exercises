// Imagine a (literal) stack of plates. If the stack gets too high, it might topple. There-
// fore, in real life, we would likely start a new stack when the previous stack exceeds
// some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
// Stacks should be composed of several stacks, and should create a new stack once
// the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
// behave identically to a single stack (that is, pop() should return the same values as it
// would if there were just a single stack).
// FOLLOW UP
// Implement a function popAt(int index) which performs a pop operation on a specific
// sub-stack.


#include <stdlib.h>
#include <stdio.h>

//I could have pointed the bottom of a stack to the head of another one, but that won't
// be convenient for the follow up.

struct node{
	int data;
	struct node *next;
};

struct stack{
	struct node *top;
	struct stack *next;
	int capacity;
	int nItems;
};

int isFull(struct stack *s){
	return s->nItems == s->capacity;
}

int isEmpty(struct stack *s){
	return s->top == NULL;
}

void push(struct stack **s, int data){
	struct node *aux;
	aux = (struct node *) malloc(sizeof(struct node));
	aux->data = data;
	if(isFull(*s)){
		struct stack *auxStack;
		auxStack=(struct stack *) malloc(sizeof(struct stack));
		(auxStack)->next = *s;
		(auxStack)->capacity=(*s)->capacity;
		(auxStack)->nItems=0;
		*s=auxStack;
		(*s)->top = NULL;
	}
	if(!isEmpty(*s)){
		aux->next = (*s)->top;
	}else{
		aux->next = NULL;
	}
	(*s)->top = aux;
	(*s)->nItems++;
}

void pop(struct stack **s){
	if(!isEmpty(*s)){
		struct node *aux;
		aux=(*s)->top;
		(*s)->top=(*s)->top->next;
		(*s)->nItems--;
		free(aux);
	}
	if(isEmpty(*s) && (*s)->next!=NULL){
		*s=(*s)->next;
	}
}

void popAt(struct stack **s, int nStack){
	int i;
	for(i=1; i<nStack; i++){
		*s=(*s)->next;
		if(*s == NULL){
			return;
		}
	}
	pop(&(*s));
}

void nItemsAtStack(struct stack *s, int nStack){
	int i;
	for(i=1; i<nStack; i++){
		s=s->next;
		if(s == NULL){
			return;
		}
	}
	printf("Items of the stack n.%d: %d\n", nStack, s->nItems);
}

int main(){
	int i;
	int j=3;
	struct stack *setOfStacks;
	struct stack *setOfStacksFirst;
	setOfStacks = (struct stack *) malloc(sizeof(struct stack));
	setOfStacks->capacity=5;
	setOfStacks->nItems=0;
	setOfStacks->top=NULL;
	setOfStacksFirst=setOfStacks;

	for(i=0; i<9;i++){
		push(&setOfStacks, i);
	}

	printf("Two Stacks used of capacity %d\n", setOfStacks->capacity);
	printf("S2.top: %d, S2.nItems: %d\n", setOfStacks->top->data, setOfStacks->nItems);
	printf("S1.top: %d, S1.nItems: %d\n", setOfStacks->next->top->data, setOfStacks->next->nItems);
	pop(&setOfStacks);
	printf("nItems after popping once: %d\n", setOfStacks->nItems);
	pop(&setOfStacks);
	pop(&setOfStacks);
	pop(&setOfStacks);
	printf("Change of stack after bottom reached, S.top: %d, S.nItems: %d\n", 
		setOfStacks->top->data, setOfStacks->nItems);
	for(i=10; i<15;i++){
		push(&setOfStacks, i);
	}
	nItemsAtStack(setOfStacksFirst, 1);
	popAt(&setOfStacksFirst, 1);
	nItemsAtStack(setOfStacksFirst, 1);
	
	return 0;
}

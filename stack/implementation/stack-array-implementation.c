#include <stdio.h>
#include <limits.h>

#define MAX 500

// Structure of stack
struct stack {
	int top;
	int a[MAX];
};

// Parameters: (Pointer to stack, Item to push)
void push(stack *sp, int item) {
	if(sp->top == MAX-1) {
		printf("Stack is full, push operation leads to overflow\n");
		return;
	}
	++(sp->top);
	sp->a[sp->top] = item;
}

// Parameters: (Pointer to stack)
int pop(stack *sp) {
	if(sp->top == -1) {
		printf("Stack is empty, pop operation leads to underflow\n");
		return INT_MIN;	// indicate invalid pop operation
	}
	int item = sp->a[sp->top];
	--(sp->top);
	return item;	// return popped item
}

// Parameters: (Stack)
int peek(stack s) {
	if(s.top == -1) {
		printf("Stack is empty\n");
		return INT_MIN;	// indicate invalid peek operation
	}
	return s.a[s.top];	// return top of stack item
}

// Parameters: (Stack)
int size(stack s) {
	return (s.top+1);	// return number of items in stack
}

// Parameters: (Stack)
void traverse(stack s) {
	printf("Elements of stack (top to bottom): ");
	while(s.top != -1) {
		printf("%d ", s.a[s.top]);
		--(s.top);
	}
	printf("\n");
}

int main() {

	struct stack s;
	s.top = -1;	// initialize stack

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	printf("Size of stack = %d\n", size(s));
	traverse(s);

	pop(&s);
	pop(&s);
	printf("Current top element of stack = %d", peek(s));

	return 0;
}
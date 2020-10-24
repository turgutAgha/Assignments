#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_CAPACITY 4

struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = STACK_CAPACITY;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;

}

void deallocStack(struct Stack* stack){
	free(stack->array);
	free(stack);
	printf("Deallocated\n");
}

int isFull(struct Stack* stack){
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

void *resize(struct Stack* stack, float times){
	
	stack->capacity *= times;							// changing the value of stack->capacity
	
	int* temp;
	temp = (int*)malloc(stack->capacity * sizeof(int));				// creating temp with the capacity of stack
	for(int i = 0; i < stack->capacity; i++){					// looping through stack to copy its elements
		temp[i] = stack->array[i];
	}
	
	free(stack->array);								// freeing the memory for stack->array
	stack->array = temp;								// copying temp to stack->array
	printf("Stack is resized. Current capacity: %d\n", stack->capacity);

	free(temp);									// freeing the memory allocated for temp
}

void push(struct Stack* stack, int item){
	if(isFull(stack))
		resize(stack, 2);
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", stack->array[stack->top]);
}

int pop(struct Stack* stack){
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int peek(struct Stack* stack){
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

void shrink(struct Stack* stack){

	printf("\nPrevious capacity: %d\n", stack->capacity);
	
	if(stack->capacity >= (stack->top + 1) * 2){		// if the capacity is 2 times higher than or equal to top
		resize(stack, 0.5);				// use resize() function to half its capacity
	}
	else{
		printf("Capacity is not changed. Current capacity: %d\n\n", stack->capacity);
	}
}
int main(int args, char *argv[]){
		
	struct Stack* stack = createStack();			// creating stack

	push(stack, 23);					// pushing new elements
	push(stack, 43);
	push(stack, 29);
	push(stack, 34);
	push(stack, 42);

	shrink(stack); 						// to check for unused memory

	printf("%d is popped\n", pop(stack));			// popping some elements
	printf("%d is popped\n", pop(stack));
	printf("%d is popped\n", pop(stack));
	
	shrink(stack);						// to check for unused memory
	
	deallocStack(stack);					// freeing the allocated memory
	return 0;
}

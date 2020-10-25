#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_CAPACITY 2

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
	//printf("Deallocated\n");
}

int isFull(struct Stack* stack){
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

void *resize(struct Stack* stack){
	int * temp;
	temp = (int*)malloc(stack->capacity * sizeof(int));

	for(int i = 0; i < stack->capacity; i++){
		temp[i] = stack->array[i];
	}
	
	stack->capacity *= 2;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));

	for(int i = 0; i < stack->capacity / 2; i++){
		stack->array[i] = temp[i];
	}

	//printf("Stack is resized, new length: %d\n", stack->capacity);
}

void push(struct Stack* stack, int item){
	if(isFull(stack))
		resize(stack);
	stack->array[++stack->top] = item;
	//printf("%d pushed to stack\n", stack->array[stack->top]);
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

int main(int args, char *argv[]){					// it is used to take a commandline argument
	if(args == 2){
		
		struct Stack* stack = createStack();			// creating stack

		int lgth = 0;
		while(argv[1][lgth] != '\0')
			lgth++;						// to find the length of argument
				
		for(int i = 0; i < lgth/2; i++){
			push(stack, argv[1][i]);			// pushing only half of the arguments' characters to stack
		}
		bool flag = true;
		for(int i = lgth/2; i < lgth; i++){			// to check the other part with LIFO logic.
			if(argv[1][i] == ']'){
				if(pop(stack) != '['){
					flag = false;
					break;
				}
			}
			else if(argv[1][i] == '['){
				if(pop(stack) != ']'){
					flag = false;
					break;
				}
			}
			else if(argv[1][i] == '('){
				if(pop(stack) != ')'){
					flag = false;
					break;
				}
			}
			else if(argv[1][i] == ')'){
				if(pop(stack) != '('){
					flag = false;
					break;
				}
			}
			else if(argv[1][i] == '}'){
				if(pop(stack) != '{'){
					flag = false;
					break;
				}
			}
			else if(argv[1][i] == '{'){
				if(pop(stack) != '}'){
					flag = false;
					break;
				}
			}
			else{
				printf("Undefined symbol. Only {, }, [, ], (, ) are allowed\n");
				return 0;
			}
		}

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
		
		deallocStack(stack);
	}
	else{
		printf("One argument is expected\n");
	}

	return 0;
}

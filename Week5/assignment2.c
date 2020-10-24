#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_CAPACITY 2

struct Stack {
	int top;
	unsigned capacity;
	char* array;
};

struct Stack* createStack(){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = STACK_CAPACITY;
	stack->top = -1;
	stack->array = (char*)malloc(stack->capacity * sizeof(char));
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
	char * temp;
	temp = (char*)malloc(stack->capacity * sizeof(char));

	for(int i = 0; i < stack->capacity; i++){
		temp[i] = stack->array[i];
	}
	
	stack->capacity *= 2;
	stack->array = (char*)malloc(stack->capacity * sizeof(char));

	for(int i = 0; i < stack->capacity / 2; i++){
		stack->array[i] = temp[i];
	}

	//printf("Stack is resized, new length: %d\n", stack->capacity);
}

void push(struct Stack* stack, char item){
	if(isFull(stack))
		resize(stack);
	stack->array[++stack->top] = item;
	//printf("%c pushed to stack\n", stack->array[stack->top]);
}

char pop(struct Stack* stack){
	if(isEmpty(stack))
		return '0';
	return stack->array[stack->top--];
}

char peek(struct Stack* stack){
	if(isEmpty(stack))
		return '0';
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

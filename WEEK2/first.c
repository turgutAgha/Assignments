#include<stdio.h>

void swap1(int val1, int val2);

int main(){

	//initializing val1 and val2
	int val1, val2;
	
	//taking inputs
	scanf("%d %d", &val1, &val2);

	//printing val1 and val2 before swapping
	printf("\nBefore swapping:\n");	
	printf("Value1: %d\nValue2: %d\n", val1, val2);

	swap1(val1, val2);

}

void swap1(int val1, int val2){
	
	int temp = val1;
	val1 = val2;
	val2 = temp;

	//printing numbers after swapping
	printf("\nAfter swapping: \n");
	printf("Value1: %d\nValue2: %d\n", val1, val2);
}

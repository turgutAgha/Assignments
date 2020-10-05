#include <stdio.h>
void swapStrings(char *destination, char *source);

int main(){
	// initializing and defining str1 and str2
	char str1[] = "Hello";
	char str2[] = "World";
	
	// printing str1 and str2 before swapping
	printf("str1: %s, str2: %s\n", str1, str2);
	
	// using swap function
	swapStrings(str1, str2);

	// printing str1 and str2 after swapping
	printf("str1: %s, str2: %s\n", str1, str2);
	return 0;
}


void swapStrings(char *destination, char *source){
	char temp;
	int len = 0;
	// finding the length of strings;
	while(destination[len]!='\0')
		len++;

	for(int i = 0; i < len; i++){		// using temp to copy one char array and change it with another
		temp = destination[i];
		destination[i] = source[i];
		source[i] = temp;
	}
}

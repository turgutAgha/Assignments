#include <stdio.h>
void swapStrings(char **destination, char **source);

int main(){
	// initializing and defining char pointers str1 and str2
	char *str1 = "C programming";
	char *str2 = "Language";
	
	// printing str1 and str2 before swapping
	printf("str1: %s, str2: %s\n", str1, str2);
	
	// using swap function
	swapStrings(&str1, &str2);

	// printing str1 and str2 after swapping
	printf("str1: %s, str2: %s\n", str1, str2);
	return 0;
}


void swapStrings(char **destination, char **source){
	
	char *temp = *destination;
	*destination = *source;
	*source = temp;
}

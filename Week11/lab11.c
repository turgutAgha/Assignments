#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 34

bool readline(char* buf, int num, FILE * stream){
	size_t freadsize = fread(buf, 1, num-1, stream);
	while(freadsize >= 1){
		for(int i = 0; i < num; i++){
			if(buf[i] == '\n'){
				buf[i] = '\0';
				break;
			}
		}
		return true;
	}
	return false;
}

int main(int argc, char ** argv){

	if(argc < 2){
		printf("1 argument is needed");
		exit(1);
	}

	char buf[MAX_LINE_SIZE];
	FILE * infile;
	
	infile = fopen(argv[1], "r");

	if(infile == NULL){
		printf("Error opening file");
		exit(1);
	}

	while(readline(buf, MAX_LINE_SIZE, infile)){
		printf("another line: %s\n", buf);	
	}
	fclose(infile);

	return 0;
}

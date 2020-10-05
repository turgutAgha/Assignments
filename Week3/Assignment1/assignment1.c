#include <stdio.h>
void swapArrays(int a1[], int a2[], int len);
void print2DArr(int *arr2D[], int rows, int columns);

int main(){
	int a1[] = {1, 2, 3, 4, 5};
	int a2[] = {0, 0, 0, 0, 0};
	int len = sizeof(a1)/sizeof(int);
	int *arr2D[2] = {a1, a2};

	// printing the content of arr2D before swapping	
	print2DArr(arr2D, 2, len);

	// swapping the elements of a1 and a2
	swapArrays(a1, a2, len);

	// printing the content of arr2D after swapping	
	print2DArr(arr2D, 2, len);
	return 0;
}

void swapArrays(int a1[], int a2[], int len){
	int temp;
	for(int i = 0; i < len; i++){
		temp = a1[i];							// using temp to copy values in one array
		a1[i] = a2[i];							// and swapping the values of arrays
		a2[i] = temp;
	}
}

void print2DArr(int *arr2D[], int rows, int columns){
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(i == rows-1 && j == columns - 1) 			// for last element to make sure that
				printf("%d\n", *(*(arr2D + i) + j)); 		// there is no empty ' ' after printing value
			else
				printf("%d ", *(*(arr2D + i) + j));		// *(*(arr2D + i) + j) is equalent to arr2D[i][j]
		}
	}

}

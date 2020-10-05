## Week3
## Assignment 1

A c program that takes two integer arrays and merges them into one 2D array. It then prints the contents of 2D array using function called print2DArr. Then it swaps those two arrays using a new function called swapArrays and again prints 2D array.

## How print2DArr function works

It takes 2D array, number of rows and columns as arguments. By using rows and columns, it loops inside 2D array and prints values with the help of pointers in a flattened shape.

```bash
//inside loop
printf("%d\n", *(*(arr2D + i) + j));

```

## How swapArrays function works

It takes two integer arrays and length of them as arguments. By using new integer called temp it copies contents of one array one by one and swaps their values.

```bash
int temp;

//inside loop
temp = a1[i];
a1[i] = a2[i];
a2[i] = temp;

```

## Week3
## Assignment2
## Method 2

In this strings without depending on length can be swapped, but it cannot be applied for strings stored in char arrays. It takes char pointers and assigns different strings to them. It uses swapStrings function to swap the strings using their addresses.

## How swapStrings function works

It takes the addresses of char pointers as arguments in order to swap these pointers themselves. It uses third user defined char pointer called temp which helps to change pointers.

```bash
void swapStrings(char **destination, char **source){
        char *temp = *destination;
        *destination = *source;
        *source = temp;
}
```

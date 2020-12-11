#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 90

int checker(char* password, char* guess, int length){
    int len_guess = 0;
    int i;
    char quit[] = "!quit";
    bool flag1 = true;
    for(i = 0; i < 5; i++){
        if(guess[i] != quit[i]){
            flag1 = false;
            break;
        }
    }
    if(flag1)
        return 1;
    i = 0;
    while(guess[i] != '\0'){
        len_guess++;
        i++;
    }

    if(len_guess != length)
        return 2;
    else{
        flag1 = true;
        for(i = 0; i < length; i++){
            if(guess[i] != password[i]){
                flag1 = false;
                break;
            }
        }
        if(!flag1)
            return 3;
        else
            return 4;
    }
}

void correctness(char* password, char* guess, int length){
    for(int i = 0; i < length; i++){
        if(password[i] == guess[i])
            printf("+");
        else{
            bool flag = false;
            for(int j = 0; j < length; j++){
                if(password[j] == guess[i]){
                    flag = true;
                    break;
                }
            }
            if(flag)
                printf("!");
            else
                printf(".");
        }
    }
    printf("\n");
}

void gameplay(char* password, int length, int chances){
    printf("Welcome to Fallout 3 hacking minigame!\n");
    printf("The passphrase contains %d letters\n", length);
    bool isWinner = false;
    while(chances > 0){
        printf("you have %d tries left: ", chances);
        char* guess = (char*)malloc(sizeof(char)* BUF_SIZE);
        scanf("%s", guess);
        int quit = 0;
        int check = checker(password, guess, length);
        switch (check) {
            case 1:
                quit = 1;
                break;
            case 2:
                printf("Wrong number of characters, try again.\n");
                chances--;
                break;
            case 3:
                printf("incorrect, here's how you did:\n");
                printf("%s\n", guess);
                correctness(password, guess, length);
                chances--;
                break;
            case 4:
                printf("correct, here's how you did:\n");
                printf("%s\n", guess);
                correctness(password, guess, length);
                quit = 1;
                isWinner = true;
                break;
        }
        if(quit == 1)
            break;
        free(guess);
    }

    if(isWinner)
        printf("you win!\n");
    else
        printf("game over!\n");
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("1 argument is needed\n");
        exit(1);
    }

    FILE * stream = fopen(argv[1], "rb");
    char* buf = (char*)malloc(sizeof(char) * BUF_SIZE);
    buf[BUF_SIZE-1] = '\0';

    if(stream == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    fread(buf, 1, BUF_SIZE, stream);

    char* cont_password = (char*) malloc(sizeof(char) * BUF_SIZE);
    int cont_length = 0, cont_chances = 0;
    int counter = 0, c = 0, i = 0;

    while(buf[i] != '\0' && counter <= 2){
        if(buf[i] != ' '){
            if(counter == 0) {
                cont_password[c] = buf[i];
                c++;
            }
            else if(counter == 1) {
                if(buf[i] - '0' <= 9)
                    cont_length = 10 * cont_length + (buf[i] - '0');
            }
            else if(counter == 2) {
                if(buf[i] - '0' <= 9)
                    cont_chances = 10 * cont_chances + (buf[i] - '0');
            }
            i++;
        }
        else {
            if (counter == 0) {
                cont_password[c] = '\0';
            }
            for (int j = 0; j < BUF_SIZE; j++) {
                if (buf[i] == ' ')
                    i++;
                else
                    break;
            }
            counter++;
        }
    }
    gameplay(cont_password, cont_length, cont_chances);

    free(buf);
    free(cont_password);
    return 0;
}

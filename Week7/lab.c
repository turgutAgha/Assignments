#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct queue{
        char name[256];
        struct queue * next;
} queue_t;

void append(queue_t ** head, char * name){
        queue_t * nextNode = *head;

        while(nextNode->next != NULL){
                nextNode = nextNode->next;
        }
        nextNode->next = (queue_t *) malloc(sizeof(queue_t*));
        strcpy(nextNode->next->name, name);
        nextNode->next->next = NULL;
}

void admit(queue_t **head){
        queue_t * next_node = NULL;

        if(*head == NULL)
                return;

        next_node = (*head)->next;

        free(*head);
        *head = next_node;
}

void luckyCustomer(queue_t ** head, char *name){

        queue_t * curr = *head;
        queue_t * temp = NULL;

        if(strcmp((*head)->name, name) == 0){
                admit(head);
        }
        else{
                while(strcmp(curr->next->name, name) != 0){
                        if(curr == NULL)
                                return;
                                
                        curr = curr->next;
                }

                temp = curr->next;
                if(temp == NULL)
                        return;
                curr->next = temp->next;
                free(temp);
        }
        
        append(head, name);

}

void print_queue(queue_t *head){
        printf("Queue: ");
        while(head->next != NULL){
                printf("%s, ", head->name);
                head = head->next;
        }
        if(head != NULL)
                printf("%s\n", head->name);
}

int main(){
        queue_t *head = (queue_t*) malloc(sizeof(queue_t));
        strcpy(head->name, "Turgut");
        head->next = NULL;

        append(&head, "Nazrin");
        append(&head, "Nigar");
        append(&head, "Kamran");
        append(&head, "Eljan");



        char input[256];
        bool quit = 0;
        while(!quit){
                print_queue(head);
                printf("Enter a command: ");
                scanf("%s", &input);
                printf("\n");
                if(*input == 'q'){
                        quit = 1;
                }
                else if(strcmp(input, "admit") == 0){
                        admit(&head);
                }
                else{
                        luckyCustomer(&head, input);
                }
        }
}

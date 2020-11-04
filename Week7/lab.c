#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct queue{
        char name[256];
        struct queue * next;
} queue_t;

void append(queue_t ** head, char * name){
        queue_t * lastNode = *head;
        while(lastNode->next != NULL){
                lastNode = lastNode->next;
        }
        queue_t * nextNode = (queue_t *) malloc(sizeof(queue_t));
        strcpy(nextNode->name, name);
        nextNode->next = NULL;
        lastNode->next = nextNode;
}

void admit(queue_t **head){
        if(*head == NULL){
                printf("There is no customer\n");
                return;
        }

        queue_t *next_node = (*head)->next;
        free(*head);
        *head = next_node;
}

void luckyCustomer(queue_t ** head, char *name){
        if(*head == NULL){
                printf("Customer doesn't exist\n");
                return;
        }

        queue_t * curr = *head;
        queue_t * temp = NULL;
        
        if(curr != NULL && strcmp(curr->name, name) == 0){
                if(curr->next == NULL)
                        return;
                admit(head);
        }
        else{
                while(curr->next != NULL && strcmp(curr->next->name, name) != 0){         
                        curr = curr->next;
                }
                temp = curr->next;
        
                if(temp == NULL){
                        printf("Customer doesn't exist\n");
                        return;
                }
                curr->next = temp->next;
        }     
        append(head, name);
        free(temp);
}

void print_queue(queue_t *head){
        printf("Queue: ");
        while(head != NULL){
                printf("%s", head->name);
                head = head->next;
                if(head != NULL)
                        printf(", ");
        }
        printf("\n");
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
                scanf("%s", input);
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

        queue_t *curr = head;
        queue_t *temp = NULL;
        while(curr != NULL){
                temp = curr->next;
                free(curr);
                curr = temp;
        }
        free(curr);
        free(head);
        head = NULL;
        return 0;
}

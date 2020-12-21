#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node * next;
    bool isChecked;
};

void append(struct Node** head, int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->isChecked = false;
    new_node->next = NULL;

    struct Node* last = *head;

    if(last == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void printList(struct Node* iter){
    printf("result: ");
    while(iter->next != NULL){
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("%d\n", iter->data);
}

void swap(struct Node** target, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp_next = *target;
    int index = 0;
    while(temp_next != NULL){
        if(temp_next->data == data)
            break;
        index++;
        temp = temp_next;
        temp_next = temp_next->next;
    }

    if (index != 0) {
        temp->next = temp->next->next;
        temp_next->next = temp->next->next;
        temp->next->next = temp_next;
    }
    else{
        temp->data = (*target)->next->data;
        temp->isChecked = (*target)->next->isChecked;
        temp->next = *target;
        *target = temp;
        (*target)->next->next = (*target)->next->next->next;
    }
}

bool isPossible(struct Node** head, int data){
    struct Node* target = *head;
    if(target == NULL)
        return false;

    while(target != NULL){
        if(target->data == data)
            break;
        target = target->next;
    }
    if(target == NULL || target->next == NULL)
        return false;
    if(target->isChecked == true || target->next->isChecked == true)
        return false;

    target->isChecked = true;
    target->next->isChecked = true;

    return true;
}

int main(){
    struct Node* head = NULL;
    int data;
    char input[10];

    printf("Enter numbers to add to your list:\n");
    scanf("%s", input);
    while(strcmp(input, "DONE") != 0){
        data = atoi(input);
        append(&head, data);
        scanf("%s", input);
    }

    printf("Type two numbers to swap them around:\n");
    scanf("%s", input);
    while(strcmp(input, "DONE") != 0){
        data = atoi(input);
        if(isPossible(&head, data)) {
            swap(&head, data);
            printList(head);
        }
        else
            printf("No swap candidates found. Try again:\n");
        scanf("%s", input);
    }
    free(head);
    
    return 0;
}


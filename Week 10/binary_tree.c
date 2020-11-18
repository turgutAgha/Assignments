#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
        int value;
        struct Node* left;
        struct Node* right;
} node_t;

node_t * newNode(int value){
        node_t* node = (node_t*) malloc(sizeof(node_t));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        return (node);
}

int maxSum(node_t* iter){
        if(iter == NULL)
                return 0;

        int ans;
        if(maxSum(iter->left) > maxSum(iter->right))
                ans = iter->value + maxSum(iter->left);
        else
                ans = iter->value + maxSum(iter->right);
        return ans;
}

int main(){
        node_t* root = newNode(1);
        root->left = newNode(5);
        root->right = newNode(10);
        root->left->left = newNode(20);
        root->left->right = newNode(4);
        root->right->left = newNode(21);
        root->right->right = newNode(20);
        root->left->left->left = newNode(999);
        root->right->left->left = newNode(13);
        root->right->right->right = newNode(15);

        printf("max sum: %d", maxSum(root));
}

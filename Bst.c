#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int data){
    if(root == NULL){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    
    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;
    
    // Inserting elements in the BST
    root = insert(root, 7);
    root = insert(root, 90);
    root = insert(root, 89);
    root = insert(root, 65);
    root = insert(root, 1);
    root = insert(root, 0);
    
    // Printing the values in inorder traversal
    printf("In-order traversal: ");
    inorder(root);
    
    return 0;
}
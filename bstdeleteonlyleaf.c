#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

Node* deleteLeaves(Node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    
    root->left = deleteLeaves(root->left);
    root->right = deleteLeaves(root->right);
    
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("Inorder traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    root = deleteLeaves(root);
    
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}

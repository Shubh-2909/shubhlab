#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* buildTree(struct Node** root) {
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    *root = (struct Node*)malloc(sizeof(struct Node));
    (*root)->data = data;

    printf("Enter data for insertion in the left of %d: \n", data);
    (*root)->left = buildTree(&((*root)->left));

    printf("Enter data for insertion in the right of %d: \n", data);
    (*root)->right = buildTree(&((*root)->right));

    return *root;
}

void inorder(struct Node* root){
    if((root) != NULL){
        inorder((root)->left);
        printf("%d ", (root)->data);
        inorder((root)->right);
    }
}

int main(){
    struct Node* root = NULL;
    buildTree(&root);
    inorder(&root);

    return 0;
}

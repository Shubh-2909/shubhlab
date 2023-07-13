#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isStackEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed element: %d\n", element);
}

void pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return;
    }
    
    Node* poppedNode = stack->top;
    int poppedElement = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    printf("Popped element: %d\n", poppedElement);
}

int main() {
    Stack stack;
    initializeStack(&stack);
    
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    
    pop(&stack);
    
    push(&stack, 20);
    
    return 0;
}

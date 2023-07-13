#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isQueueEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool isQueueFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(Queue *queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    
    if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    
    queue->data[queue->rear] = element;
    printf("Enqueued element: %d\n", element);
}

void dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }
    
    int element = queue->data[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    
    printf("Dequeued element: %d\n", element);
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    
    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);
    
    dequeue(&queue);
    
    enqueue(&queue, 20);
    
    return 0;
}

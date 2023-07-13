#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Structure representing a circular queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
bool isEmpty(CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
bool isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Circular queue is full. Enqueue operation failed.\n");
        return;
    } else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the circular queue
void dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty. Dequeue operation failed.\n");
        return;
    } else if (queue->front == queue->rear) {
        printf("Dequeued: %d\n", queue->items[queue->front]);
        queue->front = -1;
        queue->rear = -1;
    } else {
        printf("Dequeued: %d\n", queue->items[queue->front]);
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

// Function to display the elements in the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue elements:\n");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 50);
    enqueue(&queue, 60);

    display(&queue);

    return 0;
}

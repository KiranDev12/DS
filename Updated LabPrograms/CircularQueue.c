#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((front == 0 && rear == MAX_SIZE-1) || (front == rear+1)) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
    }
}

int dequeue() {
    int data = -1;
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        data = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    return data;
}

int front_element() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return queue[front];
    }
}

int rear_element() {
    if (rear == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return queue[rear];
    }
}

int is_full() {
    if ((front == 0 && rear == MAX_SIZE-1) || (front == rear+1)) {
        return 1;
    } else {
        return 0;
    }
}

int is_empty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

int size() {
    if (front == -1) {
        return 0;
    } else {
        return ((rear+MAX_SIZE-front) % MAX_SIZE) + 1;
    }
}

int main() {
    // Test the circular queue implementation
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6); // Queue is full
    printf("Front element: %d\n", front_element());
    printf("Rear element: %d\n", rear_element());
    printf("Dequeued element: % d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Front element: %d\n", front_element());
    printf("Is queue full? %d\n", is_full());
    printf("Is queue empty? %d\n", is_empty());
    printf("Queue size: %d\n", size());
    return 0;
}

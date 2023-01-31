#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef struct Queue{
    int front, rear, size;
    int arr[MAXSIZE];
}queue;

queue * enqueue(queue * ptr, int key){
    if (ptr->rear == ptr->size - 1)
    {
        printf("Queue Overflow\n");
    }
    else{
        if (ptr->front == -1)
        {
            ptr->front++;
        }
        ptr->rear++;
        ptr->arr[ptr->rear]= key;
    }
    return ptr;
}
queue * dequeue(queue * ptr){
    if (ptr->front == -1 || ptr->front>ptr->rear)
    {
        printf("Queue Underflow\n");
    }
    else{
        ptr->front++;
    }
    return ptr;
}
void display(queue * ptr){
    printf("\n");
    if (ptr->front>ptr->rear|| ptr->front == -1)
    {
        printf("Queue is empty\n");
    }

    for (int i = ptr->front; i <= ptr->rear; i++)
    {
        printf("%d\t", ptr->arr[i]);
    }
}
int main(){
    queue * ptr = (queue *)malloc(sizeof(queue));
    ptr->front = ptr->rear = -1;
    printf("Enter the size of the queue");
    scanf("%d", &ptr->size);
    enqueue(ptr, 5);
    enqueue(ptr, 4);
    enqueue(ptr, 7);
    enqueue(ptr, 1);

    display(ptr);

    dequeue(ptr);
    dequeue(ptr);
    dequeue(ptr);
    dequeue(ptr);

    display(ptr);

    enqueue(ptr, 10);
    enqueue(ptr, 20);

    display(ptr);

    dequeue(ptr);
    dequeue(ptr);
    dequeue(ptr);
    display(ptr);
}
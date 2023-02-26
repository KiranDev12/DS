#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node * createNode(int key){
    node * newnode = malloc(sizeof(node));
    newnode->data = key;
    newnode->next = newnode;
    return newnode;
}
int size(node * head){
    int count = 0;
    node * temp = head;
    while (temp->next!=head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node * insertFront(node * head, int key){
    node * newnode = createNode(key);
    if (head == NULL)
    {       
        head = newnode;
        newnode->next = head;
        return head;
    } 
    newnode->next = head;
    node * temp = head;
    while (temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    head = newnode;
    return head;
}

node * insertRear(node * head, int key){
    node * newnode = createNode(key);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return head;
    }
    node * temp = head;
    while (temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    return head;
}

node * insertByPos(node * head, int key, int pos){
    if (pos<=0 || pos >= size(head))
    {
        return NULL;
    }
}
void display(node * head){
    node * temp = head->next;
    printf("%d\n", head->data);
    if (head == NULL)
    {
        printf("\n\nEmpty Linked list\n");
    }
    
    while (temp!=head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    node * head = NULL;
    // head = insertFront(head, 5);
    head = insertFront(head, 1);
    head = insertFront(head, 2);
    head = insertFront(head, 10);
    display(head);
    head = insertRear(head, 9);
    head = insertRear(head, 9);
    head = insertRear(head, 9);
    display(head);
    head = insertByPos(head, 10, 7);
    display(head);
}
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void traversalCircular(struct Node* head){
    struct Node *p = head;
    
    do{
        printf("%d\n", p->data);
        p = p->next;
    }while(p!=head);
    
}


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    
    head -> data = 7;
    head -> next = second;

    second -> data = 11;
    second -> next = third;    

    third -> data = 22;
    third -> next = fourth;

    fourth -> data = 52;
    fourth -> next = head;

    traversalCircular(head);
    return 0;
}
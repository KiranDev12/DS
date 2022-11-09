#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr -> next;
    }
}

// CASE 1

struct Node * deleteFirst(struct Node* head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// CASE 2

struct Node * deleteAtIndex(struct Node* head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

// CASE 3

struct Node * deleteAtLast(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;

    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    
    return head;
}
// CASE 4

struct Node * deleteByValue(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
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
    fourth -> next = NULL;

    printf("Linked list before deletion: \n");
    traversal(head);

    // head = deleteFirst(head);

    // head = deleteAtIndex(head, 2);

    // head = deleteAtLast(head);

    head = deleteByValue(head, 7);
 
    printf("Linked list after deletion: \n");
    traversal(head);
    
    return 0;
}
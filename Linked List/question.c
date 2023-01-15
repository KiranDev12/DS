// write a circular code to insert at position using header node as reference without using pointer to the head node
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
int size;
struct node * read(struct node * header){
    struct node * temp = header;
    printf("Enter datas: \n");
    for (int i = 0; i < size; i++)
    {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        temp->next = newnode;
        newnode->next = header;
        temp = newnode;
    }
    return header;
}

void display(struct node * header){
    struct node * temp = header->next;
    while (temp != header)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
struct node * insertPos(struct node * header){
    struct node * temp = header->next;
    int pos;
    scanf("%d", &pos);
    if(pos == 1){
        size++;
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = header->next;
        header->next = newnode;
        return header;
    }
    for (int i = 0; i < pos - 2; i++)
        temp = temp->next;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
    size ++;
    return header;
}
int main(){
    printf("Enter number of nodes: ");
    scanf("%d", &size);
    struct node* header = (struct node * )malloc(sizeof(struct node));
    header->data = size;
    header->next = header;
    header = read(header);
    header = insertPos(header);
    display(header);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int size;
struct node
{
    int data;
    struct node *next;
};

struct node *read(struct node *head)
{
    struct node *newnode, *temp;
    printf("Enter the data of nodes\n");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;

    for (int i = 0; i < size - 1; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct node *temp = head;
        printf("Elements: ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

struct node *insertFront(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertEnd(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return head;
}

struct node *insertPos(struct node *head, int pos)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertFront(head);
    }
    else
    {
        struct node *temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

struct node *deleteFront(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        size--;
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node *deleteEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        size--;
        struct node *prev = head;
        while (prev->next->next != NULL)
        {
            prev = prev->next;
        }
        struct node *temp = prev->next;
        free(temp);
        prev->next = NULL;
    }
    return head;
}

struct node *deletePos(struct node *head)
{
    int pos;
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = deleteFront(head);
    }
    else
    {
        struct node *prev = head;
        for (int i = 0; i < pos - 2; i++)
        {
            prev = prev->next;
        }
        struct node *temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
    return head;
}

struct node *deleteKey(struct node *head)
{

    int key;
    printf("Enter the key you want to delete ");
    scanf("%d", &key);

    struct node *prev = head;

    while (prev->next->data != key)
    {
        prev = prev->next;
    }

    struct node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return head;
}

void search(struct node *head)
{
    int pos = 1, key;
    printf("Enter the key ");
    scanf("%d", &key);
    struct node *temp = head;
    while (temp->data != key && temp->next != NULL)
    {
        temp = temp->next;
        pos += 1;
    }

    if (temp->data == key)
    {
        printf("The element %d is found at %d\n", key, pos);
    }
    else
    {
        printf("Element not found\n");
    }
}

struct node *orderedList(struct node *head, int size)
{
    
}

struct node * copy(struct node * head){
    if(head == NULL){
        return NULL;
    }
    else
    {
        struct node* newnode=malloc(sizeof(struct node));
        newnode->data = head->data;
        newnode->next = copy(head->next);
        return newnode;
    }
}

struct node * reverse(struct node *head){
    struct node * prev, * current;
}
int main()
{
    struct node *head;
    printf("Enter No of nodes Required\n");
    scanf("%d", &size);
    head = (struct node *)malloc(sizeof(struct node));

    int ch;
    while (1<2)
    {
        printf("Choices Available\n1.Read\n2.Display\n3.Insert(Front)\n4.Insert(Rear)\n5.Insert(Pos)\n6.Delete(Front)\n7.Delete(Rear)\n8.Delete(Pos)\n9.Delete(key)");
        printf("10.Search(key)\n11.Create an ordered list\n12.Reverse\n13.Create a copy of the list\n14.Free");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            read(head);
            break;
        
        case 2:
            display(head);
            break;

        case 3: 
            head = insertFront(head);
            break;

        case 4:
            head = insertEnd(head);
            break;
        
        case 5:
            head = insertPos(head, size);
            break;

        case 6:
            head = deleteFront(head);
            break;

        case 7:
            head = deleteEnd(head);
            break;
        
        case 8:
            head = deletePos(head);
            break;
        
        case 9:
            head = deleteKey(head);
            break;
        
        case 10:
            search(head);
            break;

        case 11:
            head = orderedList(head, size);
            break;

        case 12:
            head = reverse(head);
            break;

        case 13:
            display(copy(head));
            break;

        default:
            break;
        }
    }
    return 0;
}
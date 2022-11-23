#include <stdio.h>
#include <stdlib.h>
int size = 0;

typedef struct node
{
    int data;
    struct node *next;
} node;

node *display(node *head)
{
    node *temp = head;

    if (size == 0)
    {
        printf("Linked list empty\n");
        return head;
    }

    printf("Linked list is--> ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    return head;
}

node *insertAtPos(node *head, int pos, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (pos <= 0 || pos > size + 1)
    {
        printf("Inavlid Position\n");
        return head;
    }
    if (size == 0)
    {
        head = newnode;
        size++;
        display(head);
        return head;
    }

    if (pos == 1)
    {
        node *temp = head;
        newnode->next = head;
        head = newnode;
        size++;
        display(head);
        return head;
    }

    if (pos == size + 1)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        size++;
        display(head);
        return head;
    }

    else
    {
        node *temp = head;
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
        display(head);
        return head;
    }
}

node *deleteAtPosition(node *head, int pos)
{
    if (size == 0)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (pos <= 0 || pos > size)
    {
        printf("Inavlid Position\n");
        return head;
    }

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        size--;
        display(head);
        return head;
    }

    if (pos == size)
    {
        node *temp = head;
        node *p = NULL;
        while (temp->next != NULL)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = NULL;
        free(temp);
        size--;
        display(head);
        return head;
    }

    else
    {
        int i = 1;
        node *temp = head;
        node *prev;
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }

        prev->next = temp->next;
        free(temp);
        size--;
        display(head);
        return head;
    }
}

node *reverse(node *head)
{
    node *temp = head;
    node *curr = NULL;
    node *prev = NULL;

    while (temp != NULL)
    {
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }

    head = prev;
    display(head);
    return head;
}

node *searchByKey(node *head, int key)
{
    node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Key %d found in %d position\n", key, i);
            return head;
        }
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Key not found in the list\n");
        return head;
    }
}

int main()
{
    node *head = NULL;
    int ch, data, pos, key;
    while (1)
    {
        printf("\n1.InsertAtPos\n2.DeleteAtPos\n3.Display\n4.Reverse\n5.SearchByKey\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter position\n");
            scanf("%d", &pos);
            printf("Enter data\n");
            scanf("%d", &data);
            head = insertAtPos(head, pos, data);
            break;

        case 2:
            printf("Enter position\n");
            scanf("%d", &pos);
            head = deleteAtPosition(head, pos);
            break;

        case 3:
            head = display(head);
            break;

        case 4:
            head = reverse(head);
            break;

        case 5:
            printf("Enter the key to be searched\n");
            scanf("%d", &key);
            searchByKey(head, key);
            break;
        }
    }
}
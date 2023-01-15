#include <stdio.h>
#include <stdlib.h>
int c=0;
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Elements:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p = malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        free(p);
        return 0;
    }
}
struct Node *push(struct Node **top)
{
    if (isFull(*top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        c++;
        int ele;
        printf("Enter the element\n");
        scanf("%d", &ele);
        struct Node *n;
        n = (struct Node *)malloc(sizeof(struct Node));
        n->data = ele;
        n->next = *top;
        *top = n;
        return n;
    }
}
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        c--;
        struct Node *ptr = *top;
        *top = (*top)->next;
        int ele = ptr->data;
        free(ptr);
        return ele;
    }
}
int peek(struct Node *top, int pos)
{
    for (int i = 0; i < pos - 1 && top != NULL; i++)
    {
        top = top->next;
    }
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        printf("%d Pos don't exist\n", pos);
        return -1;
    }
}
int stackTop(struct Node *top)
{
    return top->data;
}
int stackBotm(struct Node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    return top->data;
}
void Free(struct Node *top)
{
    struct Node *ptr=top;
    while (ptr !=NULL)
    {
        top=top->next;
        free(ptr);
        ptr=top;
    }
}
int main()
{
    int ch;
    struct Node *top = NULL;
    while (1 < 2)
    {
        printf("Choices Available\n1.Push\t2.Pop\t3.Peek\t4.Stack Top\t5.Stack Bottom\t6.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&top);
            break;
        case 2:
            printf("Element:%d", pop(&top)); // Last IN first OUT
            break;
        case 3:
            for (int j = 1; j <= c; j++)
            {
                printf("Element at Pos %d is %d\n", j, peek(top, j));
            }
            break;
        case 4:
            printf("Top most element of stack is %d\n", stackTop(top));
            break;
        case 5:
            printf("Bottom most element of stack is %d\n", stackBotm(top));
            break;
        case 6:
            LinkedListTraversal(top);
            break;
        default:
            Free(top);
            exit(0);
            break;
        }
    }
    return 0;
}
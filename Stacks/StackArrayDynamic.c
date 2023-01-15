#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int * arr;
};

int top = -1;

void push(struct stack *stack, int key)
{
    if (top == stack->size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack->arr[top] = key;
    }
}

void pop(struct stack *stack)
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d element is popped\n", stack->arr[top]);
        top--;
    }
}

void peek(struct stack *stack)
{
    if (top == -1)
    {
        printf("Nothing at the top\n");
    }
    else
    {
        printf("%d is top most element of the stack\n", stack->arr[top]);
    }
}

void display(struct stack *stack)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        int i = top;
        do
        {
            printf("%d\n", stack->arr[i]);
            i--;
        } while (i>=0);
        
    }
}

int main(){
    struct stack * stack = malloc(sizeof(struct stack));
    printf("Enter the size of the stack: ");
    scanf("%d", &stack->size);
    stack->arr = (int *)malloc(stack->size*sizeof(int));
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    display(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    display(stack);
    peek(stack);
    return 0;
}

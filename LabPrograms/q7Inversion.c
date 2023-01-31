// TODO 1: For eval... within the stack structure take int * array and For conversion... char * array
// TODO 2: push pop function is must for both type.
// TODO 3: precedence function ^ > * / > + - > ()
// TODO 4: isOperator function return 1 if +-*/^ or return 0
// TODO 5: isParenthesis function return 1 if ()
// TODO 6: reverse the given expression and also interchange ( with ) and vice versa
// TODO 7: int operate(a, b, op) --> returns (a op b)
// TODO 8: int eval(int * arr) 
// TODO 9: Conversion Infi to Pofi
    // ! Scan all the symbols one by one from left to right in the given Infix Expression.
    // ! If the reading symbol is operand, then immediately append it to the Postfix Expression .
    // ! If the reading symbol is left parenthesis ‘( ‘, then Push it onto the Stack.
    // ! If the reading symbol is right parenthesis ‘)’, then Pop all the contents of the stack until the respective 
    // ! left parenthesis is popped and append each popped symbol to Postfix Expression
    // ! If the reading symbol is operator (+ , – , * , /), then Push it onto the Stack. However, first pop the operators 
    // ! which are already on the stack that have higher or equal precedence than the current operator and append them to the 
    // ! postfix  
    // ! If the input is over, pop all the remaining symbols from the stack and append them to the postfix .
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct Stack
{
    int size, top, *arr1;
    char *arr;
};
void push(struct Stack *ptr, char val)
{
    if (ptr->top == ptr->size - 1)
        printf("Stack Overflow!\n");
    else
        ptr->arr[++ptr->top] = val;
}
char pop(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
        return ptr->arr[ptr->top--];
}
int prec(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '(')
        return 1;
    else
        return 0;
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
int isParen(char ch)
{
    if (ch == '(' || ch == ')')
        return 1;
    else
        return 0;
}
char *conv(char *ptr)
{
    int i = 0, j = 0, k = 0;
    char temp[4];
    char *wn = malloc(strlen(ptr) * 4);
    while (ptr[i] != '\0')
    {
        if (isalpha(ptr[i]))
        {
            printf("Enter the val of %c: ", ptr[i]);
            scanf("%s", temp);
            while (temp[k] != '\0')
            {
                wn[j] = temp[k];
                k++;
                j++;
            }
            k = 0;
            i++;
        }
        else
        {
            wn[j] = ptr[i];
            i++;
            j++;
        }
        wn[j] = ' ';
        j++;
    }
    wn[--j] = '\0';
    return wn;
}
char *rev(char *infix)
{
    char x;
    for (int i = 0; i < strlen(infix) / 2; i++)
    {
        x = infix[i];
        infix[i] = infix[strlen(infix) - 1 - i];
        infix[strlen(infix) - i - 1] = x;
    }
    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            continue;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            continue;
        }
    }
    return infix;
}
int operate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '^':
        return pow(a, b);
        break;
    default:
        break;
    }
}
int Eval(char *ptr)
{
    int r = 0, x, y;
    int i, j;
    if (isalnum(ptr[0]))
        r = 1;
    ptr = conv(ptr);
    struct Stack *stk = malloc(sizeof(struct Stack));
    stk->top = -1;
    stk->size = strlen(ptr);
    stk->arr1 = (int *)malloc(sizeof(stk->size));
    if (r)
        i = 0;
    else
        i = strlen(ptr) - 1;
    while (r == 1 ? ptr[i] != '\0' : i != -1)
    {
        if (isspace(ptr[i]))
        {
            r == 1 ? i++ : i--;
            continue;
        }
        if (isdigit(ptr[i]))
        {
            int val = 0;
            if (r)
            {
                while (ptr[i] != ' ')
                {
                    int temp = (int)(ptr[i] - '0');
                    val = 10 * val + temp;
                    i++;
                }
            }
            else
            {
                j = i;
                while (i < strlen(ptr) && isdigit(ptr[i]))
                    i--;
                i++;
                for (int k = i; k <= j; k++)
                {
                    val = val * 10 + (int)(ptr[k] - '0');
                }
            }
            stk->arr1[++stk->top] = val;
            r == 1 ? i++ : i--;
        }
        else
        {
            x = stk->arr1[stk->top--];
            y = stk->arr1[stk->top--];
            if (r)
                stk->arr1[++stk->top] = operate(y, x, ptr[i]);
            else
                stk->arr1[++stk->top] = operate(x, y, ptr[i]);
            r == 1 ? i++ : i--;
        }
    }
    return stk->arr1[stk->top--];
}

char *ItPP(char *infix)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isspace(infix[i]))
        {
            i++;
            continue;
        }
        else if (isOperator(infix[i]))
        {
            if (prec(infix[i]) > prec(sp->arr[sp->top]))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
        else if (isParen(infix[i]))
        {
            if (infix[i] == '(')
            {
                push(sp, infix[i]);
                i++;
            }
            else if (infix[i] == ')')
            {
                while (sp->arr[sp->top] != '(')
                {
                    postfix[j] = pop(sp);
                    j++;
                }
                pop(sp);
                i++;
            }
        }
        else
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
    }
    while (sp->top != -1)
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    int ch;
    char expn[100];
    printf("Enter the expression\n");
    scanf("%[^\n]", expn);
    do
    {
        printf("Enter Your Choice\n1.Postfix\t2.Prefix\t3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("PostFix Expn: %s\n", ItPP(expn));
            printf("Evaluated: %d\n", Eval(ItPP(expn)));
            break;
        case 2:
            printf("PreFix Expn: %s\n", rev(ItPP(rev(expn))));
            rev(expn);
            printf("Evaluated: %d\n", Eval(rev(ItPP(rev(expn)))));
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch != 3);
    return 0;
}
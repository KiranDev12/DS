#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 100

typedef struct {
    char data[MAX_EXPR_LEN];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char ch) {
    if (s->top == MAX_EXPR_LEN - 1) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infix_to_postfix(char infix_expr[MAX_EXPR_LEN], char postfix_expr[MAX_EXPR_LEN]) {
    Stack s;
    init(&s);
    int i = 0, j = 0;
    while (infix_expr[i] != '\0') {
        char ch = infix_expr[i];
        if (isdigit(ch) || isalpha(ch)) {
            postfix_expr[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (s.data[s.top] != '(') {
                postfix_expr[j++] = pop(&s);
            }
            pop(&s);  // pop the '('
        } else if (is_operator(ch)) {
            while (s.top != -1 && s.data[s.top] != '(' &&
                   precedence(ch) <= precedence(s.data[s.top])) {
                postfix_expr[j++] = pop(&s);
            }
            push(&s, ch);
        } else {
            printf("Error: Invalid character %c in infix expression\n", ch);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    while (s.top != -1) {
        postfix_expr[j++] = pop(&s);
    }
    postfix_expr[j] = '\0';
}

int main() {
    char infix_expr[MAX_EXPR_LEN], postfix_expr[MAX_EXPR_LEN];
    printf("Enter infix expression: ");
    scanf("%s", infix_expr);
    infix_to_postfix(infix_expr, postfix_expr);
    printf("Postfix expression: %s\n", postfix_expr);
    return 0;
}

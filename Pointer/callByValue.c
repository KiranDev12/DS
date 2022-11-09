#include<stdio.h>

int sum(int a, int b);

int main(){
    int a=10, b=5; // these original values arent given to the function
    printf("The values of a and b are %d and %d.\n", a, b);
    printf("The sum is %d\n", sum(a, b));
    printf("The values of a and b after function call are %d and %d.\n", a, b);
    return 0;
}

int sum(int a, int b){ // copies of a and b are used as the input arguments to this
    int c;
    c = a + b;
    a = 1020;
    b = 1923;
    return c;
}

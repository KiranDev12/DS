#include<stdio.h>

void swap(int *a, int *b);
void wrong_swap(int *a, int *b);

int main(){
    int a=1, b=2;
    printf("Value of x and y before swap is %d an %d\n", a, b);
    //wrong_swap(a, b); // will not work due to call by value
    swap(&a, &b); // works due to call by reference
    printf("Value of x and y after swap is %d and %d\n", a, b);

    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
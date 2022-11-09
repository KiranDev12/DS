#include<stdio.h>

int main(){
    int i = 10;
    int *j = &i;
    printf("The value of i is %d\n", i);
    printf("The value of i is %d\n", *j);
    printf("The address of i is %p\n", j);
    printf("The address of i is %p\n", &i);
    printf("The address of j is %p\n", &j);
    return 0;
}
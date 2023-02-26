//? Implement circular single linked list to perform the following operations
//? i) Insert by order ii ) Delete by position iii) Search for an item by key
//? Display the list contents after each operation

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

int size;

struct node * insByOrder(){
    int size;
    printf("Enter the number of elements: \n");
    scanf("%d",&size);  
}
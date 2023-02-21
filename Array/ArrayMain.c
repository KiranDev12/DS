// ? Develop a menu driven program to implement the following operations on array 
// ? storage representation with static and dynamic memory allocation.
// ? i)Insert by position ii) Delete by position iii)Insert by key iv) Delete by key v) 
// ? Insert by order vi) Search by key vii) Search by position viii) Reverse the 
// ? contents.


#include<stdio.h>
#include<stdlib.h>

int arrStatic[50]; // ! ask for static size and store
int *arrDynamic; // ! initialize it with the size
int staSize, dynSize;

void createStatic(int staSize){
    if (staSize>50)
    {
        printf("Size must be within 50\n");
    }
    else{
        printf("Enter the elements of the static array: \n");
        for (int i = 0; i < staSize; i++)
        {
            scanf("%d", &arrStatic[i]);
        }  
    }
}

void printStatic(int staSize){
    printf("Array elements are: \n");
    for (int i = 0; i < staSize; i++)
    {
        printf("%d\n", arrStatic[i]);
    }
    printf("\n");

}

void createDynamic(int dynSize){
    arrDynamic = (int *)malloc(dynSize*sizeof(int));
    printf("Enter the elements of the static array: \n");
    for (int i = 0; i < dynSize; i++)
    {
        scanf("%d", arrDynamic + i);
    }  
}

void printDynamic(int dynSize){
    printf("Array elements are: \n");
    for (int i = 0; i < dynSize; i++)
    {
        printf("%d\n", *(arrDynamic+i));
    }
    printf("\n");
}

void insertPosStatic(int val, int pos){
    if (pos>staSize+1)
    {
        printf("Enter a valid position!");
    }
    else{
        staSize++;
        for (int i = staSize - 1; i >= pos; i--)
        {
            arrStatic[i] = arrStatic[i-1];
        }
        arrStatic[pos-1] = val;
    }
}
void insertPosDynamic(int val, int pos){
    if (pos>dynSize)
    {
        printf("Enter a valid position!");
    }
    else{
        dynSize++;
        for (int i = dynSize - 1; i >= pos; i--)
        {
            * (arrDynamic + i) = *(arrDynamic + i - 1);
        }
        *(arrDynamic + pos - 1) = val;
    }
}

void main(){
    printf("Enter the size of the static array: ");
    scanf("%d", &staSize);
    createStatic(staSize);
    printf("Enter the size of the dynamic array: ");
    scanf("%d", &dynSize);
    createDynamic(dynSize);

    insertPosStatic(99, 5);
    insertPosDynamic(100, 2);
    printStatic(staSize);
    printDynamic(dynSize);
}
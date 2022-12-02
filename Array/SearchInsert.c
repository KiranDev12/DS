
#include<stdio.h>
#include<stdlib.h>

void read(int * arr, int n){
    printf("Enter elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &*(arr+i));
    }
}

void write(int * arr, int n){
    printf("Elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(arr+i));
    }
}

int check(int * arr, int n){
    for (int i = 0; i < n; i++)
    {
        if (*(arr+i)<=0)
        {
            return 0;
        }
    }
    return 1;
    
}

void searchInsert(int * arr, int n, int key){
    for (int i = 0; i < n; i++)
    {
        if(*(arr+i)==key){
            printf("The number already exists\n");
            exit(0);
        }
    }

    //Very imp to keep hold of the last element of the array

    n++;
    arr = (int*)realloc(arr,n*sizeof(int));

    //RUN THE FOR BACKWARD ALWAYS AS WE HAVE TO first allocate last element to empty space

    // int size = sizeof(arr)/sizeof(int);
    //Also a good way to keep track of size in the write function instead of taking in values for n
    
    for (int i = n-1; i>=0; i--)
    {
        *(arr+i)=*(arr+i-1);
    }
    *(arr+0) = key;
    
    write(arr,n);
}

int main(){
    int * array;
    int n;
    scanf("%d", &n);
    array = (int *)calloc(n, sizeof(int));

    read(array, n);

    write(array, n);

    if (check(array, n)==0)
    {
        printf("Your array contains atleast one negative number\n");
    }
    else{
        printf("Your array contains all positive numbers\n");
    }
    void (*ptr)() = searchInsert;
    (*ptr)(array, n, 5);
    return 0;
}


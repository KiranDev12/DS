#include<stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    
}

int indexInsertion(int arr[], int size, int element, int index){
    if(size>=100){
        return -1;
    }
    for(int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main(){
    int arr[100] = {1, 8, 12, 32};
    int size = 4, element = 44, index = 3;
    indexInsertion(arr, size, element, index);
    display(arr, size+1);
    return 0;
}
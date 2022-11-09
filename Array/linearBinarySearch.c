#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    int searchIndex = 0;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            searchIndex = i;
        }
    }
    if(searchIndex == 0){
        return -1;
    }
    else{
        return searchIndex;
    }
}

int binarySearch(int arr[], int size, int element){
    int searchIndex = 0;
    int low = 0, high = size, mid = 0;
    if (arr[low]==element){
        return 0;
    }
    else if (arr[high]==element){
        return size;
    }
    else{
        mid = (low+high)/2;
    }
}

int main(){
    int arr[] = {11, 16, 17, 18, 19, 3, 7, 9, 14};
    int size = sizeof(arr)/sizeof(int);
    int element = 14;
    int searchIndex = linearSearch(arr, size, element);
    printf("%d\n", searchIndex);
    return 0;
}
#include<stdio.h>

void func1(int array[], int length){

    int sum = 0; // k1
    int product = 1;

    for(int i = 0; i < length; i++){
        sum += array[i]; // k2 n
    }

    for(int i = 0; i < length; i++){
        product *= array[i]; // k3 n
    }

    printf("%d\n%d\n", sum, product);
}

int main(){
    int arr[] = {3,5,10};
    func1(arr, 3);
    return 0;
}

// time complexity is O(length)
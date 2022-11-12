// A C program to insert an element in an array at a specific position

#include<stdio.h>
#include<stdlib.h>

void printArray(int* arr, int n)
{
	int i;

	for(i=0; i<n; i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
}

void insertArray(int* arr, int n, int key, int pos){
	int i;
	n++;
	for(i=n-1; i>=pos; i--){
		*(arr+i) = *(arr+i-1);
	}	
	*(arr+pos-1) = key;
}

void deleteArray(int* arr, int n, int pos){
	int i;
	if (pos>n)
	{
		printf("Enter a number within the range\n");
		exit(0);
	}
	for(i=pos-1; i<n-1; i++){
		*(arr+i) = *(arr+i+1);
	}
	n--;
}

int main(){

	int i, key, pos, n=10;
	int* arr = (int *)malloc(n*(sizeof(int)));

	for(i=0; i<n; i++){
		*(arr+i)=i+1;
	}

	printf("Original Array: \n");
	printArray(arr, n);
	
	printf("What element and at what position do you want to insert? \n");
	scanf("%d%d", &key, &pos);
	insertArray(arr, n, key, pos);
	n++;
	printf("Array after insertion: \n");
	printArray(arr, n);
	
	printf("What position you want to delete? \n");
	scanf("%d", &pos);
	deleteArray(arr, n, pos);
	n--;
	printArray(arr, n);
}
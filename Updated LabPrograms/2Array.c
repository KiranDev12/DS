//? Develop a menu driven program to implement the following operations on an array of
//? integers with dynamic memory allocation.
//? i) Insert by position ii) Delete by position iii) Insert by key iv) Delete by key v) Insert by order
//? vi) Search by key vii) Search by position viii) Reverse the contents.

#include <stdio.h>
#include <stdlib.h>

void insByPos(int *arr, int pos, int key)
{
    
}
int main()
{
    int n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements one by one: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    while (1)
    {
        int ch, pos, key;
        printf("\nChoices Available: \n");
        printf("i) Insert by position \nii) Delete by position \niii) Insert by key \niv) Delete by key \nv) Insert by order \nvi) Search by key \nvii) Search by position \nviii) Reverse the contents.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter position and key to be inserted: ");
            scanf("%d %d", &pos, &key);
            insByPos(arr, pos, key);
            break;

        default:
            break;
        }
    }
}
/*
? Develop a menu driven program to implement the following operations on array 
? storage representation with static and dynamic memory allocation.
? i)Insert by position ii) Delete by position iii)Insert by key iv) Delete by key v) 
? Insert by order vi) Search by key vii) Search by position viii) Reverse the 
? contents.
*/

#include<stdio.h>
#include<stdlib.h>

int size;

void dispDynamic(int * ptr){
    printf("\nThe elements of the array are: ");
    int i = 0;
    while (i!= size)
    {
        printf("%d\t", *(ptr+i));
        i++;
    }
    printf("\n");
}

void dispStatic(int ptr[]){
    printf("\nThe elements of the array are: ");
    int i = 0;
    while (i!= size)
    {
        printf("%d\t", ptr[i]);
        i++;
    }
    printf("\n");
}

void insertPosDynamic(int * ptr){
    int pos, ele;
    ptr = realloc(ptr, (size+1)*sizeof(int)); 
    printf("Enter the Position and Element to be inserted\n");
	scanf("%d%d",&pos,&ele);
    if(pos>size || pos<0){
        printf("Invalid pos\n");
        return;
    }
    for (int i = size - 1; i >= (pos - 1); i++)
    {
        *(ptr + i + 1) = *(ptr + i);
    }
    *(ptr + pos - 1) = ele;
    size++;
    dispDynamic(ptr);
}

int main(){
    int choice;
    printf("Which memory allocation you want?(1.Dynamic/2.Static)\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        int ch;
        printf("Enter the size of the array: \n");
        scanf("%d", &size);
        int* arrDynamic = (int *)malloc(sizeof(int));
        printf("Enter the elements of the array: \n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", arrDynamic+i);
        }
        dispDynamic(arrDynamic);

        while (1<2)
        {
            

            printf("Choices available for Dynamic are: \n");
            printf("\n1.Insert(Pos)\n2.Delete(Pos)\n3.Insert(key)\n4.Delete(key)\n5.Insert(order)\n6.Search(key)\n7.Search(Pos)\n8.Reverse\n");
            scanf("%d", &ch);
            switch (ch)
            {
                case 1:
                    insertPosDynamic(arrDynamic);
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:

                    break;
                default:
                    break;
            }
        }    
    }
    else if(choice == 2)
    {  
        int ch;
        printf("Enter the size of the array: \n");
        scanf("%d", &size);  
        int arrStatic[size];       
        printf("Enter the elements of the array: \n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arrStatic[i]);
        }  
        dispStatic(arrStatic);
        while (1<2)
        {
 

            printf("Choices available for Static are: \n");
            printf("\n1.Insert(Pos)\n2.Delete(Pos)\n3.Insert(key)\n4.Delete(key)\n5.Insert(order)\n6.Search(key)\n7.Search(Pos)\n8.Reverse\n");
            scanf("%d", &ch);
            switch (ch)
            {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:

                    break;
                default:
                    break;
            }
        }  
    }
    else{
        printf("Invalid Choice\n");
    }
    return 0;
}
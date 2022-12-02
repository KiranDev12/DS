#include<stdio.h>
#include<stdlib.h>
int n;

void disp(int *a)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\n",*(a+i));
	}
}

void insert_Pos(int *a)
{
	int pos,ele;
	printf("Enter the Pos and Element to be inserted\n");
	scanf("%d%d",&pos,&ele);
	for(int i=n-1;i>=(pos-1);i--)
	{
		*(a+i+1)=*(a+i);
	}
	*(a+pos-1)=ele;
	n++;
	printf("Array after Updation\n");
	disp(a);
}

void delete_Pos(int *a)
{
	int Pos;
	printf("Enter the Pos to be deleted\n");
	scanf("%d",&Pos);
	for(int i=Pos-1;i<n;i++)
	{
		*(a+i)=*(a+i+1);
	}
	n--;
	printf("Array after Updation\n");
	disp(a);
}

void insert_key(int *a)
{
	int key,ele,i;
	printf("Enter the Key\n");
	scanf("%d",&key);
	printf("Enter the Element\n");
	scanf("%d",&ele);
	for(i=0;i<n;i++)
	{
		if(*(a+i)==key)
		break;
	}
	for(int j=n-1;j>=i;j--)
	{
		*(a+j+1)=*(a+j);
	}
	*(a+i)=ele;
	n++;
	printf("Array after Updation\n");
	disp(a);
}

void delete_key(int *a)
{
	int key,i;
	printf("Enter the key to be deleted\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(*(a+i)==key)
		break;
	}
	for(int j=i;j<n;j++)
	{
		*(a+j)=*(a+j+1);
	}
	n--;
	printf("Array after Updation\n");
	disp(a);
}

void insert_order(int *a)
{
	int ele,i; 
	printf("Enter the element to be inserted in ordered array\n");
	scanf("%d",&ele);
	for(i=0;i<n;i++)
	{
		if(*(a+i)>=ele)
		break;
	}
	for(int j=n-1;j>=i;j--)
	{
		*(a+j+1)=*(a+j);
	}
	*(a+i)=ele;
	n++;
	printf("Array after Updation\n");
	disp(a);
}

void search_key(int *a)
{
	int key,low=0,high=n,mid;
	printf("Enter the element to be searched\n");
	scanf("%d",&key);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(*(a+mid)==key)
		{
			break;
		}
		else if(*(a+mid)<key)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	if(*(a+mid)==key)
	{
		printf("Element found at Pos %d\n",(mid+1));
	}
	else
	printf("Not found\n");
}

void search_Pos(int *a)
{
	int key,found=0,i;
	printf("Enter the element to be searched\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(*(a+i)==key)
		{
			found++;
			break;
		}
	}
	if(found!=0)
	{
		printf("Element found at %d",i+1);
	}
	else
	{
		printf("Not found\n");
	}
}

void Reverse(int *a)
{
	int temp;
	for(int i=0;i<n/2;i++)
	{
		temp=*(a+i);
		*(a+i)=*(a+n-1-i);
		*(a+n-1-i)=temp;
	}
	printf("Array after Updation\n");
	disp(a);
}


int main()
{
	int choice;
	int arr[100];
	int *a=&arr[0];
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter The array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Entered Array elements are\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	while(1<2)
	{
		printf("Choice Available\n1.Insert(Pos)\n2.Delete(Pos)\n3.Insert(key)\n4.Delete(key)\n5.Insert(order)\n6.Search(key)\n7.Search(Pos)\n8.Reverse\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_Pos(a);
				break;
			case 2:delete_Pos(a);
				break;
			case 3:insert_key(a);
				break;
			case 4:delete_key(a);
				break;
			case 5:insert_order(a);
				break;
			case 6:search_key(a);
				break;
			case 7:search_Pos(a);
				break;
			case 8:Reverse(a);
				break;
			default: exit(0);
		}
	}
return 0;
}
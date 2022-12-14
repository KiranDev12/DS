#include <stdio.h>
#include <stdlib.h>
int size;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *read(struct Node *head)
{
    struct Node *newnode, *temp;
    printf("Enter the data of nodes\n");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    for (int i = 0; i < size - 1; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

void disp(struct Node *head)
{
    if(head==NULL){
	printf("Empty List\n");
	}
	else{
    		struct Node *temp = head;
    		while (temp != NULL)
    		{
        	printf("Element : %d\n", temp->data);
        	temp = temp->next;
    		}
	}
}

struct Node *Insert_Front(struct Node *head)
{
    int data;
    size++;
    printf("Enter the Data\n");
    scanf("%d", &data);
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *Insert_Rear(struct Node *head)
{
    int data;
    size++;
    printf("Enter the Data\n");
    scanf("%d", &data);
    struct Node *ptr;
    struct Node *p = head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct Node *Insert_Pos(struct Node *head)
{
    int data, Pos;
    size++;
    printf("Enter the Data and Pos\n");
    scanf("%d%d", &data, &Pos);
    if(Pos==1)
    {
	head=Insert_Front(head);
    }
    else
    {
    	struct Node *ptr;
    	struct Node *p = head;
    	ptr = (struct Node *)malloc(sizeof(struct Node));
    	for (int i = 0; i < Pos - 2; i++)
    	{
        	p = p->next;
    	}
    	ptr->data = data;
    	ptr->next = p->next;
    	p->next = ptr;
    }
    return head;
}

struct Node *Delete_Front(struct Node *head)
{
    if(head == NULL)
    {
	printf("Empty List\n");
    }
    else
    {
	size--;
    	struct Node *ptr = head;
    	head = head->next;
    	free(ptr);
    }
    return head;
}

struct Node *Delete_Rear(struct Node *head)
{
    if(head==NULL)
    {
	printf("Empty List\n");
    }
    else
    {
	size--;
    	struct Node *p = head;
    	struct Node *q = head->next;
    	while (q->next != NULL)
    	{
        	p = p->next;
        	q = q->next;
    	}
    	p->next = NULL;
    	free(q);
    }
    return head;
}

struct Node *Delete_Pos(struct Node *head)
{
    int Pos;
    if(head==NULL)
    {
	printf("Empty List\n");
    }
    else
    {
    	printf("Enter the Pos to be deleted\n");
    	scanf("%d", &Pos);
    	if(Pos==1)
    	{
		head=Delete_Front(head);
    	}
	else if(Pos == (size))
	{
		head=Delete_Rear(head);
	}
    	else
    	{
    		struct Node *p = head;
    		struct Node *q = head->next;
    		for (int i = 0; i < Pos - 2; i++)
    		{
        		p = p->next;
        		q = q->next;
    		}
    		p->next = q->next;
    		free(q);
		size--;
    	}
    }
    return head;
}

struct Node *Delete_key(struct Node *head)
{
    int val;
    if(head==NULL)
    {
	printf("Empty List");
    }
    else
    {
    	printf("Enter the Value(key) to be deleted\n");
    	scanf("%d", &val);
    	struct Node *p = head;
    	struct Node *q = head->next;
    	while (q->data != val && q->next != NULL)
    	{
        	p = p->next;
        	q = q->next;
    	}
    	if (q->data == val)
    	{
		size--;
        	p->next = q->next;
        	free(q);
    	}
    }
    return head;
}

void Search(struct Node *head)
{
    int ele, index = 0;
    printf("Enter the Element to be searched\n");
    scanf("%d", &ele);
    struct Node *ptr = head;
    while (ptr->data != ele && ptr->next != NULL)
    {
        ptr = ptr->next;
        index++;
    }
    if (ptr->data == ele)
    {
        printf("Element found at Position %d\n", index + 1);
    }
    else
    {
        printf("Element Not Found\n");
    }
}

struct Node *Sorting(struct Node *head)
{
    int a;
    struct Node *q;
    struct Node *p;
    for (q = head; q != NULL; q = q->next)
    {
        for (p = q->next; p != NULL; p = p->next)
        {
            if (p->data < q->data)
            {
                a = q->data;
                q->data = p->data;
                p->data = a;
            }
        }
    }
    return head;
}

struct Node *Reverse(struct Node *head)
{
    struct Node *p, *q;
    if (head != NULL)
    {
        q = head;
        p = head->next;
        head = head->next;
        q->next = NULL; // Make first node as last node
        while (head != NULL)
        {
            head = head->next;
            p->next = q;
            q = p;
            p = head;
        }
        head = q; // Make last node as head
    }
    return head;
}

struct Node *Copy(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct Node* newNode=malloc(sizeof(struct Node));
        newNode->data = head->data;
        newNode->next = Copy(head->next);
        return newNode;
    }
}

void Free(struct Node *ptr)
{
	if(ptr != NULL)
	{
		struct Node *p=ptr->next;
		ptr->next=NULL;
		free(ptr);
		Free(p);
	}
}

int main()
{
    int ch;
    struct Node *head;
    printf("Enter No of Nodes Required\n");
    scanf("%d", &size);
    head = (struct Node *)malloc(sizeof(struct Node));
    while (1 < 2)
    {
        puts("Choices Available\n1.Read\n2.Display\n3.Insert(Front)\n4.Insert(Rear)\n5.Insert(Pos)\n6.Delete(Front)\n7.Delete(Rear)\n8.Delete(Pos)\n9.Delete(key)");
        puts("10.Search(key)\n11.Create an ordered list\n12.Reverse\n13.Create a copy of the list\n14.Free");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            read(head);
            break;
        case 2:
            disp(head);
            break;
        case 3:
            head = Insert_Front(head);
            break;
        case 4:
            head=Insert_Rear(head);
            break;
        case 5:
            head=Insert_Pos(head);
            break;
        case 6:
            head=Delete_Front(head);
            break;
        case 7:
            head=Delete_Rear(head);
            break;
        case 8:
            head=Delete_Pos(head);
            break;
        case 9:
            head=Delete_key(head);
            break;
        case 10:
            Search(head);
            break;
        case 11:
            head=Sorting(head);
            break;
        case 12:
            head=Reverse(head);
            break;
        case 13:
            disp(Copy(head));
            break;
	case 14:
	    Free(head);
	    head=NULL;
	    break;
        default:
		printf("Exiting\n");
               	exit(0);
               	break;
	}
    }
    return 0;
}
/*
? Define a structure called Time containing 3 integer members (hour, minute, 
? second). Develop a menu driven program to perform the following by writing 
? separate function for each operation.
? a) To read time b) To display time c) To Update time d) Add two times by 
? writing Add (T1, T2) which returns the new Time. 
? Update function increments the time by one second and returns the new time (if 
? the increment results in 60 seconds, then the second member is set to zero and 
? minute member is incremented by one. If the result is 60 minutes, the minute 
? member is set to zero and the hour member is incremented by one. Finally, when 
? the hour becomes 24, Time should be reset to zero)
! Note: Illustrate the use of pointer to a structure variable and passing and returning 
! of structure type to and from the function (both by value and reference).
*/


#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>
typedef struct Time
{
	int hour;
	int minute;
	int second;
}time;

time *p;

time *read(time *p)
{
	p=(time *)(calloc(1, sizeof(time)));
	printf("\nEnter the 'hours':\t");
	scanf("%d", &(p->hour));
	printf("\nEnter the 'mintute':\t");
	scanf("%d", &(p->minute));
	printf("\nEnter the 'second':\t");
	scanf("%d", &(p->second));
	if( (p->hour)>23 || (p->hour)<0 || (p->minute)>59 || (p->minute)<0 || (p->second)>59 || (p->second)<0 )
	{
		printf("\nEnter vaid time\n");
	}
	else
	{
		return p;
	}
}
void display(time *p)
{
	printf("\nThe time is %d:%d:%d\n", (p->hour), (p->minute), (p->second));
}
time *update(time *p)
{
	p->second +=1;
	if((p->second)>59)
	{
		p->second=0;
		p->minute+=1;
	}
	if(p->minute>59)
	{
		p->minute=0;
		p->hour+=1;
	}
	if(p->hour>23)
	{
		p->hour=0;
	}
	return p;
}
void timeAdd(time one, time two)
{
	printf("\nEnter the time you want to add.....\n");
	printf("\nTime1\n");
	printf("Hour:\t");
	scanf("%d", &(one.hour));
	printf("Minute:\t");
	scanf("%d", &(one.minute));
	printf("Second:\t");
	scanf("%d", &(one.second));
	printf("\nTime2\n");
	printf("Hour:\t");
	scanf("%d", &(two.hour));
	printf("Minute:\t");
	scanf("%d", &(two.minute));
	printf("Second:\t");
	scanf("%d", &(two.second));
	time add;
	int day=0;
	add.second=one.second+two.second;
	add.minute=one.minute+two.minute;
	add.hour=one.hour+two.hour;
	if(add.second>59)
	{
		//! Remember this combination 
		add.minute+=((add.second)/60);
		add.second=(add.second%60);
	}
	if(add.minute>59)
	{
		add.hour+=((add.minute)/60);
		add.minute=(add.minute%60);
	}
	if(add.hour>23)
	{
		day+=add.hour/24;
		add.hour = add.hour%24;
	}
	
	
	printf("\nSum of the two times is\n");
	printf("\nDays:Hours:Minute:Seconds=%d:%d:%d:%d\n", day, add.hour, add.minute, add.second);
}
void main()
{
	int choice;
	time *q, T1, T2;
	while(1)
	{
		printf("Enter\n1.To enter time\n2.To display time\n3.To update time\n4.To add time\n5.To stop\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				q=read(q);
				break;
			case 2:
				display(q);
				break;
			case 3:
				q=update(q);
				printf("\nAfter the updation.....\n");
				display(q);
				break;
			case 4:
				timeAdd(T1, T2);
				break;
			case 5:
				exit(0);
			default :
				printf("\nInvalid choice....\n");
		}
	}
}
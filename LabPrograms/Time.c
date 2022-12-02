#include <stdio.h>
#include <stdlib.h>

struct TIME
{
    int hr, min, sec;
};
typedef struct TIME time;

void read(time *T)
{
    printf("Enter the time in hrs:mins:sec\n");
    scanf("%d%d%d", &T->hr, &T->min, &T->sec);
}

void display(time *T)
{
    printf("Hrs\tMins\tSec\n");
    printf("%d\t%d\t%d\n", T->hr, T->min, T->sec);
}

void update(time *T)
{
    T->sec++;
    if (T->sec >= 60)
    {
        T->min = T->min + (T->sec) / 60;
        T->sec = T->sec % 60;
        if (T->min >= 60)
        {
            T->hr = T->hr + T->min / 60;
            T->min = T->min % 60;
            if (T->hr >= 24)
            {
                printf("time before Reseting:\n");
                display(T);
                printf("Reseting T");
                T->hr = T->hr - 24;
            }
        }
    }
}

void add(time *T1, time *T2, time *T3)
{
    T3->hr = T1->hr + T2->hr;
    T3->min = T1->min + T2->min;
    T3->sec = T1->sec + T2->sec;

    if (T3->sec >= 60)
    {
        T3->min = T3->min + (T3->sec) / 60;
        T3->sec = (T3->sec) % 60;
    }
    if (T3->min >= 60)
    {
        T3->hr = T3->hr + T3->min / 60;
        T3->min = T3->min % 60;
    }
    if (T3->hr >= 24)
    {
        printf("time before Reseting:\n");
        display(T3);
        T3->hr = T3->hr - 24;
    }
}
void main()
{
    int choice, ch;
    time T1, T2, T3;

    while (1 < 2)
    {
        printf("Choices Available:\n1.Read\n2.Display\n3.Update\n4.Add\n5.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Reading time 1\n");
            read(&T1);
            printf("Reading time 2\n");
            read(&T2);
            break;

        case 2:
            printf("Enter time to be Displayed\n1.time 1\n2.time 2\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                display(&T1);
                break;
            case 2:
                display(&T2);
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("Enter time to be Updated\n1.time 1\n2.time 2\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                update(&T1);
                break;
            case 2:
                update(&T2);
                break;
            default:
                break;
            }
            break;

        case 4:
            printf("Adding two times\n");
            printf("T1\n");
            display(&T1);
            printf("T2\n");
            display(&T2);
            add(&T1, &T2, &T3);
            printf("Added time\n");
            display(&T3);
            break;

        default:
            printf("Invalid choice...\n");
            exit(0);
        }
    }
}

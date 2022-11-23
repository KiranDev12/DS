#include <stdio.h>
#include <stdlib.h>
int n = 0;

typedef struct student
{
    char name[100];
    int reg_no;
    int m1, m2, m3;
    int avg;
} s;

void read(s *std)
{
    printf("Enter the name of the student : ");
    scanf("%s", &std[n].name);
    printf("Enter the register number of the student : ");
    scanf("%d", &std[n].reg_no);
    printf("Enter the marks obatained in three subjects : ");
    scanf("%d %d %d", &std[n].m1, &std[n].m2, &std[n].m3);
    std[n].avg = 0;
    n++;
}

void display(s *std)
{
    printf("Name\tRegister Number\tM1\tM2\tM3\tAverage\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t\t%d\t%d\t%d\t%d\n", std[i].name, std[i].reg_no, std[i].m1, std[i].m2, std[i].m3, std[i].avg);
    }
}

s calcAvg(s *std)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        if (std[i].m1 < std[i].m2)
        {
            if (std[i].m1 < std[i].m3)
                min = std[i].m1;
            else
                min = std[i].m3;
        }
        else if (std[i].m2 < std[i].m1)
        {
            if (std[i].m2 < std[i].m3)
                min = std[i].m2;
            else
                min = std[i].m3;
        }
        else
        {
            if (std[i].m3 < std[i].m1)
            {
                min = std[i].m3;
            }
            else
                min = std[i].m1;
        }
        int total = std[i].m1 + std[i].m2 + std[i].m3;
        std[i].avg = (total - min) / 2.0;
    }
}

int main()
{
    int ch;
    s *stdz = NULL;
    while (1)
    {
        printf("1.Read\t2.Display\t3.Calculate Average\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            stdz = (s *)realloc(stdz, (n + 1) * sizeof(s));
            read(stdz);
            break;

        case 2:
            display(stdz);
            break;

        case 3:
            calcAvg(stdz);
            break;
        }
    }
    return 0;
}
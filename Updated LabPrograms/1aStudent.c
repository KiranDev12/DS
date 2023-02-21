
//? 1. a) Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and
//? average_ marks.
//? Develop a menu driven program to perform the following by writing separate function for each
//? operation: a) read information of N students b) display student’s information c) to calculate the
//? average of best two test marks of each student.

//! Note: Allocate memory dynamically and illustrate the use of pointer to an array of structure.

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int reg_no;
    int marks[3];
};

// for each student, the above structure repeats and is dealt as an array in main fn

void read(struct Student *student, int i)
{
    printf("Enter the details of %d student: \n", i + 1);
    printf("Name: ");
    scanf("%s", student->name);
    printf("Reg No.: ");
    scanf("%d", &student->reg_no);
    for (int j = 0; j < 3; j++)
    {
        printf("Subject-%d: ", j + 1);
        scanf("%d", &student->marks[j]);
    }
}

void display(struct Student *student, int i)
{
    printf("Details of %d student: \n", i + 1);
    printf("Name: ");
    printf("%s\n", (student->name));
    printf("Reg No.: ");
    printf("%d\n", (student->reg_no));
    for (int j = 0; j < 3; j++)
    {
        printf("Subject-%d: ", j + 1);
        printf("%d\n", (student->marks[j]));
    }
    printf("\n");
}

void average(struct Student *student, int i)
{
    int min, total = 0;

    for (int j = 0; j < 3; j++)
    {
        total += student->marks[j];
    }
    if (student->marks[0] <= student->marks[1] && student->marks[0] <= student->marks[2])
    {
        min = student->marks[0];
    }
    if (student->marks[1] <= student->marks[0] && student->marks[1] <= student->marks[2])
    {
        min = student->marks[1];
    }
    if (student->marks[2] <= student->marks[0] && student->marks[2] <= student->marks[1])
    {
        min = student->marks[2];
    }

    float average = (total - min) / 2.0;
    printf("Average of best of two of %d student is: %f\n", i + 1, average);
}

int main()
{
    int n;
    printf("Enter the number of students in the class  ");
    scanf("%d", &n);

    struct Student *class = (struct Student *)malloc(n * sizeof(struct Student));

    int ch;
    while (1)
    {
        printf("Choices Available: \n");
        printf("1.Read \n2.Display \n3.Average Marks\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                read(class + i, i);
            }
            printf("\n");
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                display(class + i, i);
            }
            printf("\n");
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                average(class + i, i);
            }
            printf("\n");
            break;
        default:
            exit(0);
        }
    }
}
#include <stdio.h>

struct student
{
   char name[20];
   int roll;
   int maths;
   int physics;
   int chemistry;
};

int main()
{
   int i = 1;
   struct student arr[3];

   for (i = 0; i < 3; i++)
   {
      gets(arr[i].name);
      scanf("%d", &arr[i].roll);
      scanf("%d", &arr[i].maths);
      scanf("%d", &arr[i].physics);
      scanf("%d", &arr[i].chemistry);
   }

   for (i = 0; i < 3; i++)
   {
      printf("%s\n", arr[i].name[20]);
      printf("%d\n", arr[i].roll);
      printf("%d\n", arr[i].maths);
      scanf("%d\n", arr[i].physics);
      printf("%d\n", arr[i].chemistry);
   }

   return 0;
}
#include <stdio.h>

// Without the bellow line of code, the size is 12 and after using 6

#pragma pack(1)

// Include to avoid memory loss
// It is called packing and it controls from doing padding

struct abc
{
   char a;
   int c;
   char b;
};

int main()
{
   int size = sizeof(struct abc);

   printf("%d", size);
   return 0;
}
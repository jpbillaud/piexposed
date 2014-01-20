#include <stdio.h>

/*
 * Write a C program to find the size of structure without using sizeof operator
 */

#define SIZE_OF_STRUCT(mystruct) (size_t)((struct mystruct*)0+1)

int main()
{
   struct mystruct {
      int c;
   };

   printf("size %lu\n", SIZE_OF_STRUCT(mystruct));

   return 0;
}



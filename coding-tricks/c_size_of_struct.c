#include <stdio.h>

/*
 * Write a C program to find the size of structure without using sizeof operator
 */

#define SIZE_OF_STRUCT(mystruct)     \
   ({ struct nested_##mystruct {     \
         struct mystruct s;          \
         char end[0];                \
      } __attribute__((packed)) var; \
      var.end - (char *)&var; })

void main()
{
   struct mystruct {
      int c;
   };
   
   printf("size %d\n", SIZE_OF_STRUCT(mystruct));
}



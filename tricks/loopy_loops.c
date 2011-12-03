#include <stdio.h>

/*
 * Print the numbers from 1 to 1000 without using any loop or conditional
 * statements. Don’t just write the printf() or cout statement 1000 times.
 */

int loopy_loops(int i, int m)
{
   printf("%d\n", i);

   /*
    * XOR operator will only return false when i and m are the same
    */
   return (!(i^m)) || loopy_loops(i+1, m);
}

int main(int argc, char **argv)
{
   return loopy_loops(1, 1000);
}

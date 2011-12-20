#include <stdio.h>

/*
 * Write a function that given an integer ranging from 0 to 32 generates
 * a bit mask with that many bits.
 */

unsigned int
value_to_nb_bits(unsigned int value)
{
   return ((long long unsigned int)1 << value) - 1;
}

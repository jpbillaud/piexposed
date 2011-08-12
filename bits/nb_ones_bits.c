/*
 * Write a function that determines the number of 1 bits in the computer's
 * internal representation of a given integer.
 */

int
nb_ones_bits(int value)
{
   int nb_ones = 0;

   while (value) {
      nb_ones++;
      value &= (value - 1);
   }

   return nb_ones;
}

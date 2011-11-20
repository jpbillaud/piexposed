/*
 * Write a function that determines the Hamming distance of two integers that is
 * the number of bits that differs from one integer to the other.
 */

int
hamming_distance_bits(unsigned int value1, unsigned int value2)
{
   int nb_ones = 0;
   unsigned bits_diff_map = value1 ^ value2;

   while (bits_diff_map) {
      nb_ones++;
      bits_diff_map &= (bits_diff_map - 1);
   }

   return nb_ones;
}

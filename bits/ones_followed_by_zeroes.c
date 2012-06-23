/*
 * Write a function that determines if an integer is composed of any number of
 * bits set, followed by any number of bits unset. (Used to check if a netmask
 * is valid for example.)
 */

int
ones_followed_by_zeroes(unsigned int value)
{
  unsigned int boundaries = ~value + 1;
  return !(boundaries & (boundaries - 1));
}

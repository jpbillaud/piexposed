/*
 * Write a function that determines if a number is power of two.
 */

int
is_power_of_two(int value)
{
   return !(value & (value - 1));
}

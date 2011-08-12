/*
 * Write a function that determines whether a computer is big-endian or
 * little-endian.
 */

int
is_little_endian()
{
   union {
      int value;
      char first_byte;
   } u;
   u.value = 1;
   return u.first_byte;
}

int
is_big_endian()
{
   return !is_little_endian();
}

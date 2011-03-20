#include <stdlib.h>

/*
 * Write an efficient function to find the first nonrepeated character
 * in a string. For instance the first nonrepeated character in "total"
 * is 'o' and the first nonrepeated in "teeter" is 'r'.
 */

char
first_non_repeated_char(char *str)
{
   char count_arr[128] = {0, };
   char *tmp = str;

   /*
    * First fill in the counter table
    */
   while (*tmp) {      
      count_arr[*(tmp++)]++;
   }

   /*
    * Then look for the first non-repeated character
    */
   while (*str) {      
      if (count_arr[*str] == 1) {
         return *str;
      }
      str++;
   }   

   return '\0';
}

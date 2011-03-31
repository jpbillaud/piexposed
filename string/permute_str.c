#include <stdlib.h>
#include <string.h>

/*
 * Implement a routine that prints all possible orderings of
 * the characters in a string. In other words, print all
 * permutations that use all the characters from the original
 * string. For example, given the string "hat", your function
 * should print the strings "tha", "aht", "tah", "ath", "hta",
 * and "hat". Treat each character in the input string as a
 * distinct character, even if it is repeated. Given the string
 * "aaa", your routine should print "aaa" six times. You may
 * print the permutations in any order your choose.
 */

static void
do_permute_str(char *str,
               char *result_str,
               char *mark_arr,
               int pos,
               int arr_len)
{
   int idx;

   if (pos == arr_len) {
      // print the permutation here
      return;
   }

   for (idx = 0; idx < arr_len; idx++) {
      if (!mark_arr[idx]) {
         mark_arr[idx] = 1;
         result_str[pos] = str[idx];
         do_permute_str(str, result_str, mark_arr, pos + 1, arr_len);         
         mark_arr[idx] = 0;
      }
   }
}

int
permute_str(char *str)
{
   int arr_len = strlen(str) + 1;
   char *result_str;
   char *mark_arr;

   result_str = malloc(arr_len);
   if (!result_str) {
      return -1;
   }
   memset(result_str, 0, arr_len);

   mark_arr = malloc(arr_len);
   if (!mark_arr) {
      free(result_str);
      return -1;
   }
   memset(mark_arr, 0, arr_len);

   do_permute_str(str, result_str, mark_arr, 0, arr_len - 1);

   free(mark_arr);
   free(result_str);

   return 0;
}

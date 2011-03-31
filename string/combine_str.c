#include <stdlib.h>
#include <string.h>

/*
 * Implement a function that prints all possible combinations of the characters
 * in a string. These combinations range in length from one to the length of
 * the string. Two combination that differ only in ordering of their characters
 * are the same combination. In other words, "12" and "31" are different
 * combinations from the input string "123", but "21" is the same as "12".
 */

static void
do_combine_str(char *str,
               char *result_str,
               char *mark_arr,
               int pos,
               int combine_len)
{
   int idx;

   if (!combine_len) {
      // print the combination here
      return;
   }

   for (idx = 0; idx < strlen(str); idx++) {

      if (idx + combine_len > strlen(str)) {
         return;
      }

      if (!mark_arr[idx]) {
         mark_arr[idx] = 1;
         result_str[pos] = str[idx];
         do_combine_str(str, result_str, mark_arr, pos + 1, combine_len - 1);
         memset(mark_arr + idx + 1, 0, strlen(str) - idx - 1);
      }
   }
}

int
combine_str(char *str)
{
   int combine_len;
   char *result_str;
   char *mark_arr;

   for (combine_len = 1; combine_len <= strlen(str); combine_len++) {

      result_str = malloc(combine_len + 1);
      if (!result_str) {
         return -1;
      }
      memset(result_str, 0, combine_len + 1);

      mark_arr = malloc(strlen(str));
      if (!mark_arr) {
         free(result_str);
         return -1;
      }
      memset(mark_arr, 0, strlen(str));

      do_combine_str(str, result_str, mark_arr, 0, combine_len);

      free(mark_arr);
      free(result_str);
   }

   return 0;
}

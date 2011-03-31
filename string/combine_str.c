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
do_combine_str(char *str, char *result_str, int start, int pos, int str_len)
{
   int idx;

   for (idx = start; idx < str_len; idx++) {
      result_str[pos] = str[idx];
      // print the combination here
      do_combine_str(str, result_str, idx + 1, pos + 1, str_len);
   }
   result_str[pos] = '\0';
}

int
combine_str(char *str)
{
   char *result_str;
   int str_len = strlen(str);

   result_str = malloc(str_len + 1);
   if (!result_str) {
      return -1;
   }
   memset(result_str, 0, str_len + 1);

   do_combine_str(str, result_str, 0, 0, str_len);

   free(result_str);
   return 0;
}

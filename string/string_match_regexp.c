#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Write a function that implements a minimum regexp engine
 * where only '.', '*' and '.*' are supported assuming each
 * pattern requires beginning to end matching (not anywhere matching).
 *
 * For instance:
 *
 * 'abc' =~ 'abc' (ok)
 * 'abc' =~ 'a*bc' (ok)
 * 'aaaaaaabc' =~ 'c*bc' (ko)
 * 'aaaaaaabc' =~ 'a.*bc' (ok)
 * 'abbbbaaaaaabc' =~ 'ab*a*b*c' (ok)
 * 'abbbbaaaaaabc' =~ 'ab*a*h*bc' (ok)
 * 'bbd' =~ 'b*bbd' (ok)
 * 'bbd' =~ '.*bbd' (ok)
 * 'bbd' =~ '.*cbd' (ko)
 * '' =~ '.*' (ok)
 */

int string_match_regexp(char *str, char *pattern)
{
   /*
    * If we ever reached the end of the pattern then
    * there might be a match depending if we also
    * reached the end of string see last statement
    * of this function.
    */
   while (*pattern) {

      /*
       * If the next character is a wildcard then
       * we call recursively into the regexp engine
       * until we ate enough characters on the way i.e.
       * until the underlying recursive path succeed
       * or there is no eligible character to be eaten
       * anymore.
       *
       * This is the "backtracking" piece of the code 
       * since if the underlying call fails we step back
       * and try again with another character taken out of
       * the way.
       */
      if (*(pattern + 1) == '*') {
         while (*str && (*pattern == *str || *pattern == '.')) {
            if (string_match_regexp(str++, pattern+2)) {
               return 1;
            }
         }
         pattern += 2;
      } else {
         /*
          * The easy part, if the character pointed by str diverges
          * from the character pointed by pattern then we bail out
          * except if pattern points to '.' in which case we keep
          * going.
          */
         if (*pattern != '.' && *str != *pattern) {
            return 0;
         }

         str++;
         pattern++;
      }
   }

   /*
    * Only match if we reached the end of the string as well...
    */
   return !*str;
}

int main()
{
    printf("(1) %u expect 1\n", string_match_regexp("abc", "abc"));
    printf("(2) %u expect 1\n", string_match_regexp("abc", "a*bc"));
    printf("(3) %u expect 0\n", string_match_regexp("aaaaaaabc", "c*bc"));
    printf("(4) %u expect 1\n", string_match_regexp("aaaaaaabc", "a.*bc"));
    printf("(5) %u expect 1\n", string_match_regexp("abbbbaaaaaabc", "ab*a*b*c"));
    printf("(6) %u expect 1\n", string_match_regexp("abbbbaaaaaabc", "ab*a*h*bc"));
    printf("(7) %u expect 1\n", string_match_regexp("bbd", "b*bbd"));
    printf("(8) %u expect 1\n", string_match_regexp("bbd", ".*bbd"));
    printf("(9) %u expect 0\n", string_match_regexp("bbd", ".*cbd"));
    printf("(10) %u expect 1\n", string_match_regexp("", ".*"));
    printf("(11) %u expect 1\n", string_match_regexp("", ".*c*"));
    printf("(12) %u expect 0\n", string_match_regexp("bbbbdbdbdaac", ".*d"));
    printf("(13) %u expect 1\n", string_match_regexp("bbbb", "b*c*"));
    printf("(14) %u expect 1\n", string_match_regexp("bbbb", "b*b*c*"));
    printf("(15) %u expect 1\n", string_match_regexp("abcd", ".*d"));
    printf("(16) %u expect 0\n", string_match_regexp("abcd", ".*d*c*c*e*hhh*j*.*c*h"));
}

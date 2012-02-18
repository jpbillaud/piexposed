#include <stdio.h>

/*
 * Write a function that implements a minimum regexp engine
 * where only '.', '*' and '.*' are supported.
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
    * there is match.
    */

   while (*pattern) {

      /*
       * If the next character is a wildcard then
       * we try to vacuum whatever we can on the way
       */
      if (*(pattern + 1) == '*') {

         /*
          * If the wildcard applies to '.' then whatever
          * is the current character pointed by str will
          * be used to vacuum.
          */
         char match = (*pattern == '.') ? *str : *pattern;
         int count = 0;

         /*
          * If the characters after the wildcard are matching
          * the character we are supposed to vacuum then
          * we need to make sure we at least vacuum this much.
          *
          * That's mainly to deal with pattern looking like
          * 'b*bbb'.
          */
         pattern += 2;
         while (*pattern && *pattern == match) {
            pattern++;
            count++;
         }

         /*
          * Vacuum as much as we can.
          */
         while (*str == match) {
            str++;
            count--;
         }
         
         /*
          * Too bad we could not find enough matching characters
          * so let's bail out.
          */
         if (count > 0) {
            return 0;
         }
      } else {
         /*
          * The easy part, if the character pointed by str diverges
          * from the character pointed by pattern then we bail out
          * except if pattern points to '.' in which case we keep
          * going.
          */

         if (*pattern != '.' &&
             *str != *pattern) {
            return 0;
         }

         str++;
         pattern++;
      }
   }

   return 1;
}

int main()
{
   printf("%u\n", string_match_regexp("abc", "abc"));
   printf("%u\n", string_match_regexp("abc", "a*bc"));
   printf("%u\n", string_match_regexp("aaaaaaabc", "c*bc"));
   printf("%u\n", string_match_regexp("aaaaaaabc", "a.*bc"));
   printf("%u\n", string_match_regexp("abbbbaaaaaabc", "ab*a*b*c"));
   printf("%u\n", string_match_regexp("abbbbaaaaaabc", "ab*a*h*bc"));
   printf("%u\n", string_match_regexp("bbd", "b*bbd"));
   printf("%u\n", string_match_regexp("bbd", ".*bbd"));
   printf("%u\n", string_match_regexp("bbd", ".*cbd"));
   printf("%u\n", string_match_regexp("", ".*"));
}

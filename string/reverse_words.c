#include <stdlib.h>
#include <string.h>

/*
 * Write a function that reverses the order of the words in a string.
 * For example, your function should transform "Do or do not, there is no try."
 * to "try. no is there not, do or Do". Assume that all words are space
 * delimited and treat punctuation the same as letters.
 */

void
reverse_one_word(char *str)
{
   short length = strlen(str);
   char *start, *end;
   char tmp;

   for (start = str, end = str + length - 1;
        start < end;
        start++, end--) {
      tmp = *end;
      *end = *start;
      *start = tmp;
   }
}

void
reverse_words(char *str)
{
   char *start, *end;

   /*
    * First let's reverse the entire string in place.
    */
   reverse_one_word(str);

   /*
    * Then reverse words one at the time.
    */
   for (start = end = str; *end; end++) {
      if (*end == ' ') {
         *end = '\0';
         reverse_one_word(start);
         *end = ' ';
         start = end + 1;
      }
   }
   reverse_one_word(start);
}

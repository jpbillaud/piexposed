#include <stdlib.h>

/*
 * Write a function that deletes a set of characters from a string.
 */

void
rm_given_chars_from_str(char *str, char *chars_to_rm)
{
   char rm_arr[128] = {0, };
   char *tmp = str;
   int iter = 0;

   /*
    * Tag the character to remove in our constant-time access
    * array.
    */
   while (*chars_to_rm) {
      rm_arr[*(chars_to_rm++)] = 1;
   }

   /*
    * Remove characters one by one in the string
    */
   while (*tmp) {      
      if (rm_arr[*tmp]) {
         *tmp = '\0';
      }
      tmp++;
   }

   /*
    * Shift remaining letters to fill the gaps created
    * by the removed characters
    */
   for (; str != tmp; str++) {

      /*
       * If we bump into a null character then something
       * got removed there so we need to increase the offset
       * used for moving back characters
       */
      if (!*str) {
         iter++;
         continue;
      }

      /*
       * Now we move characters backward from offset bytes
       */
      if (iter) {
         *(str - iter) = *str;
         *str = '\0';
      }
   }
}

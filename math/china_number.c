#include <stdio.h>
#include <math.h>

/* 
 * Sometimes in China digit "4" is regarded as an unlucky number since it has the
 * same pronunciation with "death" in Chinese. In few conditions some people may want
 * to avoid using it. If we do that and make "4" disappear from current decimal number
 * system, the positive numbers in the system become: 
 * 0, 1, 2, 3, 5, 6, ..., 13, 15, ..., 23, 25, ..., 33, 35, ..., 39, 50, 51, ... 
 *
 * The question is: Given a positive integer n, get the results: (1) whether n is legal
 * in this system; (2) How many positive numbers which are less than or equal to the
 * input number. Write one function to get the two results. 
 *
 * Sample input & output: 
 * 1 -> 1 
 * 3 -> 3 
 * 6 -> 5 
 * 14 -> illegal 
 * 16 -> 14
 */

int is_legal(int n)
{
   int rank = 0;
   int nb_prev = 0;

   while (n) {
      int rest = n % 10;
   
      /*
       * If the number is illegal let's bail out right away.
       */
      if (rest == 4) {
         return -1;
      }
      n /= 10;

      /*
       * This is very much like base 9 computation. The idea is that for each
       * range of 10, there are 9 legal elements.
       */
      if (rest < 4) {
         nb_prev += rest * pow(9, rank);
      } else {
         /*
          * In this case the rest is greater than 4 so we need to take it out
          * of the count.
          */
         nb_prev += (rest-1) * pow(9, rank);
      }

      rank++;
   }

   return nb_prev;
}


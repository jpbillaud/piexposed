#include <stdlib.h>
#include <string.h>

/*
 * Implement a function to perform a binary search on a sorted
 * array of integers to find the index of a given integer.
 */

int
binary_search(int *array, int lower, int upper, int target)
{
   int idx = (upper + lower) / 2;
   int result;

   /*
    * If the lower index passed the upper one then we did
    * not found the target.
    */
   if (lower > upper) {
      return -1;
   }

   if (array[idx] == target) {
      return idx;
   }

   /*
    * Recursion happens here depending on the mid-value.
    */
   if (array[idx] > target) {
      return binary_search(array, lower, idx - 1, target);
   } else {
      return binary_search(array, idx + 1, upper, target);
   }
}

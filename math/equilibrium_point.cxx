#include <iostream>
#include <vector>

/*
 * Find a point in an array where sum of left side array members and
 * right side are equal.. in other words equilibrium point.
 */

using namespace std;

int arr[] = {1, 1, 3, 2};

int equilibrium_point(int *arr,
                      int arr_len)
{
   vector<int>vec(arr, arr + arr_len);
   vector<int>::iterator begin = vec.begin();
   vector<int>::iterator end = --vec.end();
   int sum_left = 0, sum_right = 0;

   /*
    * The idea is to have an iterator on the first element
    * and one on the last one and shrink the window base
    * on the accumulated sums on each side.
    *
    * If both iterators exactly meet and the sums are equal on
    * both side then we found the equilibrium point.
    */

   while (begin < end) {

      if (sum_left == sum_right) {
         sum_left += *begin++;
         sum_right += *end--;
         continue;
      }

      if (sum_left < sum_right) {
         sum_left += *begin++;
      } else {
         sum_right += *end--;
      }
   }

   return (begin == end &&
           sum_left == sum_right) ? *begin : -1;
}

int main()
{
   cout << equilibrium_point(arr, sizeof(arr)/sizeof(int)) << endl;
}

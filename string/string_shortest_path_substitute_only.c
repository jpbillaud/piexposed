#include <stdio.h>

/*
 * Write a function that given two strings returns the shortest path, on a per
 * character basis taking into account obstacles, from one to another. Note
 * that only obstacle 1 applies for the path from character 1 of string 1 to
 * character 2 of string 2.
 *
 *
 * For instance the distance between:
 *
 * - "AAA" and "FED" with obstacles "CHR" is 28.
 * - "A" and "D" with obstacle "C" is 23.
 * - "A" and "D" with obstacle "E" is 3.
 * - "D" and "A" with obstacle "E" is 3.
 * - "A" and "Y" with obstacle "Z" is 24.
 * - "A" and "Y" with obstacle "H" is 2.
 * - "B" and "D" with obstacle "A" is 2.
 *
 * Note that both strings as well as the obstacles string have the same length.
 */

#define max(a,b) (((a) < (b)) ? (b) : (a))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int string_shortest_path(char *str1, char *str2, char *forbid)
{   
   int dist;
   int from = min(*str1 - 'A', *str2 - 'A');
   int to = max(*str1 - 'A', *str2 - 'A');
   int obs = *forbid - 'A';

   if (!*str1) {
      return 0;
   }

   if (from < obs && to > obs) {
      dist = 26 - (to - from);
   } else {
      dist = to - from;
   }

   return dist + string_shortest_path(++str1, ++str2, ++forbid);
}

int main()
{
   printf("distance AAA -> FED (CHR) %d\n", string_shortest_path("AAA", "FED", "CHR"));
   printf("distance A -> Z (E) %d\n", string_shortest_path("A", "Z", "E"));
   printf("distance D -> A (E) %d\n", string_shortest_path("D", "A", "E"));
   printf("distance A -> D (E) %d\n", string_shortest_path("A", "D", "E"));
   printf("distance D -> A (C) %d\n", string_shortest_path("D", "A", "C"));
   printf("distance A -> D (C) %d\n", string_shortest_path("A", "D", "C"));
   printf("distance D -> G (Z) %d\n", string_shortest_path("D", "G", "Z"));
   printf("distance A -> Y (Z) %d\n", string_shortest_path("A", "Y", "Z"));
   printf("distance A -> Y (H) %d\n", string_shortest_path("A", "Y", "H"));
   printf("distance B -> D (A) %d\n", string_shortest_path("B", "D", "A"));
   printf("distance R -> A (H) %d\n", string_shortest_path("R", "A", "H"));
   printf("distance R -> A (Z) %d\n", string_shortest_path("R", "A", "Z"));

   return 0;
}

#include <stdio.h>
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
do_process_solution(char *str, int *is_present, int n_char)
{
    int idx;

    for (idx = 0; idx < n_char; idx++) {
        if (is_present[idx]) {
            printf("%c", str[idx]);
        }
    }
    printf("\n");
}

static void
do_combine_str(char *str, int *is_present, int pos, int n_char)
{
    int idx;
    int c_state[2] = {0, 1};

    if (pos == n_char) {
        do_process_solution(str, is_present, n_char);
        return;
    }

    for (idx = 0; idx < 2; idx++) {
        is_present[pos] = c_state[idx];
        do_combine_str(str, is_present, pos+1, n_char);
    }
}

int
combine_str(char *str)
{
    int *is_present;
    int n_char = strlen(str);

    is_present = malloc(n_char);
    if (!is_present) {
        return -1;
    }

    do_combine_str(str, is_present, 0, n_char);

    free(is_present);
    return 0;
}

int main()
{
    combine_str("abc");
}

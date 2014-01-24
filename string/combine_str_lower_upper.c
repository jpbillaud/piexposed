#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Implement a function that prints all possible combinations of the lower/upper
 * characters in a string. For instance "abC" would give out "abc", "AbC",
 * "ABc" and so on.
 */

static void
do_process_solution(char *str, int *is_upper, int n_char)
{
    int idx;

    for (idx = 0; idx < n_char; idx++) {
        if (is_upper[idx]) {
            printf("%c", toupper(str[idx]));
        } else {
            printf("%c", tolower(str[idx]));
        }
    }
    printf("\n");
}

static void
do_combine_str_lower_upper(char *str, int *is_upper, int pos, int n_char)
{
    int idx;
    int c_state[2] = {0, 1};

    if (pos == n_char) {
        do_process_solution(str, is_upper, n_char);
        return;
    }

    for (idx = 0; idx < 2; idx++) {
        is_upper[pos] = c_state[idx];
        do_combine_str_lower_upper(str, is_upper, pos+1, n_char);
    }
}

int
combine_str_lower_upper(char *str)
{
    int *is_upper;
    int n_char = strlen(str);

    is_upper = malloc(n_char);
    if (!is_upper) {
        return -1;
    }

    do_combine_str_lower_upper(str, is_upper, 0, n_char);

    free(is_upper);
    return 0;
}

int main()
{
    combine_str_lower_upper("abc");
}

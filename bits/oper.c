#include <stdio.h>

/*
 * Write function that implements the '+' and '-' operation along with 
 * various helpers.
 */

int
bit_most_sig(unsigned int value)
{
    return value ? 1 + bit_most_sig(value >> 1) : 0;
}

int
bit_comp_1(unsigned int value, unsigned int most_sbit)
{
    return ((1 << most_sbit) - 1) & ~value;
}

int
bit_comp_2(unsigned int value, unsigned int most_sbit)
{
    return bit_comp_1(value, most_sbit) + 1;
}

int
bit_add(unsigned int value1, unsigned int value2)
{
    int k = 0;
    int res = 0;
    int kept = 0;

    while (value1 || value2) {
        int bit1 = value1 & 1;
        int bit2 = value2 & 1;

        value1 >>= 1;
        value2 >>= 1;

        if (!bit1 && !bit2) {
            res |= kept << k++;
            kept = 0;
            continue;
        }

        if (bit1 ^ bit2) {
            res |= !kept << k++;
            continue;
        }

        res |= kept << k++;
        kept = 1;
    }

    return res | (kept << k);
}

int
bit_sub(unsigned value1, unsigned value2)
{
    int n_value1_msk;
    int n_value2_msk;
    int n_msk;
    int res;

    n_value1_msk = bit_most_sig(value1);
    n_value2_msk = bit_most_sig(value2);
    n_msk = (n_value1_msk > n_value2_msk) ? n_value1_msk : n_value2_msk;

    res = bit_add(value1, bit_comp_2(value2, n_msk));

    if (bit_most_sig(res) >= n_msk) {
        res &= (1 << n_msk) - 1;
    }

    return res;
}

int main()
{
    printf("5+3=%u\n", bit_add(5, 3));
    printf("17+15=%u\n", bit_add(17, 15));
    printf("0+1=%u\n", bit_add(0, 1));
    printf("0+0=%u\n", bit_add(0, 0));
    printf("102+44=%u\n", bit_add(102, 44));
    printf("6-3=%u\n", bit_sub(6, 3));
    printf("15-1=%u\n", bit_sub(15, 1));
    printf("33-25=%u\n", bit_sub(33, 25));
    printf("109-63=%u\n", bit_sub(109, 63));
    printf("91-7=%u\n", bit_sub(91, 7));
}

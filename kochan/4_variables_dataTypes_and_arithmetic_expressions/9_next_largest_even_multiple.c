/**
 * 9_next_largest_even_multiple.c
 * Tue, Jan 18, 2022 23:38hrs
 * 
 * This program rounds off an integer "i", to the
 * next largest even multiple of another integer "j"
 * using the formula
 * i + j - i % j
 */
#include <stdio.h>

int main(void)
{
    short i[] = {256, 365, 12258, 996};
    short j[] = {7, 7, 23, 4};

    for (short x = 0; x < 4; x++)
    {
        short rounded = i[x] + j[x] - i[x] % j[x];
        printf("%hi rounded to the next largest even multiple of %hi is %i\n", i[x], j[x], rounded);
    }

    return 0;
}
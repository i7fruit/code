/**
 * 4_will_equal_a.c
 * Wed, Jan 12, 2022 12:09hrs
 * The following expression will
 * always equal the value of the
 * first variable
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    short value0 = 1, value1 = 2, result = 0;

    result = value0 / value1 * value1 + value0 % value1;

    printf("%i\n", result);

    return 0;
}
/*
 * 2_type_specifiers.c
 * Tue, Jan 11, 2022 20:25hrs
 * This program illustrates the
 * use of type specifiers
 */
#include <stdio.h>
#include <limits.h> // To get range of min & max numbers one can store in each data type

int main(void)
{
    // For the range of numbers one can store in each data type
    printf("\nSigned Character char: %i to %i\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned Character char: %i to %i\n", 0, UCHAR_MAX);

    // Short Integers
    printf("\nsigned short int: %i to %i\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int: %i to %u\n", 0, USHRT_MAX);

    // Integers
    printf("\nsigned int: %i to %i\n", (-INT_MAX - 1), INT_MAX);
    printf("unsigned int: %i to %u\n", 0, UINT_MAX);

    // Long Integers
    printf("\nsigned long int: %li to %li\n", (-LONG_MAX - 1L), LONG_MAX);
    printf("unsigned long int: %i to %lu\n", 0, ULONG_MAX);

    // Long Long Integers
    printf("\nlong long int: %lli to %lli\n", (-LLONG_MAX - 1L), LLONG_MAX);
    printf("unsigned long long int: %i to %llu\n", 0, ULLONG_MAX);

    return 0;
}
#include <stdio.h>
#include <cs50.h>

#include <limits.h> // To get range of min & max numbers one can store in each data type

int main(void)
{
    char c = 'a';
    char b[] = "Osugo";
    string name = "Dave";
    int n = 7;
    float y = 1.2;

    printf("\n\nchar c = %lu byte, b = %lu bytes, string name = %lu bytes, int n = %lu bytes, float y = %lu bytes\n" \
    , sizeof(c), sizeof(b), sizeof(name), sizeof(n), sizeof(y));

    printf("\nBoolean values use %lu byte of space\n", sizeof(bool));
    printf("Integers use %lu bytes of space\n", sizeof(int));
    printf("Floats use %lu bytes of space\n", sizeof(float));
    printf("A Character uses %lu byte of space\n", sizeof(char));
    printf("Doubles use %lu bytes of space\n", sizeof(double));
    printf("Long integers use %lu bytes of space\n", sizeof(long));
    printf("Long Long integers use %lu bytes of space\n", sizeof(long long));
    printf("A string uses %lu bytes of space\n", sizeof(string));
    printf("Long Doubles use %lu bytes of space\n", sizeof(long double));

    // For the range of numbers one can store in each data type
    printf("\nSigned Character char: %i to %i\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned Character char: %i to %i\n", 0, UCHAR_MAX);

    // Integers
    printf("\nsigned int: %i to %i\n", (-INT_MAX - 1), INT_MAX);
    printf("unsigned int: %i to %u\n", 0, UINT_MAX);

    // Short Integers
    printf("\nsigned short int: %i to %i\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int: %i to %u\n", 0, USHRT_MAX);

    // Long Integers
    printf("\nsigned long int: %li to %li\n", (-LONG_MAX - 1L), LONG_MAX);
    printf("unsigned long int: %i to %lu\n", 0, ULONG_MAX);

    // Long Long Integers
    printf("\nlong long int: %lli to %lli\n", (-LLONG_MAX - 1L), LLONG_MAX);
    printf("unsigned long long int: %i to %llu\n", 0, ULLONG_MAX);

}

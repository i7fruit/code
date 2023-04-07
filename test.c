#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%i\n", INT_MAX);
    printf("%u\n", UINT_MAX);
    printf("%li\n", LONG_MAX);
    printf("%lli\n", LLONG_MAX);

    return 0;
}
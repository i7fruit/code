/** 
 * 01_function_arguments.c
 * 
 * Tuesday, June 14 2022 23:37hrs
 * 
 * Creates a function that calculates
 * a triangular number.
 */
#include <stdio.h>

void triangular_number(short value);

int main(void)
{
    short size = 0;
    do
    {
        printf("What triangular number do you want to find? ");
        scanf("%hi", &size);
    } 
    while (size < 1 || size > 20);

    triangular_number(size);

    return 0;
}

void triangular_number(short value)
{
    int triangular = 0;

    for (short i = 1; i <= value; i++)
    {
        triangular += i;
    }

    printf("Triangular number %hi = %i\n", value, triangular);
}
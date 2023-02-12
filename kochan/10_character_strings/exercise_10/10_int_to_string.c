/**
 * 10_int_to_string.c
 *
 * Saturday, February 11, 2023 15:48hrs
 *
 * This program takes an integer input from
 * the user and converts it to a string.
*/
#include <stdio.h>

// Function prototypes
long long get_integer(void);
void int_to_string(long long i, char arr[]);

int main(void)
{
    long long number = 0;
    short size = 64;

    number = get_integer();

    char string[size];

    int_to_string(number, string);

    printf("%s\n", string);

    return 0;
}

/***************************************
 * get_integer()
*/
long long get_integer(void)
{
    long long i = 0;

    do
    {
        printf("Enter an integer: ");
        scanf("%lli", &i);
    }
    while (i < -9000000000000000000 || i > 9000000000000000000);

    return i;
}

/*****************************************
 * int_to_string()
*/
void int_to_string(long long i, char arr[])
{
    int j = 0, size = 64;

    _Bool is_negative = 0;

    // Temporaray array
    char temp[size];

    // Value to convert integers 0 - 9, to character digits
    long long zero_character = 48;

    if (i < 0)
    {
        temp[j] = '-';
        i = -i;
        j++;
    }

    while (i != 0)
    {
        temp[j] = (i % 10) + zero_character;

        // Updates value of i
        i /= 10;
        j++;
    }

    // Terminates the temp string
    temp[j] = '\0';

    arr[j] = temp[j];

    // Iterator for arr[] array
    int k = 0;

    // Copies content of temp[] array into arr[] array
    if (is_negative)
    {
        for (; j > 0; j--, k++)
        {
            arr[k] = temp[j];
        }
    }

    else
    {
        for (j--; j >= 0; j--, k++)
            arr[k] = temp[j];
    }

    arr[k] = '\0';

    printf("Conversion complete!\n");
}
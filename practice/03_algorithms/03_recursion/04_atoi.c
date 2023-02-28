#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Computes the last element of the string
    int n = strlen(input) - 1;

    // Converts the last character
    int digit = input[n] - 48;

    // Removes this character from the string
    input[n] = '\0';

    // Base case
    if (n == 0)
        return input[n] * 10 + digit;

    return convert(input) * 10 + digit;
}
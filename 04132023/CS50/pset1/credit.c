/**
 * PSET 1
 *
 * credit.c
 *
 * January 12 2020 19:48 EST
 *
 * This program prompts the user for a credit card number
 * and then use's Luhn's Algorithm to validate the number.
 */
#include <stdio.h>
#include <cs50.h>
#include <limits.h>

// Variable to store the number of digits the card number has
short count;

// Function prototypes
unsigned long get_card_number(unsigned long i);
bool calc_checksum(unsigned long i);
void starting_digits_check(unsigned long i);

int main(void)
{
    // Variable to hold the credit card number
    unsigned long ccn = 0;

    // Prompts user for a credit card number
    ccn = get_card_number(ccn);

    // Calculates the checksum
    bool validity = calc_checksum(ccn);

    // Checks for the starting digits of the card
    if (validity)
    {
        starting_digits_check(ccn);
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}

/**
 * The get_card_number() function prompts the user for a credit card number
 * and then checks to make sure that it's got the right number of digits
 */
unsigned long get_card_number(unsigned long i)
{
    // Declares a variable to store a copy of the card number
    unsigned long j;

    // Prompts the user for a card number
    do
    {
        i = j = get_long("Enter a credit card number: ");

        // Computes the digit count of the number
        while (j > 0)
        {
            j /= 10;
            count++;
        }

    }
    while (count < 10 || count > 16);

    return i;
}

/**
 * The calc_checksum() function checks if the value of multiplying,
 * starting from the right, every other digit of the card by 2, and
 * adding the sum of that to the sum of the digits that weren't multiplied,
 * is equal to zero when the value of modulo divided by 10. If it is zero,
 * the the card might be valid, and thus returns a boolean value of true, for
 * the rest of the program to determine what credit card company the card belongs to.
 * Otherwise, it returns a value of false, and the program terminates and does no further
 * validity checks on the card.
 */
bool calc_checksum(unsigned long i)
{
    // Makes a copy of the card number
    unsigned long j = i;

    /**
     * Multiplies every other digit from right by 2,
     * and adds the sum of that operation to the sum of
     * the digits that weren't multiplied. If the value of
     * multiplying a digit by 2 is greater than 9, then the
     * program calculates the sum of each of the value's digits
     * by performing both regular and modulo division on the value
     */
    short total, x, y;
    total = x = y = 0;

    while (j > 0)
    {
        // Starts with rightmost digit
        x = j % 10;
        total += x;

        // Updates the number
        j /= 10;

        // Multiplies every other number by 2
        y = (j % 10) * 2;

        // Checks if result of multiplication yields a 2-digit number
        if (y > 9)
        {
            // Adds both digits if it does
            total += ((y / 10) + (y % 10));
            j /= 10;
        }

        else
        {
            // Adds value of multiplication to the total if it does not
            total += y;
            j /= 10;
        }
    }

    // Checks if the value of the total ends in zero
    if (total % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

/**
 * The starting_digits_check() function examines the starting digits
 * of the card to see if they match the starting digits of the credit
 * card numbers of the three companies we are checking for. It gets the
 * digits by constantly dividing the credit card number until the required
 * number of digits we want to check for is reached
 */
void starting_digits_check(unsigned long i)
{
    // Makes a copy of the number
    unsigned long j = i;

    while (j > 99)
    {
        j /= 10;
    }

    if ((j == 34 || j == 37) && count == 15)
    {
        printf("AMEX\n");
    }

    else if ((j >= 51 && j <= 55) && count == 16)
    {
        printf("MASTERCARD\n");
    }

    else if ((j / 10 == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
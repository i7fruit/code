/**
 * 08_escape_sequences.c
 *
 * Tuesday, August 30 2022 18:09hrs
 *
 * This program illustrates the use of
 * some escape characters in C.
 */
#include <stdio.h>

int main(void)
{
    // \" prints quotation marks "
    printf("\"Hello\"\n");

    // \? prints a question mark ?
    printf("What's your name\?\n");

    // \b backspace
    printf("The backspace character\b\b deletes the character that preceeds it\n");

    // \r carriage return positions the cursor at the beginning of the line
    printf("Why do you think we all do?");
    printf("\r ... people in Ghana\n");

    // \t horizontal tab
    printf("n\tn^2\n");
    printf("------------\n");
    printf("2\t4\n");
    printf("3\t6\n");

    // \v vertical tab ie drops the cursor to the next line at the current position
    printf("\nHello\vWorld!\n\n");

    // \nnn prints octal character values
    printf("\142\144\n"); // \142 = b, \144 = d, so line prints bd

    // \unnnn prints unicode characters
    printf("Pound Sterling = \u00A3\n");
    printf("Dollar sign = \u0024\n");
    printf("Copyright sign = \u00A9\n");

    // \xnn prints hex character values
    printf("\x23\n"); // prints #
    printf("\xBC\n"); // prints 1/4

    return 0;
}
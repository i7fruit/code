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
    printf("Hello\vWorld!\n");

    // \nnn prints octal values
    printf("Here = \0026\n");

    return 0;
}
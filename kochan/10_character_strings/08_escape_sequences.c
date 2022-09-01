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

    // \r carriage return
    printf("How do you do?\n");
    printf("\r in Ghana?\n");

    return 0;
}
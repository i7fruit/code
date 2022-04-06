/**
 * PSET 1
 * hello.c
 *
 * January 12 2020 15:54 EST
 *
 * This program prompts a user for their
 * name using the get_string() function and
 * prints it to the screen using printf
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts the user for their name
    string name = get_string("Please enter your name\n");
    printf("hello, %s\n", name);

    return 0;
}
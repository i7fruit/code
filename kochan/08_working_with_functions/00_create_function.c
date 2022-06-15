/** 
 * 00_create_function.c
 * 
 * Tuesday, June 14 2022 23:25hrs
 * 
 * This program illustrates how a function
 * is created.
 */
#include <stdio.h>

// Function prototype
void print_message(void);

int main(void)
{
    // Calls the print_message() function
    print_message();

    return 0;
}

/*****************************************
 * The print_message() function takes no
 * arguments and returns no value. It simply
 * prints a message to the screen using
 * the printf function.
 */
void print_message(void)
{
    printf("Hello, world!\n");
}
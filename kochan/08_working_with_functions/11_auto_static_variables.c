/** 
 * 11_auto_static_variables.c
 * 
 * Tuesday, June 28 2022 18:03hrs
 * 
 * This program illustrates the use of automatic
 * and static variables.
 */
#include <stdio.h>

// Function prototype
void auto_static(void);

int main(void)
{
    short round = 0;

    const short five = 5;

    // Calls the function five times
    for (short i = 0; i < five; i++)
        auto_static();

    putchar('\n');

    return 0;
}

/**************************************
 * auto_static()
 */
void auto_static(void)
{
    auto auto_var = 100;
    static static_var = 1;

    // Increments each variable at each function call
    auto_var++;
    static_var++;
}
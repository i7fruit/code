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
    {
        printf("Round %i\n", i + 1);
        auto_static();
    }

    putchar('\n');

    return 0;
}

/**************************************
 * auto_static()
 */
void auto_static(void)
{
    auto short auto_var = 100;
    static short static_var = 1;

    // Increments each variable at each function call
   printf("auto_var = %hi\nstatic_var = %hi\n\n", auto_var++, static_var++);
}
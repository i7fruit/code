/*
 * buggy1.c
 *
 * cs50 header file is missing
 * thus, restricting access to
 * the get_string() function.
 */

#include <stdio.h>
//#include <cs50.h>

int main(void)
{
    string s = get_string();
    printf("Hello %s\n", s);
}
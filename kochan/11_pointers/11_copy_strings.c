/**
 * 11_copy_strings.c
 *
 * Saturday, April 08 2023 18:56hrs
 *
 * Uses pointer notation to copy strings
 * to an array
*/
#include <stdio.h>

// Function prototype
void copy_str(char *to, char *from);
void print_string(char *str);

int main(void)
{
    char text[] = "Copy this string to a new location.";

    // Computes length of string to be copied
    int length = sizeof(text) / sizeof(text[0]);

    // Array to store copied string
    char string[length];

    // Iterates through text and copies contents to string
    copy_str(string, text);

    // Prints the contents of the string[] array
    print_string(string);

    putchar('\n');

    return 0;
}

/******************************************
 * The copy_str() function takes as arguments
 * two pointers; one to a string to be copied,
 * and the other to the location that string is
 * to be copied to. It uses a for loop to iterate
 * through the string to be copied, and assigns
 * the string to its new location by dereferencing
 * the pointer that points to the new location.
*/
void copy_str(char *to, char *from)
{
    while (*from != '\0')
    {
        *to = *from;
        to++; from++;
    }

    // Terminates the copied string
    *to = '\0';
}

/**********************************
 * print_string()
*/
void print_string(char *str)
{
    while (*str != '\0')
    {
       printf("%c", *str);
       str++;
    }
}
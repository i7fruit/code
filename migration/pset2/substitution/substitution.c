/**
 * pset 2
 * substitution.c
 * February 5 2020
 *
 * This program takes text input from a user and encrpts
 * it using a substitution cipher. It maps the text against
 * a twenty-six alphabetic-character key and prints out each
 * cipherkey as the user's text maps to it.
 */
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
bool key_validator(string s);

int main(int argc, string argv[])
{
    // Checks if the user gave one command line argument
    if (argc != 2)
    {
        printf("./substitution KEY\n");
        return 1;
    }

    // Checks if the user gave a valide key
    if (key_validator(argv[1]) == 0)
    {
        // Prompts the user for a key
        string s = get_string("Plaintext: ");

        // Computes the length of the string
        int n = strlen(s);

        // Declares an array to store the ciphertext
        char t[n + 1];

        // Determines the ciphertext
        for (int i = 0; i < n; i++)
        {
            if (isupper(s[i]))
            {
                t[i] = toupper(argv[1][s[i] - 'A']);
            }

            else if (islower(s[i]))
            {
                t[i] = tolower(argv[1][s[i] - 'a']);
            }

            else
            {
                t[i] = s[i];
            }
        }

        // Null terminates the ciphertext
        t[n] = '\0';

        // Prints the ciphertext
        printf("ciphertext: %s\n", t);

        return 0;
    }

    else
    {
        return 1;
    }
}

/**********************************************************
 * The key_validator() function takes a string of text
 * and checks if it is contains no non-alphabetic characters,
 * is twenty-six characters long, and has no repeting characters
 *
 * If all criteria checks out, the funtion returns true, and returns
 * false otherwise
 */
bool key_validator(string s)
{
    // Validates the key
    int len = strlen(s);

    if (len != 26)
    {
        printf("Must use 26-character key\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (!(isalpha(s[i])) || (toupper(s[i]) == toupper(s[j])))
            {
                printf("Must only contain non-repeating alphabetic characters\n");
                return 1;
            }
        }
    }

    return 0;
}
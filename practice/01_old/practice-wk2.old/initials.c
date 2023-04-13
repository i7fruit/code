/*
 * initials.c
 *
 * The following programs prints
 * the initials of whatever name
 * entered by the user
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define CHANGE_CASE 32 // the difference between upper and lowercase letters
#define APOSTROPHE 44 // ASCII value of the apostrophe (') character

int main()
{
    // prompt the user for input
    printf("Enter your name\n");
    string name = get_string();
    
    // makes sure that get_string() gets a string
    if (name != NULL)
    {
        // prints the first initial
        if (name[0] >= 'a' && name[0] <= 'z')
        {
            name[0] = name[0] - CHANGE_CASE;
        }
        printf("%c", name[0]);
        
        // iterates over the other characters
        for (int i = 1, n = strlen(name); i < n; i++)
        {
            if ((name[i] == ' ' || name[i] == '-' || name[i] == APOSTROPHE) && (name[i + 1] >= 'a' && name[i + 1] <= 'z'))
            {
                name[i + 1] = name[i + 1] - CHANGE_CASE;
                printf("%c", name[i + 1]);
            }
            else if ((name[i] == ' ' || name[i] == '-' || name[i] == APOSTROPHE) && (name[i + 1] >= 'A' && name[i + 1] <= 'Z'))
            {
                printf("%c", name[i + 1]);
            }
        }
    }
    printf("\n");
    return 0;
}
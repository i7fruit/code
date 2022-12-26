/**
 * 05_replace_string.c
 *
 * Saturday, December 24, 2022 21:48hrs
 *
 * This program scans through a string of
 * characters to identify a substring to
 * be replaced, and replaces that substring
 * with a new string of characters.
 */
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void get_text(char arr[]);

int main(void)
{
    const int size = 64;

    char text[size] = "";
    char str_to_delete[size] = "";
    char str_to_insert[size] = "";

    // Prompts the user for input
    printf("Enter a string of text\n");
    get_text(text);

    printf("Enter text to remove\n");
    get_text(str_to_delete);

    printf("Enter text to insert\n");
    get_text(str_to_insert);

    printf("%s\n", text);

    return 0;
}

/***********************************************
 * The get_text() function uses the getchar() function
 * to get a string of text from the user and stores
 * it in an array using a do-while loop
 */
void get_text(char arr[])
{
    int i = -1;

    do
    {
        arr[++i] =  getchar();
    }
    while (arr[i] != '\n');

    arr[i] = '\0';
}

/**************************************************
 * The find_string() function takes two arguments. One
 * array for a string of text, and the other array to
 * hold a string of text to find in the first array.
*/
int find_string(const char arr_0[], const char arr_1[])
{
    bool is_searching = true, index_set = false;
    int index = 0;

    // Traverses the array to find starting index of substring
    for (int i = 0, j = 0; arr_0[i] != '\0'; i++)
    {
        if (arr_0[i] == arr_1[j])
        {
            is_searching = false;

            if (!index_set)
            {
                index = i;
                index_set = true;
            }

            j++;
        }

        else
        {
            // Resets starting index of substring
            j = 0;
            is_searching = true;
            index_set = false;
        }
    }
}
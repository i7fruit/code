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
#include <string.h>

// Function prototypes
void get_text(char arr[]);
int find_string(const char arr_0[], const char arr_1[]);
void remove_string(char arr[], int index, int count);
void replace_string(char source[], char remove[], char insert[]);

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

    replace_string(text, str_to_delete, str_to_insert);

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

/*****************************************************
 * The replace_string() function replaces a string of
 * characters in an array with a new string of characters.
 */
void replace_string(char source[], char remove[], char insert[])
{
    int index = find_string(source, remove);

    // Number of characters to remove from source string
    int count = strlen(remove);

    if (index > 0)
        remove_string(source, index, count);
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

    // Computes length of each string
    int n = strlen(arr_0);
    int m = strlen(arr_1);

    // Terminates if substring is longer than main string
    if (m > n)
        return -1;

    // Traverses the array to find starting index of substring
    for (int i = 0, j = 0; arr_0[i] != '\0' && arr_1[j] != '\0'; i++)
    {
        // If both characters are equal...
        if (arr_0[i] == arr_1[j])
        {
            // ...signal that search for starting index has stopped...
            is_searching = false;

            // ...and set index if it has not been set
            if (!index_set)
            {
                index = i;
                index_set = true;
            }

            // Progresses through substring
            j++;
        }

        // If characters do not match
        else
        {
            // Reset starting index of substring...
            j = 0;

            // ...indicate that search for starting index is ongoing...
            is_searching = true;

            // ... and indicate starting index has not been set.
            index_set = false;
        }
    }

    // Returns the first index of the substring if set
    if (index_set)
        return index;

    // Returns a negative value if substring not found
    return -1;
}

/***************************************************************************
 * The remove_string() function takes as arguments an array that stores a string
 * of text, and two integers that store values for the starting index of a string
 * to be extracted from the array, and the number of characters that string will contain.
*/
void remove_string(char arr[], int index, int count)
{
    // Computes length of string to extract from
    int size = strlen(arr);
    int end = index + count;
    int i = index;

    /**
     * Traverses array from the starting index (i) of the substring
     * to the end of the array (size). Continues as long as the array
     * is traversible, and the end of the substring (end), is within
     * the bounds of the array (size)
     */
    for (; i < size && end < size; i++, end++)
    {
        // Overwrites characters to be removed with a bang sign
        arr[i] = '!';
    }

    //// Terminates the rest of the array when the end of the substring is reached
    //if (i < size)
    //    arr[i] = '\0';
}

/**********************************************
 * The insert_string() function uses a forloop
 * to insert one string of text into another
 */
void insert_string(char arr_0[], char arr_1[], int element)
{
    // Counts characters from insertion point to end of array
    int count = 0, i = -1, j = 0;
    int max = 64;

    while (arr_0[++i] != '\0')
        count++;

    // Store characters starting from insertion point into temporary array
    char temp[count];
    for (i = element; arr_0[i] != '\0'; i++, j++)
        temp[j] = arr_0[i];

    // Inserts new string
    for (i = element, j = 0; i != max && arr_1[j] != '\0'; i++, j++)
        arr_0[i] = arr_1[j];

    // Resets j
    j = 0;

    // Inserts rest of chars from temp array
    for (; i != max; i++, j++)
        arr_0[i] = temp[j];
}
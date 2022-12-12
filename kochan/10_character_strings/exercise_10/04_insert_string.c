/**
 * 04_insert_string.c
 *
 * Thursday, December 01, 2022 21:48hrs
 *
 * This program inserts a string of text into
 * another string of text and displays the result
 * to standard output.
 */
#include <stdio.h>
#include <string.h>

// Function prototypes
void get_text(char arr[]);
void insert_string(char arr_0[], char arr_1[], int element);

int main(void)
{
    // Maximum size of array
    const int size = 64;

    // Index to start insertion from
    int insertion_index = 0;

    // String of text to insert text into
    char text[size] = "";

    // String of text to insert
    char string[size] = "";

    printf("Enter a string of text: ");
    get_text(text);

    printf("Enter text to insert: ");
    get_text(string);

    printf("Insertion point: ");
    scanf("%i", &insertion_index);

    // Array to store full text
    int a = strlen(text), b = strlen(string), c;

    c = a + b;

    char concatenated[c];

    insert_string(text, string, insertion_index);

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
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    // Overwrites newline character with an ascii 0
    arr[i] = '\0';
}

/**********************************************
 * The insert_string() function uses a forloop
 * to insert one string of text into another
 */
void insert_string(char arr_0[], char arr_1[], int element)
{
    int i = 0, j = 0;

    // Inserts characters before insertion
    for (; i < element; i++)
        concatenated[i] = arr_0[i];

    // Inserts characters to be inserted
    for (; j < b; i++, j++)
        concatenated[i] = arr_1[j];

    // Resets j
    j = element;

    // Adds rest of characters
    for (; arr_0[j] != '\0'; i++, j++)
        concatenated[i] = arr_0[j];
}
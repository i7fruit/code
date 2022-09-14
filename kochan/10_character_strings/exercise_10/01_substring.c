/**
 * 01_substring.c
 *
 * Wednesday, September 14 2022 12:31hrs
 *
 * This program extracts a substring from
 * another string.
 */
#include <stdio.h>

void get_text(char arr[]);
void substring(const char source[], const int start, const int count, char result[]);

int main(void)
{
    const int size = 64;
    int low = 0, length = 0;

    char string[size] = "";
    char extract[size] = "";
    char result[size] = "";

    printf("Enter text: ");
    get_text(string);

    printf("Enter text to extract: ");
    get_text(extract);

    printf("Starting index: ");
    scanf("%i", &low);

    printf("Lenth of string: ");
    scanf("%i", &length);

    substring(string, low, length, result);

    printf("%s\n", result);

    return 0;
}

/*****************************************
 * The get_text() function prompts the user
 * for a string of text using the getchar()
 * function.
 */
void get_text(char arr[])
{
    int i = -1;

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    arr[i] = '\0';
}

/*****************************************
 * The substring() function takes an array
 * of characters and extracts a string of
 * text from it starting from the starting
 * index defined by the user. It saves the
 * extracted text in another array.
 */
void substring(const char source[], const int start, const int count, char result[])
{
    for (int i = start, j = 0; i < count && source[i] != '\0'; i++, j++)
    {
        result[j] = source[i];
    }
}
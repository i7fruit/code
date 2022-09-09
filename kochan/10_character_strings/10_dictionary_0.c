/**
 * 10_dictionary_0.c
 *
 * Wednesday, September 07 2022 22:18hrs
 *
 * This program searches through an array
 * of structs looking for a specific word.
 * When found, it returns an integer indicating
 * what position in the array the word is found,
 * or a -1 to indicate that the word is not located
 * in the array.
 */
#include <stdio.h>
#include <stdbool.h>

// Structure definition
struct entry
{
    char word[15];
    char definition[50];
};

// Function prototypes
bool equal_strings(const char arr_0[], const char arr_1[])

int main(void)
{
    // Size of the array of structs
    const int size = 10;

    // Declares an array of struct entry structs
    const struct entry dictionary[size] =
    {
        { "aardvark", "a burrowing African mammal" },
        { "abyss", "a bottomless pit" },
        { "acumen", "mentally sharp; keen" },
        { "addle", "to become confused" },
        { "aerie", "a high nest" },
        { "affix", "to append; attach" },
        { "agar", "a jelly made from seaweed" },
        { "ahoy", "a nautical call of greeting" },
        { "aigrette", "an ornamental cluster of feathers" },
        { "ajar", "partially opened" }
    };

    // Stores the word to search for
    char search_item[15];

    // Prompts user for word to search for
    printf("Word: ");
    scanf("%s", search_item);

    // Searches the dictionary array for the word
    lookup(dictionary, search_item, size);

    return 0;
}

/***************************************************
 * The lookup() function searches an array of struct entry
 * structures comparing the word to search for, with the
 * word member of each element of the struct entry array. If a
 * match is found, the function returns an integer representing
 * the element of the dictionary array where that word can be
 * found, otherwise it returns a -1, to indicate that the word
 * was not found.
 */
int lookup(struct entry[], char word, int n)
{
    // Searches dictionary for word
    for (int i = 0; i < n; i++)
    {
        if ()
    }
}

/***********************************************************
 * The equal_strings() functions compares each character in
 * two different arrays for equality. The function returns a
 * 1 if both strings of text are equal, and 0 if they are not.
 */
_Bool equal_strings(const char arr_0[], const char arr_1[])
{
    short i = 0;

    while (arr_0[i] == arr_1[i] && arr_0[i] != '\0')
        i++;

    if (arr_0[i] == '\0' && arr_1[i] == '\0')
        return 1;

    return 0;
}
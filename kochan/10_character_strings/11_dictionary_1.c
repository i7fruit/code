/**
 * 11_dictionary_1.c
 *
 * Friday, September 09 2022 12:31hrs
 *
 * This program uses binary search to search
 * through an array of struct entry elements
 * to find a word entered by the user to display
 * its definition. Otherwise message is displayed
 * letting the user know that the word could not
 * be found.
 */
#include <stdio.h>

#define FIFTEEN 15
#define SIXTY 60
#define HUNDRED 100

struct entry
{
    char word[FIFTEEN];
    char definition[SIXTY];
};

// Function prototype
void get_word(char arr[], const int n);

int main(void)
{
    // Dictionary of words and their definitions
    const struct entry dictionary[HUNDRED] =
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
        { "ajar", "partially opened" },
        { "babydoll", "a doll designed to look like a baby"},
        { "cagey", "reluctant to give information owing to caution or suspicion"}
    };

    char search_item[FIFTEEN];

    printf("Enter word to search for: ");
    get_word(search_item, FIFTEEN);

    lookup(dictionary, search_item, HUNDRED);

    return 0;
}

/**************************************************
 * This function uses the getchar() to get a word
 * from the user.
 */
void get_word(char arr[], const int n)
{
    int i = -1;

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n' && i < n);

    // Null terminates string
    arr[i] = '\0';
}

/***************************************************
 * The lookup() function searches an array of struct entry
 * structures comparing the word to search for, with the
 * word member of each element of the struct entry array.
 *
 * This function uses the Binary Search algorithm to efficiently
 * search through the array until the word is found.
 */
int
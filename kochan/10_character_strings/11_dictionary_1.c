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
#define SIZE 12

struct entry
{
    char word[FIFTEEN];
    char definition[SIXTY];
};

// Function prototype
void get_word(char arr[], const int n);
int lookup(const struct entry arr[], const char text[], const int n);
int compare_strings(const char arr0[], const char arr1[]);

int main(void)
{
    // Dictionary of words and their definitions
    const struct entry dictionary[SIZE] =
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

    int element = lookup(dictionary, search_item, SIZE);

    if (element == -1)
        printf("Word not in dictionary.\n");

    else
        printf("%s\n", dictionary[element].definition);

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
int lookup(const struct entry arr[], const char text[], const int n)
{
    int low = 0, hi = n - 1, mid = 0;

    while (low <= hi)
    {
        // Calculates midpoint
        mid = (low + hi) / 2;

        // Searches left part of array
        int position = compare_strings(arr[mid].word, text);

        // If dictionary word comes before search word, adjust low element
        if (position == -1)
            low = mid + 1;

        // If dictionary word comes after search word, adjust hi element
        else if (position == 1)
            hi = mid - 1;

        else
        // Returns mid element if dictionary word is same as search word
            return mid;
    }

    return -1;
}

/*****************************************************
 * compare_strings()
 */
int compare_strings(const char arr0[], const char arr1[])
{
    int i = 0;

    while (arr0[i] == arr1[i] && arr0[i] != '\0')
        i++;

    if (arr0[i] == arr1[i])
        return 0;

    else if (arr0[i] < arr1[i])
        return -1;

    return 1;
}
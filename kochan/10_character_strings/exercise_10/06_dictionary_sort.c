/**
 * 06_dictionary_sort.c
 *
 * Saturday, January 21, 2023 17:56hrs
 *
 * This program uses bubble sort to sort
 * a dictionary in ascending order.
*/
#include <stdio.h>

#define FIFTEEN 15
#define SIXTY 60
#define SIZE 12

// Structure definition
struct entry
{
    char word[FIFTEEN];
    char definition[SIXTY];
};

int main(void)
{
    // Declares an array of struct entry structure variables
    const struct entry dictionary[SIZE] =
    {
        { "aardvark", "a burrowing African mammal" },
        { "abyss", "a bottomless pit" },
        { "acumen", "mentally sharp; keen" },
        { "babydoll", "a doll designed to look like a baby"},
        { "addle", "to become confused" },
        { "aerie", "a high nest" },
        { "affix", "to append; attach" },
        { "agar", "a jelly made from seaweed" },
        { "ahoy", "a nautical call of greeting" },
        { "aigrette", "an ornamental cluster of feathers" },
        { "ajar", "partially opened" },
        { "cagey", "reluctant to give information owing to caution or suspicion"}
    };
}
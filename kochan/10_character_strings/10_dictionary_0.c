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

// Structure definition
struct entry
{
    char word[15];
    char definition[50];
};

int main(void)
{
    // Declares an array of struct entry structs
    struct entry dictionary[10] =
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
    }
}
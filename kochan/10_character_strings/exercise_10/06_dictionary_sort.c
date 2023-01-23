/**
 * 06_dictionary_sort.c
 *
 * Saturday, January 21, 2023 17:56hrs
 *
 * This program uses bubble sort to sort
 * a dictionary in ascending or descending
 * order.
*/
#include <stdio.h>

#define FIFTEEN 15
#define SIXTY 60
#define SIZE 16

// Structure definition
struct entry
{
    char word[FIFTEEN];
    char definition[SIXTY];
};

// Function prototypes
char get_order(void);
int compare_strings(char arr0[], char arr1[]);
void dictionary_sort(struct entry arr[], int size, char order);

int main(void)
{
    // Declares an array of struct entry structure variables
    struct entry dictionary[SIZE] =
    {
        { "aardvark", "a burrowing African mammal" },
        { "ubuntu", "a quality that includes the essential human virtues"},
        { "abyss", "a bottomless pit" },
        { "turquoise", "a greenish-blue color"},
        { "acumen", "mentally sharp; keen" },
        { "babydoll", "a doll designed to look like a baby"},
        { "addle", "to become confused" },
        { "aerie", "a high nest" },
        { "affix", "to append; attach" },
        { "eatery", "a restaurant or other place where people can be served food"},
        { "agar", "a jelly made from seaweed" },
        { "ahoy", "a nautical call of greeting" },
        { "aigrette", "an ornamental cluster of feathers" },
        { "ajar", "partially opened" },
        { "ecotage", "sabotage carried out for ecological reasons"},
        { "cagey", "reluctant to give information owing to caution or suspicion"}
    };

    // Prompts the user for an order to sort by
    printf("Sort in ascending or descending order a/d?: ");
    char order = get_order();

    // Sorts the dictionary in order
    dictionary_sort(dictionary, SIZE, order);

    printf("%s\n", dictionary[1].word);

}

/***************************************************************************
 * The get_order() function prompts the user to key in a character a or d
 * to indicate if they want the dictionary sorted in ascending or descending
 * order.
*/
char get_order(void)
{
    char order = ' ';

    do
    {
        order = getchar();
    }
    while ((order != 'a' && order != 'A') && (order != 'd' && order != 'D'));

    return order;
}

/*************************************************************************
 * The dictionary_sort() function sorts a dictionary in ascending or
 * descending order
*/
void dictionary_sort(struct entry arr[], int size, char order)
{
    // Temporary storage struct entry variable
    char temp[FIFTEEN];

    if (order == 'a' || order == 'A')
    {
        printf("Sorting in ascending order...\n");

        int counter = -1;

        do
        {
            counter = 0;

            for (int i = 0, j = 1; i < (size - 1); i++, j++)
            {
                if (compare_strings(arr[i].word, arr[j].word) == 1)
                {
                    /**
                     * Swaps the elements
                    */
                   // Stores arr[i].word in a temporary array
                   int k = 0;
                    for (; arr[i].word[k] != '\0'; k++)
                        temp[k] = arr[i].word[k];

                    // Terminates string in temp array
                    temp[k] = '\0';

                    // Stores arr[j].word in arr[i].word
                    for (int k = 0; arr[j].word[k] != '\0'; k++)
                        arr[i].word[k] = arr[j].word[k];

                    // Stores contents of the temp array into arr[j].word
                    for (int k = 0; temp[k] != '\0'; k++)
                        arr[j].word[k] = temp[k];

                    // Increment counter
                    counter++;
                }
            }
        }
        while (counter != 0);
    }

    else
    {
        //printf("Sorting in descending order...\n");

        //int counter = -1;

        //do
        //{
        //    counter = 0;

        //    for (int i = 0, j = 1; i < (size - 1); i++, j++)
        //    {
        //        if (compare_strings(arr[i].word, arr[j]) == -1)
        //        {
        //            // Swap elements

        //            // Increment counter
        //            counter++;
        //        }
        //    }
        //}
        //while (counter != 0);
    }
}

/*****************************************************
 * compare_strings()
 */
int compare_strings(char arr0[], char arr1[])
{
    int i = 0;

    /**
     * Iterates through each string while characters in
     * corresponding elements are the same
    */
    while (arr0[i] == arr1[i] && arr0[i] != '\0')
        i++;

    /**
     * Returns -1 if character in first array
     * comes before character in second array
     * alphabetically
     */
    if (arr0[i] < arr1[i])
        return -1;

    /**
     * Returns 1 if character in first array
     * comes after character in second array
     * alphabetically
     */
    else if (arr0[i] > arr1[i])
        return 1;

    // Returns 0 if both characters are equal
    return 0;
}
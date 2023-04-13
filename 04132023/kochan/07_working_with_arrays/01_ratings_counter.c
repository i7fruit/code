/*
 01_ratings_counter.c

 Tuesday, June 07 2022 20:37hrs

 Program uses an array to increment the
 frequency count in elements of an array.
 */
#include <stdio.h>

#define SIZE 11
#define RESPONDENTS 20

int main(void)
{
    short ratings_counter[SIZE], response;

    // Initializes ratings_counter[] array to zeros
    for (short i = 0; i < SIZE; i++)
        ratings_counter[i] = 0;

    // Prompts user for response
    printf("Enter response between 1 and 10\n");

    for (short i = 0; i < RESPONDENTS; i++)
    {
        printf("What is your rating? ");
        scanf("%hi", &response);

        if (response < 1 || response > 10)
        {
            printf("Invalid rating\n");
            i--;
        }
        else
            ratings_counter[response]++;
    }

    printf("\n\nRating    Number of responses\n");
    printf("---------------------------------\n");
    for (short i = 1; i < SIZE; i++)
        printf("%4i%14i\n", i, ratings_counter[i]);

    return 0;
}
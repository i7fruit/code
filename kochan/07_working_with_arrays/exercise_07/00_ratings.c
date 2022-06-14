/*
 00_ratings.c

 Tuesday, June 13 2022 21:46hrs

 Program uses an array to increment the
 frequency count in elements of an array.
 */
#include <stdio.h>

#define SIZE 11
#define RESPONDENTS 20

int main(void)
{
    short responses = 0;

    short ratings_counter[SIZE];

    // Initializes ratings_counter[] array to zeros
    for (short i = 0; i < SIZE; i++)
        ratings_counter[i] = 0;

    // Prompts user for response
    printf("Enter response between 1 and 10\n");
    do
    {
        printf("What is your rating? ");
        scanf("%hi", &responses);

        if (responses == 999)
        {
            printf("End of entry\n");
            break;
        }

        if (responses < 1 || responses > 10)
        {
            printf("Invalid rating\n");
            continue;
        }
        else
            ratings_counter[responses]++;
    }
    while (responses > 0 && responses < SIZE);

    printf("\n\nRating    Number of responses\n");
    printf("---------------------------------\n");
    for (short i = 1; i < SIZE; i++)
        printf("%4i%14i\n", i, ratings_counter[i]);

    return 0;
}
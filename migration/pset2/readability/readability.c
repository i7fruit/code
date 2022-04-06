/**
 * pset 2
 * readability.c
 * February 4 2020
 * This program parses are string of text
 * and uses the Coleman-Liau index to compute
 * what grade level that the text is suited for
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
float count_letters(string s);
float count_words(string s);
float count_sentences(string s);
void grade_level(string s);

int main(void)
{
    // Prompts the user to enter text
    string text = get_string("Text: ");

    // // Computes number of letters within text
    // printf("%i\n", count_letters(text));

    // // Computes the number of words within the text
    // printf("%i\n", count_words(text));

    // // Computes the number of sentences within the text
    // printf("%i\n", count_sentences(text));

    // // Uses the Coleman-Liau index to compute the grade level of the text
    grade_level(text);


    return 0;
}

/********************************************************************
 * The count_letters() function takes a string of text and iterates
 * through its characters to determine how many letters are contained
 * within it
 */
float count_letters(string s)
{
    float n = 0;

    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (isalpha(s[i]))
        {
            n++;
        }
    }

    return n;
}

/********************************************************************
 * The count_words() function takes a string of text and iterates through
 * its characters to determine how may words are contained within it
 */
float count_words(string s)
{
    float w = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == ' ' || s[i + 1] == '\0')
        {
            w++;
        }

        i++;
    }

    return w;
}

/********************************************************************
 * The count_sentences() function iterates through a string of text
 * to determine how many sentences are contained therein.
 */
float count_sentences(string s)
{
    float t = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            t++;
        }
    }

    return t;
}

/********************************************************************
 * The coleman-liau index computes the grade level of the text
 */
void grade_level(string s)
{
    // Gets number of words
    float words = count_words(s);

    // Gets average number of letters per 100 words
    float L = (count_letters(s) / words) * 100;

    // Gets number of sentences
    float S = (count_sentences(s) / words) * 100;

    // Computes index
    float I = 0.0588 * L - 0.296 * S - 15.8;

    if (I < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (I > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.0f\n", round(I));
    }
}
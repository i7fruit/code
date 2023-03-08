/**
 * fscanf_3.c
 *
 * Sunday, Oct 21 2018 20:22hrs
 *
 * This program uses fscanf to read
 * input from a file containing text
 *
 * This can be a problem especially
 * when we don't know how long the
 * longest word is
 */
#include <stdio.h>

#define MAX 8

int main(void)
{
    // A pointer to a string of text
    const char *text = "text.txt";

    FILE *fptr = fopen(text, "r");
    if (!fptr)
        return -1;

    char word[MAX]; // If this temp buffer isn't large enough, you will overwrite stuff in
                  // memory.
                  // You can fix this by limiting the number of bytes fscanf reads at a
                  // time, but that is inefficient

    while (!feof(fptr))
    {
        fscanf(fptr, "%5s", word); // fscanf won't read spaces into the buffer
        printf("%s ", word);
    }

    fclose(fptr);

    return 0;
}
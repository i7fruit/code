/**
 * fread_3.c
 *
 * This program reads data written
 * to the file from fread_2.c, stores
 * it in an array, and prints the contents
 * of that array to standard output
 */

#include <stdio.h>

#define SIZE 5

FILE *fptr;

int main(void)
{
    // Checks to know if pointer returns null
    if ((fptr = fopen("mydata", "r")) == 0)
    {
        fprintf(stderr, "Cannot open file\n");
        return 1;
    }

    // Declares an array to hold read values, and an int to store count
    int values[SIZE];
    int n = 0;

    // Reads from file, stores to array, and stores count in n
    n = fread(values, sizeof(int), SIZE, fptr);

    printf("Function read %i items\n", n);

    // Prints contents of the array
    for (int i = 0; i < SIZE; i++)
        printf("%i ", values[i]);

    fclose(fptr);

    return 0;
}
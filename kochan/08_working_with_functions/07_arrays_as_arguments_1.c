/** 
 * 07_arrays_as_arguments_1.c
 * 
 * Wednesday, June 22, 2022 01:30hrs
 * 
 * This program illustrates how arrays
 * can be arguments to a function.
 */
#include <stdio.h>

// Function prototypes
int maximum(int arr[], int size);
int get_integer(void);
void mult_by_two(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
    int number_of_integers = 0, max = 0;

    // Prompts user for size of array
    number_of_integers = get_integer();

    int values[number_of_integers];

    for (short i = 0; i < number_of_integers; i++)
        values[i] = 0;

    // Prompts user to enter values for the array
    for (short i = 0; i < number_of_integers; i++)
    {
        printf("Enter value %i: ", i + 1);
        scanf("%i", &values[i]);
    }

    // Prints the array
    print_array(values, number_of_integers);

    // Calls the maximum() function
    max = maximum(values, number_of_integers);

    printf("\nMaximum value is %i\n", max);

    // Multiplies values in each element by two
    mult_by_two(values, number_of_integers);

    // Value of array after doubling its values
    print_array(values, number_of_integers);

    //max = maximum()

    return 0;
}

/**************************************
 * The get_integer() function gets a
 * positive integer from the user and
 * returns it to main()
 */
int get_integer(void)
{
    int i = 0;

    do
    {
        printf("Enter a positive integer: ");
        scanf("%i", &i);
    } 
    while (i < 1 || i > 7);

    return i;
}

/****************************************
 * The maximum() function calculates what
 * the largest integer in the array is, and
 * returns it to the calling function.
 */
int maximum(int arr[], int size)
{
    int m = arr[0];

    for (short i = 1; i < size; i++)
        if (arr[i] > m)
            m = arr[i];

    return m;
}

/*************************************
 * The mult_by_two() function multiplies
 * every element in a given array by two
 */
void mult_by_two(int arr[], int size)
{
    const short two = 2;

    for (short i = 0; i < size; i++)
        arr[i] *= two;

    return;
}

/**************************************
 * The print_array() function uses a
 * forloop and the printf() function
 * to print values of the array to standard
 * output.
 */
void print_array(int arr[], int size)
{
    for (short i = 0; i < size; i++)
        printf("%i ", arr[i]);

    return;
}
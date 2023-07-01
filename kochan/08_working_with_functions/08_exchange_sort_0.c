/**
 * 08_exchange_sort_0.c
 *
 * Friday, June 24 2022 11:41hrs
 *
 * This program sorts an array of integers
 * by comparing the values of each element
 * with every other element and swaping them
 * into position in ascending order.
 */
#include <stdio.h>

// Function prototypes
int get_integer(char text[]);
void fill_array(int arr[], int n);
void print_array(int arr[], int size);
void exchange_sort(int arr[], int n);

int main(void)
{
    int size = 0;

    size = get_integer("How many numbers do you want to sort? ");

    int values[size];

    // Prompts user to initialize array
    fill_array(values, size);

    // Array before sort
    print_array(values, size);

    exchange_sort(values, size);

    // Array after sort
    print_array(values, size);

    return 0;
}

/**************************************
 * The get_integer() function gets a
 * positive integer from the user and
 * returns it to main()
 */
int get_integer(char text[])
{
    int i = 0;

    do
    {
        printf("%s");
        scanf("%i", &i);
    }
    while (i < 1 || i > 7);

    return i;
}

/**********************************
 * The fill_array() function uses a
 * forloop and the scanf() function
 * to get integers from the user and
 * populates an array.
 */
void fill_array(int arr[], int n)
{
    for (short i = 0; i < n; i++)
    {
        printf("Value %i: ", i + 1);
        scanf("%i", &arr[i]);
    }
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

    putchar('\n');

    return;
}

/***************************************
 * exchange_sort()
 */
void exchange_sort(int arr[], int n)
{
    for (short i = 0; i < (n - 1); i++)
        for (short j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
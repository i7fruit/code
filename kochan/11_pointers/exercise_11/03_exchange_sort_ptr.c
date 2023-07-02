/**
 * 12_exchange_sort_1.c
 *
 * Saturday, July 02 2022 09:44hrs
 *
 * This program sorts an array of integers
 * by comparing the values of each element
 * with every other element and swaping them
 * into positions of ascending or descending order
 * specified by the user.
 */
#include <stdio.h>
#include <ctype.h>

// Function prototypes
int get_integer(char *text);
char get_character(char text[]);
void fill_array(int arr[], int n);
void print_array(int arr[], int size);
void exchange_sort(int arr[], int n, char o);

int main(void)
{
    int size = 0;
    char order = ' ';

    size = get_integer("Enter an array size no greater than 7: ");

    int values[size];

    order = get_character("Sort in ascending (A/a) or descending (D/d): ");

    // Prompts user to initialize array
    fill_array(values, size);

    // Array before sort
    print_array(values, size);

    exchange_sort(values, size, order);

    // Array after sort
    print_array(values, size);

    return 0;
}

/**************************************
 * The get_integer() function gets a
 * positive integer from the user and
 * returns it to main()
 */
int get_integer(char *text)
{
    int i = 0;

    do
    {
        printf("%s ", text);
        scanf("%i", &i);
    }
    while (i < 1 || i > 7);

    return i;
}

/******************************
 * get_character()
 */
char get_character(char text[])
{
    char c = ' ';

    do
    {
        printf("%s ", text);
        scanf("%c", &c);
    }
    while (c != 'a' && c != 'A' && c != 'd' && c != 'D');

    return c;
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
        printf("Value[%i]: ", i);
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
void exchange_sort(int arr[], int n, char o)
{
    for (short i = 0; i < (n - 1); i++)
        for (short j = i + 1; j < n; j++)
        {
            if (o == 'a' || o == 'A')
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else if (o == 'd' || o == 'D')
            {
                if (arr[i] < arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
}
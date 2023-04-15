/**
 * 14_pointer_to_function.c
 *
 * Friday, April 14 2023 20:18hrs
 *
 * This program illustrates the use of pointers
 * to functions.
*/
#include <stdio.h>

int main(void)
{
    int *value = NULL;
    int *multiplier = NULL;

    get_values(value, multiplier);

    printf("%i\n%i\n", value, multiplier);

    return 0;
}

/**********************************************
 * get_values()
*/
void get_values(int *num, int *mult)
{
    int i = 0, j = 0;

    num = malloc(sizeof(int));
    if (!num)
    {
        fprintf(stderr, "Insufficient memory\n");
        return 1;
    }

    mult = malloc(sizeof(int));
    if (!mult)
    {
        fprintf(stderr, "Insufficient memory\n");
        return 2;
    }

    scanf("%i", &i);
    *num = i;
    scanf("%i", &j);
    *mult = j;
}
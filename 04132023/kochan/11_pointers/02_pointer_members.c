/**
 * 02_pointer_members.c
 *
 * Saturday, March 11 2023 12:29hrs
 *
 * This program illustrates the use of structure variables
 * that have pointers as its members
*/
#include <stdio.h>

// Structure definition
typedef struct
{
    int *age;
    float *height;
}
person;

int main(void)
{
    // Structure definition
    person man;

    // Regular int variables
    int x = 23;
    float y = 1.76;

    // Initializes the struct variable man
    /**
     * NOTE: If a structure is not initialized during declaration,
     * newly assigned values have to be typecast to the data type
     * of the structure
     */
    man = (person){&x, &y};  // Also *man.age = x, *man.height = y

    printf("%i, %.2f\n", *man.age, *man.height);

    return 0;
}
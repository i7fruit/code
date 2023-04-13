/** 
 * 03_array_of_structures.c
 * 
 * Wednesday, July 27 2022 16:14hrs
 * 
 * This program illustrates the use of an
 * array of structures in C.
 */
#include <stdio.h>

// Structure definition
struct time
{
    int hours;
    int minutes;
    int seconds;
};

// Function prototype
void print_array(struct time array[], int n);
struct time time_update(struct time value);

int main(void)
{
    const short size = 5;

    // Structure declaration
    struct time lap_times[size] =
    {
        {11, 59, 59}, {12, 0, 0}, {1, 29, 59}, {23, 59, 59}, {19, 12, 27}
    };
    
    printf("Current times\n");
    print_array(lap_times, size);

    printf("\nTimes after one sec\n");

    for (short i = 0; i < size; i++)
        lap_times[i] = time_update(lap_times[i]);

    print_array(lap_times, size);

    return 0;
}

/********************************************************************
 * print_array()
 */
void print_array(struct time array[], int n)
{
    for (short i = 0; i < n; i++)
        printf("%.2i:%.2i:%.2i\n", array[i].hours, array[i].minutes, array[i].seconds);
}

/********************************************************************
 * time_update()
 */
struct time time_update(struct time value)
{
    // Updates time by a second
    value.seconds++;

    if (value.seconds != 60)
        return value;

    else
    {
        value.seconds = 0;
        value.minutes++;

        if (value.minutes != 60)
            return value;

        else
        {
            value.minutes = 0;
            value.hours++;

            if (value.hours != 24)
                return value;

            else
            {
                value.hours = 0;
                value.minutes = 0;
                value.seconds = 0;
            }
        }
    }

    return value;
}
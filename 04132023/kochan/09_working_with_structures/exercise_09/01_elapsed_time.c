/**
 * 01_elapsed_time.c
 *
 * Tuesday, August 02 2022 18:02hrs
 *
 * This program calculates the elapsed time between
 * two time stamps.
 */
#include <stdio.h>

// Struct definition
struct time
{
    int hours;
    int minutes;
    int seconds;
};

// Function prototypes
int get_integer(void);
struct time get_time(void);
void print_time(struct time value);
struct time elapsed_time(struct time start, struct time end);

int main(void)
{
    // Struct declaration
    struct time start_time, end_time, elapsed;

    // Prompts user for a start and end time
    start_time = get_time();
    end_time = get_time();

    printf("Time elapsed between ");
    print_time(start_time);
    printf(" and ");
    print_time(end_time);
    printf(" is ");

    elapsed = elapsed_time(start_time, end_time);

    print_time(elapsed);
    putchar('\n');

    return 0;
}

/********************************************************************************
 * get_integer()
 */
int get_integer(void)
{
    int i = 0;

    do
    {
        scanf("%i", &i);
    }
    while (i < 1);

    return i;
}

/********************************************************************
 * get_time()
 */
struct time get_time(void)
{
    struct time value;

    printf("Hour: ");
    do
    {
        scanf("%i", &value.hours);
    }
    while (value.hours < 0 || value.hours > 23);

    printf("Minutes: ");
    do
    {
        scanf("%i", &value.minutes);
    }
    while (value.minutes < 0 || value.minutes > 59);

    printf("Seconds: ");
    do
    {
        scanf("%i", &value.seconds);
    }
    while (value.seconds < 0 || value.seconds > 59);

    return value;
}

/********************************************************************
 * print_time()
 */
void print_time(struct time value)
{
    printf("%.2i:%.2i:%.2i", value.hours, value.minutes, value.seconds);
}

/********************************************************************
 * elapsed_time()
 */
struct time elapsed_time(struct time start, struct time end)
{
    struct time temp = {0, 0, 0};

    // Subtracts seconds
    // If need to borrow sixty seconds...
    if (end.seconds < start.seconds)
    {
        // ...check if minutes are sufficient
        if (end.minutes > 0)
        {
            end.minutes--;
            end.seconds += 60;
            temp.seconds = end.seconds - start.seconds;
        }

        // ...if minutes are not sufficient
        else if (end.minutes == 0)
        {
            // ...borrow sixty minutes if hours are sufficient
            if (end.hours > 0)
            {
                end.hours--;
                end.minutes++;
                // ...then add to seconds
                end.seconds += 60;
                temp.seconds = end.seconds - start.seconds;
            }

            // ...if hours not sufficient, add 24 hours
            else if (end.hours == 0)
            {
                end.hours += 24;
                end.hours--;
                end.minutes += 60;
                // ...add to seconds
                end.minutes--;
                end.seconds += 60;
                temp.seconds = end.seconds - start.seconds;
            }
        }
    }

    else
        temp.seconds = end.seconds - start.seconds;

    // Subtracts minutes
    // If need to borrow sixty minutes...
    if (end.minutes < start.minutes)
    {
        // ...check if hours are sufficient
        if (end.hours > 0)
        {
            end.hours--;
            end.minutes += 60;
            temp.minutes = end.minutes - start.minutes;
        }

        // ...if hours are not sufficient...
        else if (end.hours == 0)
        {
            // ...add 24 hours
            end.hours += 24;
            end.hours--;
            end.minutes += 60;
            temp.minutes = end.minutes - start.minutes;
        }
    }

    else
        temp.minutes = end.minutes - start.minutes;

    // Subtracts hours
    // If end hour is less than start hour...
    if (end.hours < start.hours)
    {
        // ...add one hour to value of end.hours
        end.hours += 24;
        temp.hours = end.hours - start.hours;
    }

    else
        temp.hours = end.hours - start.hours;

    return temp;
}
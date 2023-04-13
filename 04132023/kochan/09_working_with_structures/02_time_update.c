/** 
 * 02_time_update.c
 * 
 * Tuesday, July 26 2022 22:20hrs
 * 
 * This program updates the value of
 * a timestamp by one second.
 */
#include <stdio.h>

// Structure definition
struct time
{
    int hours;
    int minutes;
    int seconds;
};

// Function prototypes
int get_integer(void);
struct time get_time(void);
struct time time_update(struct time value);

int main(void)
{
    struct time current_time, updated_time;

    current_time = get_time();

    printf("Current time: %.2i:%.2i:%.2i\n", current_time.hours, current_time.minutes, current_time.seconds);

    updated_time = time_update(current_time);

    printf("Updated time: %.2i:%.2i:%.2i\n", updated_time.hours, updated_time.minutes, updated_time.seconds);

    return 0;
}

/********************************************************************
 * get_integer()
 */
int get_integer(void)
{
    int i = 0;

    scanf("%i", &i);

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

            if (value.hours != 60)
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
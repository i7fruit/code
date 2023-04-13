/**
 * 05_structures_containing_structures.c
 *
 * Friday, July 29 2022 12:39hrs
 *
 * This program illustrates how a structure
 * can have other structures as its members.
 */
#include <stdio.h>
#include <stdbool.h>

// Time struture
struct time
{
    int hours;
    int minutes;
    int seconds;
};

// Date struture
struct date
{
    int month;
    int day;
    int year;
};

// Date-time structure
struct date_time
{
    struct time stime;
    struct date sdate;
};

// Function prototypes
int get_integer(void);
void print_date_time(struct date_time value);
struct time get_time(void);
struct time time_update(struct time value);
struct date get_date(void);
struct date date_update(struct date value);
bool is_leap_year(int year);
int number_of_days(struct date value);

int main(void)
{
    // Structure declaration
    struct date_time event, event_update;

    // Prompts user for input
    event.sdate = get_date();
    event.stime = get_time();

    event_update = event;

    // Prints out the date and time
    print_date_time(event);
    putchar('\n');

    // Updates the time by one second
    event_update.stime = time_update(event.stime);

    if (event_update.stime.hours == 0 && event_update.stime.minutes == 0 && event_update.stime.seconds == 0)
        event_update.sdate = date_update(event.sdate);

    print_date_time(event_update);

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

/********************************************************************************
 * print_date_time()
 */
void print_date_time(struct date_time value)
{
    printf("%.2i.%.2i.%.2i\n%.2i:%.2i:%.2i\n", value.sdate.month, value.sdate.day, value.sdate.year % 100 \
    , value.stime.hours, value.stime.minutes, value.stime.seconds);
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

/********************************************************************************
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

/********************************************************************************
 * The is_leap_year() function takes an
 * integer and uses an if statement to check
 * if that value is evenly divisible by
 * 4 and not evenly divisible by 100, OR
 * evenly divisible by 400. If this check
 * returns true it indicates that that value
 * qualifies as a leap year. The function returns
 * false, otherwise.
 */
bool is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }

    return false;
}

/********************************************************************************
 * The number_of_days() function computes the
 * total number of days each month of the year
 * contains.
 */
int number_of_days(struct date value)
{
    // Lookup table for number of days in each month
    const int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (value.month == 2)
    {
        if (is_leap_year(value.year))
            return days_per_month[value.month - 1] + 1;

        else
            return days_per_month[value.month - 1];
    }

    return days_per_month[value.month - 1];
}

/********************************************************************************
 * get_date()
 */
struct date get_date(void)
{
    struct date value;

    // Prompts user for a date
    printf("Enter month: ");
    do
    {
        value.month = get_integer();
    }
    while (value.month < 1 || value.month > 12);

    printf("Enter day: ");
    do
    {
        value.day = get_integer();
    }
    while (value.day < 1 || value.day > 31);

    printf("Enter year: ");
    do
    {
        value.year = get_integer();
    }
    while (value.year < 1);

    return value;
}

/********************************************************************************
 * The date_update() function takes a struct
 * date argument and computes the value of
 * a date incremented by one day.
 */
struct date date_update(struct date value)
{
    struct date tomorrow = {.month = 0, .day = 0, .year = 0};

    // Update the day by 1
    value.day++;

    // If day is beyond month limit...
    if (value.day > number_of_days(value))
    {
        tomorrow.day = 1;

        // If last day of year...
        if (value.month == 12)
        {
            tomorrow.month = 1;
            tomorrow.year = value.year + 1;
        }

        // ...in february of a leap year...
        else if (value.month == 2)
        {
            if (is_leap_year(value.year))
            {
                if (value.day == 29)
                {
                    tomorrow.day = 29;
                    tomorrow.month = value.month;
                    tomorrow.year = value.year;
                }
                else
                {
                    tomorrow.month = value.month + 1;
                    tomorrow.year = value.year;
                }
            }
            else
            {
                tomorrow.month = value.month + 1;
                tomorrow.year = value.year;
            }
        }
        // ...if any other month.
        else
        {
            tomorrow.month = value.month + 1;
            tomorrow.year = value.year;
        }
    }
    else
    {
        tomorrow.day = value.day;
        tomorrow.month = value.month;
        tomorrow.year = value.year;
    }

    return tomorrow;
}
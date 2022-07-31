/**
 * 05_structures_containing_structures.c
 *
 * Friday, July 29 2022 12:39hrs
 *
 * This program illustrates how a structure
 * can have other structures as its members.
 */
#include <stdio.h>

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
void print_date_time(struct date_time value);

int main(void)
{
    // Structure declaration
    struct date_time event = { {12, 44, 01}, {07, 29, 2022}};

    // Prints out the date and time
    print_date_time(event);

    // Updates the time by one second


    return 0;
}

/******************************************
 * print_date_time()
 */
void print_date_time(struct date_time value)
{
    printf("%.2i.%.2i.%.2i\n%.2i:%.2i:%.2i\n", value.sdate.month, value.sdate.day, value.sdate.year % 100 \
    , value.stime.hours, value.stime.minutes, value.stime.seconds);
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
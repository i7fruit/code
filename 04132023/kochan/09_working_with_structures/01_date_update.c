/** 
 * 01_date_update_0.c
 * 
 * Sunday, July 24 2022 21:39hrs
 * 
 * This program updates the value of a given
 * date by one day, and prints the updated
 * date to standard output.
 */
#include <stdio.h>
#include <stdbool.h>

// Struct definition
struct date
{
    int month;
    int day;
    int year;
};

// Function definition
int get_integer(void);
bool is_leap_year(int year);
int number_of_days(struct date value);
struct date get_date(void);
struct date date_update(struct date value);

int main(void)
{
    struct date today, tomorrow;

    // Prompts user to enter a date
    today = get_date();

    // Prints the date entered by user
    printf("Today is %.2i.%.2i.%.2i\n", today.month, today.day, today.year % 100);

    tomorrow = date_update(today);

    // Prints updated date
    printf("Tomorrow is %.2i.%.2i.%.2i\n", tomorrow.month, tomorrow.day, tomorrow.year % 100);

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
/**
 * 00_days_between_dates.c
 *
 * Tuesday, August 02 2022 12:38hrs
 *
 * This program uses a formula to calculate
 * the number of days between two dates.
 *
 * The value of "N" is calculated for each date:
 *
 *     N = 1461 * f(year,month) / 4 + 153 * g(month) / 5 + day
 *
 * after which the difference between both values are returned as
 * the number of days between the two dates.
 *
 * The formula above works for dates after March 01 1900.
 *
 * 1 should be added to the value of N for dates between
 * March 01 1800 and February 28 1900
 *
 * 2 should be added to the value of N for dates between
 * March 01 1700 and February 28 1800.
 */
#include <stdio.h>

#define SEVENTEEN_HUNDRED 1700
#define EIGHTEEN_HUNDRED 1800
#define NINETEEN_HUNDRED 1900
#define FEBRUARY 2
#define MARCH 3

// Structure definition
struct date
{
    int month;
    int day;
    int year;
};

// Function prototypes
int get_integer(void);
struct date get_date(void);
void print_date(struct date value);
int N(struct date value);

int main(void)
{
    // Structure declaration
    struct date first_date, second_date;

    printf("Enter any dates from March 01 1700\n\n");

    do
    {
        printf("First date\n");
        first_date = get_date();
    }
    while (first_date.year <= SEVENTEEN_HUNDRED && first_date.month <= FEBRUARY);
    putchar('\n');

    do
    {
        printf("Second date\n");
        second_date = get_date();
    }
    while (second_date.year <= SEVENTEEN_HUNDRED && second_date.month <= FEBRUARY);
    putchar('\n');

    print_date(first_date);
    print_date(second_date);

    // Computes N values for each date
    int n0 = N(first_date);
    int n1 = N(second_date);

    int days = n1 - n0;

    printf("%i days.\n", days);

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

/********************************************************************
 * print_date()
 */
void print_date(struct date value)
{
    printf("%.2i.%.2i.%.2i\n", value.month, value.day, value.year % 100);
}

/********************************************************************
 * N()
 */
int N(struct date value)
{
    int n = 0;

    if (value.month <= 2)
    {
        value.year--;
        value.month += 13;
    }

    else
        value.month++;

    n = 1461 * value.year / 4 + 153 * value.month / 5 + value.day;

    // Adds 1 or 2 to the value of n
    if ((value.month >= MARCH && value.year >= EIGHTEEN_HUNDRED) && (value.month <= FEBRUARY && value.year <= NINETEEN_HUNDRED))
        n++;

    else if ((value.month >= MARCH && value.year >= SEVENTEEN_HUNDRED) && (value.month <= FEBRUARY && value.year <= EIGHTEEN_HUNDRED))
        n += 2;

    return n;
}
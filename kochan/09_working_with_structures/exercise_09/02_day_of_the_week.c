/**
 * 02_day_of_the_week.c
 *
 * Tuesday, August 09 2022 16:21hrs
 *
 * This program uses prompts the user for a date and
 * output what day of the week that date falls into.
 *
 * The value of "N" is calculated for the date:
 *
 *     N = 1461 * f(year,month) / 4 + 153 * g(month) / 5 + day
 *
 * after which 621,049 is subtracted from the value of N to get a
 * Result. Finally, that Result modulo 7, will give a number from
 * 0 to 6 which represents a day of the week from Sunday 0, to
 * Saturday 6.
 *
 * The formula for N above works for dates after March 01 1900.
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
int get_day(int n);

int main(void)
{
    // Structure declaration
    struct date user_date;

    printf("\nEnter any dates from March 01 1700\n\n");

    do
    {
        user_date = get_date();
    }
    while (user_date.year <= SEVENTEEN_HUNDRED && user_date.month <= FEBRUARY);
    putchar('\n');

    // Computes N value for the date
    int n = N(user_date);

    int day = get_day(n);

    // Prints day of the week
    switch (day)
    {
        case 0:
            printf("Sunday ");
            break;

        case 1:
            printf("Monday ");
            break;

        case 2:
            printf("Tuesday ");
            break;

        case 3:
            printf("Wednesday ");
            break;

        case 4:
            printf("Thursday ");
            break;

        case 5:
            printf("Friday ");
            break;

        case 6:
            printf("Saturday ");
            break;
    
        default:
            break;
    }

    print_date(user_date);

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

/********************************************************************
 * get_day()
 */
int get_day(int n)
{
    const int value = 621049, seven = 7;

    // Subtracts 621,049 from the value of n and modulo divides result by 7
    return (n - value) % seven;
}
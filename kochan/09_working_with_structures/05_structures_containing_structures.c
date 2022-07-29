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

int main(void)
{
    // Structure declaration
    struct date_time event = { {12, 44, 01}, {07, 29, 2022}};

    // Prints out the date and time
    printf("%.2i.%.2i.%.2i\n%.2i:%.2i:%.2i\n", event.sdate.month, event.sdate.day, event.sdate.year % 100 \
    , event.stime.hours, event.stime.minutes, event.stime.seconds);

    return 0;
}
/**
 * 01_average.c
 *
 * Monday, May 30 2022 22:51hrs
 *
 * This program calculates the average of a
 * set of grades while keeping track of the
 * number of failing grades. Grades less than
 * 65 are considered failing grades.
 */
#include <stdio.h>
#define LIMIT 65

int main(void)
{
    unsigned short number_of_grades = 0, total = 0, fail_counter = 0,
    grade = 0;
    float average = 0;

    printf("How many grades to you wish to enter? ");
    scanf("%hu", &number_of_grades);

    for (short i = 0; i < number_of_grades; i++)
    {
        printf("Enter grade %i: ", i + 1);
        scanf("%hu", &grade);

        // Checks if passing grade
        if (grade < LIMIT)
            fail_counter++;

    // Updates total
    total += grade;
    }

    // Computes average
    average = (float)total / number_of_grades;

    printf("\nAverage grade: %.2f\n", average);
    printf("Failing grades: %hu\n", fail_counter);

    return 0;
}
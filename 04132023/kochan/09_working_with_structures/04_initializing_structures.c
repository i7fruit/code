/**
 * 04_initializing_structures.c
 *
 * Friday, July 29 2022 12:26hrs
 *
 * This program illustrates how structures
 * in C can be initialized.
 */
#include <stdio.h>

// Structure definition
struct person
{
    int age;
    float height;
    int weight;
};

int main(void)
{
    // Structure declaration
    struct person sam = {26, 1.45, 126}, emi;
    printf("Sam is %i years old, %.2fm tall, and weighs %ilbs.\n", sam.age, sam.height, sam.weight);

    // Using member names in any order
    struct person asata = {.height = 1.68, .weight = 170, .age = 25};
    printf("Asata is %i years old, %.2fm tall, and weighs %ilbs.\n", asata.age, asata.height, asata.weight);

    // Using compound litterals. This can appear anywhere in the program
    emi = (struct person) {22, 1.39, 130};
    printf("Emi is %i years old, %.2fm tall, and weighs %ilbs.\n", emi.age, emi.height, emi.weight);

    return 0;
}
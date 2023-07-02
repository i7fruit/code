#include <stdio.h>

//void print(int *arr[], int n)
//{
//    for (int i = 0; i < n; i++)
//        printf("%i ", (arr + i));
//}

int main(void)
{
    int values[] = {1, 2, 3};
    int *ptr = values;

    printf("%i ", *ptr);

    return 0;
}
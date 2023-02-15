#include <stdio.h>

int main(void)
{
    int size = 7;

    int arr[] = {1, 129, 4, 3, 2, 5, 0};

    for (int i = 0; i < size; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    for (int k = 0; k < size; k++)
        printf("%i ", arr[k]);
}
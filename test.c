#include <stdio.h>

int main(void)
{
    int arr[] = {1, 4, 3, 2, 5};

    for (int i = 0, j = 1; i < 5; i++, j = i + 1)
    {
        int min = i;

        for (; j < 5; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[j];
            arr[j] = temp;
        }
    }

    for (int k = 0; k < 5; k++)
        printf("%i ", arr[k]);
}
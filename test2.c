#include <stdio.h>

// Function prototypes
void sort(int arr[], int lo, int hi);
void merge(int arr[], int lo, int mid, int hi);

int main()
{
    int values[] = {-8, 8, 234, 8, 0, 19, 2, 7, 6, 21, 97, -738};

    int size = sizeof(values) / sizeof(values[0]);

    int lo = 0, hi = size - 1;

    sort(values, lo, hi);

    for (int i = 0; i < size; i++)
        printf("%i ", values[i]);

    putchar('\n');

    return 0;
}

void sort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        // Finds midpoint
        int mid = (lo + hi) / 2;

        // Sorts left half
        sort(arr, lo, mid);

        // Sorts right half
        sort(arr, (mid + 1), hi);

        merge(arr, lo, mid, hi);
    }
}

void merge(int arr[], int lo, int mid, int hi)
{
    // Computes sizes of subarrays
    int nl = (mid + 1) - lo;
    int nr = hi - mid;

    // Creates subarrays
    int lft_arr[nl];
    int rgt_arr[nr];

    // Populates subarrays
    for (int i = 0; i < nl; i++)
        lft_arr[i] = arr[lo + i];

    for (int j = 0; j < nr; j++)
        rgt_arr[j] = arr[(mid + 1) + j];

    // Merges the subarrays
    int i = 0, j = 0, k = lo;

    while (i < nl && j < nr)
    {
        if (lft_arr[i] < rgt_arr[j])
        {
            arr[k] = lft_arr[i];
            i++;
        }
        else if (rgt_arr[j] < lft_arr[i])
        {
            arr[k] = rgt_arr[j];
            j++;
        }
        k++;
    }

    // Append what's left
    while (i < nl)
    {
        arr[k] = lft_arr[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        arr[k] = rgt_arr[j];
        j++;
        k++;
    }
}
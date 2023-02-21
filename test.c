#include <stdio.h>

// Function prototypes
void sort(int arr[], int lo, int hi);
void merge(int arr[], int lo, int mid, int hi);

int main(void)
{
    int size = 7;

    int arr[] = {1, 129, 4, 3, 2, 5, 0};

    // Declares lowest and highest indices
    int start = 0, end = size - 1;

    sort(arr, start, end);

    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);

    return 0;
}

// sort
void sort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        // Finds mid point
        int mid = (lo + hi) / 2;

        // Sorts left half
        sort(arr, lo, mid);

        // Sorts right half
        sort(arr, (mid + 1), hi);

        // Merge subarrays
        merge(arr, lo, mid, hi);
    }
}

// merge
void merge(int arr[], int lo, int mid, int hi)
{
    // Computes size of subarrays
    int size_lft_array = (mid + 1) - lo;
    int size_rgt_array = hi - mid;

    // Declares subarrays
    char lft_array[size_lft_array];
    char rgt_array[size_rgt_array];

    // Populates both subarrays
    for (int i = 0; i < size_lft_array; i++)
        lft_array[i] = arr[lo + i];

    for (int j = 0; j < size_rgt_array; j++)
        rgt_array[j] = arr[(mid + 1) + j];

    // Merges the subarrays
    int i = 0, j = 0, k = lo;
    while (i < size_lft_array && j < size_rgt_array)
    {
        if (lft_array[i] < rgt_array[j])
        {
            arr[k] = lft_array[i];
            i++;
            k++;
        }
        else if (rgt_array[j] < lft_array[i])
        {
            arr[k] = rgt_array[j];
            j++;
            k++;
        }
    }

    // Adds whatever's left
    while (i < size_lft_array)
    {
        arr[k] = lft_array[i];
        i++;
        k++;
    }

    while (j < size_rgt_array)
    {
        arr[k] = rgt_array[j];
        j++;
        k++;
    }
}
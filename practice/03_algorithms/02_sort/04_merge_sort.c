/**
 * 04_merge_sort.c
 *
 * Saturday, February 18 2023 18:47hrs
 *
 * This program sorts an array of integers
 * by recursively splitting the array and
 * sorting its resulting subarrays until
 * each subarray contains only one element,
 * after which it merges them in ascending
 * or decending order
*/
#include <stdio.h>

int main(void)
{
    // Array size
    int size = 7;

    int arr[] = {1, 129, 4, 3, 2, 5, 0};

    // Computes lowest and highest indices
    int lo = 0, hi = size - 1;

    sort(arr, lo, hi);

    return 0;
}

/********************************************************
 * This sort function takes an array of type int,
 * and two integers. It first finds the midpoint
 * of the array if its elements exceed one, then
 * it calls itself to sort the corresponding subarrays.
 * After the subarrays are sorted, it calls on the
 * merge function to combine the subarrays into a
 * fully sorted array.
 */
void sort(int arr[], int lo, int hi)
{
    /**
     * If the array size is greater than 1 ie if starting index is lower than
     * ending index, it proceeds to find its midpoint
    */
    if (lo < hi)
    {
        // Finds mid point of the array
        int mid = (lo + hi) / 2;

        // Sorts the left part of the subarray
        sort(arr, lo, mid);

        // Sorts the right part of the subarray
        sort(arr, (mid + 1), hi);

        // Merges both subarrays
        merge(arr, lo, mid, hi);
    }
}

//
void merge(int arr[], int lo, int mid, int hi)
{
    
}
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

// Function prototypes
void sort(int arr[], int lo, int hi);
void merge(int arr[], int lo, int mid, int hi);

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

 /********************************************************
  * The merge function takes in an array, and three
  * integers. It compares the values of the elements
  * in the arrays it's merging and sorts them in
  * ascending or decending order.
  */
void merge(int arr[], int lo, int mid, int hi)
{
    // Computes the sizes of both subarrays
    int size_left_subarray = mid - lo + 1;
    int size_right_subarray = hi - mid;

    // Creates temporary arrays to store subarrays
    int left_subarray[size_left_subarray];
    int right_subarray[size_right_subarray];

    // Initializes the subarrays
    int i = 0, j = 0, k = 0;

    for (; i < size_left_subarray; i++)
        left_subarray[i] = arr[lo + i];

    for (k = mid + 1; j < size_right_subarray; j++)
        right_subarray[j] = arr[k + j];

    /**
     * Merges both arrays into a sorted order
     */
    // Resets indices of both subarrays
    i = 0, j = 0, k = 0;

    // While both arrays have not been completely iterated through...
    while (i < size_left_subarray && j < size_right_subarray)
    {
        // Compare values in elements of each subarray
        if (left_subarray[i] < right_subarray[j])
        {
            arr[k] = left_subarray[i];
            i++; k++;
        }

        else if (right_subarray[j] < left_subarray[i])
        {
            arr[k] = right_subarray[j];
            j++; k++;
        }
    }

    // Appends what's left from each subarray if any
    while (i < size_left_subarray)
    {
        arr[k] = left_subarray[i]; i++; k++;
    }

    while (j < size_right_subarray)
    {
        arr[k] = right_subarray[j]; j++; k++;
    }
}
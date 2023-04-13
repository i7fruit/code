/*
 * binary.c
 *
 * This algorith searches for a specific
 * item by using a divide and conquer approach.
 * It finds the mid-point of an array and makes
 * comparisons as to what half the item is likely
 * to be located, if the item exits in the array
 * in the first place
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 
 #define SIZE 5
 
 void merge(int Arr[], int l, int mid, int h);
 void sort(int A[], int l, int h);
 int binary(int Array[], int low, int high, int x);
 
 int main(void)
 {
     // Declares and initializes and array
     int list[SIZE] = {8, 3, 9, 12, 0};
     int nmb0;
     
     // Finds the highest and lowest indices
     int low = 0, high = SIZE - 1;
     
     // Calls the sort function to sort the array
     sort(list, low, high);
     
     // Prints the array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", list[i]);
     }
     
     printf("\n");
     
     // Searches for a specific number
     printf("What number do you want?\n");
     scanf("%i", &nmb0);
     
     binary(list, low, high, nmb0);
     
     return 0;
 }
 
 // Merge function
 void merge(int Arr[], int l, int mid, int h)
 {
     // First determines the sizes of the subarrays
     int nl = (mid - l) + 1;
     int nr = h - mid;
     
     // Creates temporary arrays
     int left_arr[nl], right_arr[nr];
     
     // Initializes both sub-arrays
     for (int i = 0; i < nl; i++)
     {
         left_arr[i] = Arr[l + i];
     }
     
     for (int j = 0; j < nr; j++)
     {
         right_arr[j] = Arr[(mid + 1) + j];
     }
     
     int i = 0, j = 0, k = l; // Sets k to the lowest index
     
     // Merges the arrays
     while (i < nl && j < nr)
     {
         if (left_arr[i] <= right_arr[j])
         {
             Arr[k] = left_arr[i];
             i++;
         }
         
         else
         {
             Arr[k] = right_arr[j];
             j++;
         }
         
         k++;
     }
     
     // Appends whatever's left
     while (i < nl)
     {
         Arr[k] = left_arr[i];
         i++;
         k++;
     }
     
     while (j < nr)
     {
         Arr[k] = right_arr[j];
         j++;
         k++;
     }
 }
 
 // Sort function
 void sort(int A[], int l, int h)
 {
     if (l < h)
     {
         // Finds mid-point
         int mid = (l + h) / 2;
         
         // Sorts left half
         sort(A, l, mid);
         
         // Sorts right half
         sort(A, (mid + 1), h);
         
         // Merges the halves
         merge(A, l, mid, h);
     }
 }
 
 // Binary search
 int binary(int Array[], int low, int high, int x)
 {
     // Finds mid-point
     if (low <= high)
     {
         int mid = (low + high) / 2;
     
         if (Array[mid] == x)
         {
             printf("Number was found\n");
             return true;
         }
         
         else if (x < Array[mid])
         {
             // Changes highest index
             high = mid - 1;
             binary(Array, low, high, x);
         }
     
         else if (x > Array[mid])
         {
             low = mid + 1;
             binary(Array, low, high, x);
         }
     }
     
     else
     {
         printf("Number wasn't found\n");
     }
     
     return false;
 }
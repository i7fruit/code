/*
 * merge.c
 *
 * This program sorts an array of integers
 * by recursively splitting the array and
 * sorting its resulting subarrays until
 * each subarray contains only one element,
 * after which it merges them in ascending
 * or decending order
 *
 * The user is required to enter the size
 * of the array at the command line for argv[1]
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 
 void merge(int Arr[], int l, int mid, int r);
 void sort(int A[], int l, int r);
 
 int main(int argc, string argv[])
 {
     if (argc != 2)
     {
         // Prints warning
         printf("Command line argument required\nE.g:\"./program_name argument\"\n");
         exit(1);
     }
     
     // Prints the size of the array
     int size = atoi(argv[1]);
     printf("Enter an array of size %i\n", size);
      
     
     // Declares an array
     int Array[size];
     
     // Prompts the user for input
     for (int i = 0; i < size; i++)
     {
         printf("Enter an integer\n");
         Array[i] = get_int();
     }
     
     printf("\n");
     
     // Prints the unsorted array
     for (int i = 0; i < size; i++)
     {
         printf("%i ", Array[i]);
     }
     
     printf("\n");
     
     // Determines the indices
     int low = (size - size);
     int high = (size - 1);
     
     sort(Array, low, high);
     
     // Prints sorted array
     for (int i = 0; i < size; i++)
     {
         printf("%i ", Array[i]);
     }
     
     putchar('\n');
     
     return 0;
 }
 
 /*
  * The merge function takes in an array, and three
  * integers. It compares the values of the elements
  * in the arrays it's merging and sorts them in
  * ascending or decending order.
  */
  
  void merge(int Arr[], int l, int mid, int r)
  {
      // Determines the sizes of the subarrays to be merged
      int nl = (mid - l) + 1; // Size of left subarray
      int nr = (r - mid); // Size of left subarray
      
      // Declares temporary arrays
      int left[nl], right[nr];
     
      // Initializes the arrays
      for (int i = 0; i < nl; i++)
      {
          left[i] = Arr[l + i];
      }
      
      for (int j = 0; j < nr; j++)
      {
          right[j] = Arr[(mid + 1) + j];
      }
      
      
      
      // Initializes counting variables
      int i = 0, j = 0, k = l;
      
      // Merges the subarray
      while (i < nl && j < nr)
      {
          if (left[i] <= right[j])
          {
              Arr[k] = left[i];
              i++;
          }
          
          else
          {
              Arr[k] = right[j];
              j++;
          }
          k++;
      }
      
      // Appends whatever is left in both subarrays
      while (i < nl)
      {
          Arr[k] = left[i];
          i++;
          k++;
      }
      
      while (j < nr)
      {
          Arr[k] = right[j];
          j++;
          k++;
      }
  }
 
 /*
  * This sort function takes an array of type int,
  * and two integers. It first finds the midpoint
  * of the array if its elements exceed one, then
  * it calls itself to sort the corresponding subarrays.
  * After the subarrays are sorted, it calls on the
  * merge function to combine the subarrays into a
  * fully sorted array.
  */
  
  void sort(int A[], int l, int r)
  {
      // Checks if left index is lower than the right index
      if (l < r)
      {
          // Finds the midpoint of the array
          int mid = (l + r) / 2;
          
          // Calls itself to sort the left subarray
          sort(A, l, mid);
          
          // Calls itself to sort the right subarray
          sort(A, (mid + 1), r);
          
          // Calls the merge function to merge the arrays
          merge(A, l, mid, r);
      }
  }
#include <stdio.h>

int main(void)
{
    short values[] = {0, 1, 3, 5, 90};
    short start = 0, end = sizeof(values) / sizeof(values[0]);

    short search_val = 0;
    printf("What value do you want to search for? ");
    scanf("%hi", &search_val);

    while (start < end)
    {
        // Finds mindpoint of array
        short mid = (start + end) / 2;

        // Returns if value found
        if (values[mid] == search_val)
        {
            printf("%hi found\n", search_val);
            return 0;
        }
        // Adjusts end value if mid value is lower
        else if (values[mid] < search_val)
        {
            start = mid + 1;
        }
        // Adjusts start value if mid is higher
        else
        {
            end = mid - 1;
        }
    }

    printf("%hi not found\n", search_val);
    return 1;
}
#include <stdio.h>

int main(void)
{
    const int size = 64;
    char string0[size] = "Hi";
    char string1[size] = "Hi";

    int i = 0;

    while (string0[i] == string1[i]) 
        i++;

    if (string0[i] == string1[i])
        printf("Both text are the same.\n");

    else if (string0[i] < string1[i])
        printf("%s comes before %s\n", string0, string1);

    else
        printf("%s comes before %s\n", string1, string0);

    return 0;

}
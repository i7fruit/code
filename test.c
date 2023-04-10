#include <stdio.h>
#include <limits.h>

int main(void)
{
    char *string = "Constant string.";

    *string = "New";

    printf("%s\n", string);

    return 0;
}
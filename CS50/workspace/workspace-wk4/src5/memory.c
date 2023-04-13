// http://valgrind.org/docs/manual/quick-start.html#quick-start.prepare

#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    x[10] = 0; // Trying to access memory that I shouldn't
}

// Did not deallocate memory assigned to pointer x

int main(void)
{
    f();
    return 0;
}

// NOTE: You can type !va or !val at the terminal to rerun valgrind

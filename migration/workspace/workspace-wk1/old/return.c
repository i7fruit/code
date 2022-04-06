#include <stdio.h>
#include <cs50.h>

int square(int name); /* This is the prototype or
                       * signature of the function */
int main(void)
{
   /* Prompt the user for imput */

    printf("Enter a number to find");
    printf(" its square:\n");
    
        int x = GetInt();
        
    /* Display the result to the
     * standard output device. */
        
    printf("%i^2 is %i\n", x, square(x));   
}

/* Define a square function */

int square(int name)
{
    /* 
     * The function returns the result
     * of name times name
     */
    
    return name * name;
    
    /* 
     * ALTERNATIVELY CAN DO THIS:
     * 
     * int y = name * name;
     * return y;
     *
     * BUT IT'S BAD DESIGN TO DECLARE A
     * VARIABLE ONLY TO IMMEDIATELY RETURN
     * IT IN A FOLLOWING LINE. */
}

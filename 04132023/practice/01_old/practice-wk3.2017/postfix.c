/**
 * semicolon on the while
 */

 #include <stdio.h>

 int main(void)
 {
     int var = 2;

     /**
      * Prints H twice while expression
      * evaluates to true, and a third H
      * as program reads printf before
      * evaluating to false
      */

     while (printf("H ") && var--);

     return 0;
 }
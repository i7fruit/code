/**
 * scanf_0.c
 *
 * Friday, 06.29.18 19:05hrs
 */

 #include <stdio.h>

 int main(void)
 {
     short x;

     printf("x: ");
     scanf("%hi", &x);

     printf("x = %hi", x);

     putchar('\n');

     return 0;
 }
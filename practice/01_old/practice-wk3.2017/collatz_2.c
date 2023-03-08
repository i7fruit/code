/**
 * collatz_2.c
 */

 #include <stdio.h>
 #include <cs50.h>

 int collatz(int x);

 int main(void)
 {
     // Prompts user for input
     printf("Enter an integer: \n");
     int i = get_int();

     printf("%i Step%s\n", collatz(i), (collatz(i) > 1)? ("s.") : ("."));

     return 0;
 }

 /**
  * The collatz function takes an integer
  * and works some arithmetic on it till it
  * gives the value one. If the integer is even,
  * it recursively divides the number by 2, if odd,
  * it multiplies the number by 3 and adds 1 to the
  * product. If the integer is 1, it simply returns 1
  */

  int collatz(int x)
  {
      //Tracks the number of steps taken to get back to 1
      static int c = 0;

      if (x == 1)
          return c;

      else if (x % 2 == 0)
           {
              c++;
              return collatz(x / 2);
           }

      else
      {
          c++;
          return collatz(3 * x + 1);
      }
  }
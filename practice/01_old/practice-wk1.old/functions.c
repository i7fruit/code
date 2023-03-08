#include <stdio.h>
#include <cs50.h>

void print_name(string name, int n); /* Prototype or Signature of the fnctn*/

int main(void)
{ 
    printf("What is your first name?\n");
    string s = GetString();  /* Declares a string called "s" */
    
    printf("How old are you?\n");
    int n = GetInt();
    print_name(s, n); /* Calls the function that I defined */
}

/* Define my own function of print_name
 * outside of the Main function. It takes
 * a string data type and returns nothing,
 * hence the void return type. */
 
 void print_name(string name, int n)
 {
    printf("Hi, %s, you are %i years old.\n", name, n);
 }

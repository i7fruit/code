#include <stdio.h>
#include <cs50.h>

void print_name(string name); /* Prototype or Signature of the fnctn*/

int main(void)
{ 
    printf("Give me a string\n");
    string s = get_string();  /* Declare a string called "s" */
    
    print_name(s); /* Calls the function that I defined */
}

/* Define my own function of print_name
 * outside of the Main function. It takes
 * a string data type and returns nothing,
 * hence the void return type. */
 
 void print_name(string name)
 {
    printf("Hi, %s.\n", name);
 }

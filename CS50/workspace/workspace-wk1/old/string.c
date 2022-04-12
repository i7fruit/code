#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("What is your name?\n");
    string name = GetString();
    printf("My name is %s.\n", name);
    
}

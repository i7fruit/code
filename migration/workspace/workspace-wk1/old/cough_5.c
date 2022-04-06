#include <stdio.h>
#include <cs50.h>

void cough(int n);
void say(string s, int n);
int main(void)
{
    cough(2);   
}

// This calls the say function
void cough(int n)
{
    say("Cough", n);
}

/*
 * This function says a string
 * a specific number of times
 */
 
void say(string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", s);
    }
}

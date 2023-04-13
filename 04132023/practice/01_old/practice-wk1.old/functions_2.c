#include <stdio.h>
#include <cs50.h>

void cough(int n);
void say(string s, int n);

int main(void)
{
    printf("Enter an integer: ");
    int n = GetInt();
    //cough(n);
    
    printf("What's your name?\n");
    string s = GetString();
    
    say(s, n);
}

/*void cough(int n)
{
    say("cough", n);
}*/

void say(string s, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s ", s);
    }
}

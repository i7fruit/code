#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("What is your score? ");
    float score = GetFloat();
    
    if(score > 90.0)
    {
        printf("You have a grade of \"A+\".\n");
    }
    
    if((score >= 80.0) && (score <= 90.0))
    {
        printf("You have a grade of \"A\".\n");
    }
    
    if((score >= 70.0) && (score < 80.0))
    {
        printf("You have a grade of \"A-\".\n");
    }
    
    if((score >= 60.0) && (score < 70.0))
    {
        printf("You have a grade of \"B\".\n");
    }
    
    if((score >= 50.0) && (score < 60.0))
    {
        printf("You have a grade of \"C\".\n");
    }
    
    if((score >= 40.0) && (score < 50.0))
    {
        printf("You have a grade of\"D\".\n");
    }
    
    if(score < 40)
    {
        printf("Hell, Dude, an \"F\"?.\n");
    }
}

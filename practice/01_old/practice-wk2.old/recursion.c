/*
 * recursion.c
 * 06.20.17
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 void func(string s);
 
 int main(void)
 {
     printf("Enter string\n");
     string str = get_string();
     
     for (int i = 0; i < 5; i++)
     {
         func(str);
     }
 }
 
 /*
  * The func function will print a string
  * and then call itself--indefinitely
  */
 void func(string s)
 {
     printf("Hello, %s\n", s);
     func(s);
 }
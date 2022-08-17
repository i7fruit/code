///**
// * 05_getchar.c
// *
// * Friday, August 12 2022 22:18hrs
// *
// * This program illustrates the use
// * of the getchar function by using
// * it to read a string of text from
// * standard input.
// */
//#include <stdio.h>

//// Function prototype
//void readline(char arr[], int limit);
//void print_array(char arr[]);

//int main(void)
//{
//    const short size = 20, frequency = 3;

//    // An array to store text read from the keyboard
//    char buffer[size];

//    // Reads input from the user three times
//    for (short i = 0; i < frequency; i++)
//    {
//        printf("Enter a string of text\n");
//        readline(buffer, size - 1);
//        print_array(buffer);
//        printf("\n\n");

//        // Clears the buffer
//        for (short j = 0; j < size; j++)
//            buffer[j] = '\0';
//    }

//    return 0;
//}

///****************************************************
// * print_array()
// */
//void print_array(char arr[])
//{
//    for (short i = 0; arr[i] != '\0'; i++)
//        printf("%c", arr[i]);
//}

///****************************************************
// * The readline() function takes a character array
// * to store the string captured from standard input,
// * and a second argument of an integer value representing
// * the number of characters the user is limited to storing
// * in the array. This way the user does not exceed the buffer.
// */
//void readline(char arr[], int limit)
//{
//    short i = -1;

//    do
//    {
//        arr[++i] = getchar();
//    }
//    while (arr[i] != '\n' && i != limit);

//    // Overwrites '\n' with '\0'
//    arr[i] = '\0';
//}

#include <stdio.h>
int main (void) {
int i;
char line[81];
void readLine (char buffer[]);
for ( i = 0; i < 3; ++i ) {
readLine (line);
printf ("%s\n\n", line); }
return 0; }
// Function to read a line of text from the terminal
void readLine (char buffer[]) {
char character; int i=0;
do {
}
while ( character != '\n' );
buffer[i - 1] = '\0'; }
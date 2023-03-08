/*
 * This program uses Luhn's Algorithm
 * to check if the credit card number
 * entered by a user is valid or not.
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 
 int main(void)
 {
     /* 
      * Prompts the user for a credit
      * card number.
      */
     
     long long cc_number;
     
     do
     {
         printf("Number: ");
         cc_number = GetLongLong();
     }
     while ((cc_number < 1000000000000) || (cc_number > 9999999999999999));
     
    /*
     * Determines the length of the card number.
     * copy_ccnmbr is a copy of the credit card
     * number used to determine the length so that
     * the original number is not modified.
     */
    
    long long length = 0;
    long long copy_ccnmbr = cc_number;
    long long a, b, c, d;
    
    while (copy_ccnmbr != 0)
    {
        copy_ccnmbr /= 10;
        length++;
        
         /* pick 13th, 14th, 15th, and 16th digits */
        if (length == 13)
        {
            d = ((copy_ccnmbr / 10000000000000) % 10);
        }
        if (length == 14)
        {
            c = ((copy_ccnmbr / 100000000000000) % 10);
        }
        if (length == 15)
        {
            b = ((copy_ccnmbr / 1000000000000000) % 10);
        }
        if (length == 16)
        {
            a = ((copy_ccnmbr / 10000000000000000) % 10);
        }
    }
    printf("%lli\n", b);
    
    if (((length == 13) && (d == 4)) || ((length == 16) && (d == 4)))
        {
            printf("Visa Card\n");
        }
        if (((length == 15) && ((b == 3) && (c == 4))) && ((length == 15) && ((b == 3) && (c == 7))))
        {
            printf("American Express Card\n");
        }    
    
    /* Calculate the checksum of the card */
    
    long long i = 0, j = 0, x = 0, y = 0;
    long long total = 0;
    
    
    for (i = 1, j = 1; i <= length; i++, j = j * 10)
    {
        if ((i % 2) == 0)
        {
            x = ((cc_number / j) % 10);
            y = x * 2;
            
            if (y > 9)
            {
                total = total + (y / 10) + (y % 10);
                x = 0;
            }
            else
            {
                total = total + y;
                x = 0;
            }
        }
        else
        {
            x = ((cc_number / j) % 10);
            total = total + x;
            x = 0;
        }
        
    }
    printf("%lli\n",total);
 }

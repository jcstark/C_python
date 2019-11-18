#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    // Ask for the card number.
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < (long) pow(10,12));
    
    int check;
    int front = 0;
    for (int i = 1; i <= 16; i += 1)
    {
        // Sum of the numbers multiplied by 2.
        if (i % 2 == 0)
        {
            int a = (number % (long) pow(10, i)) / (long) pow(10, i - 1);
            int b = 2 * a;
            if (b >= 10)
            {
                b = 1 + b % 10;
            }
            check = check + b;       
        }
        // Sum to the previous sum the sum of the other numbers.
        else if (i % 2 == 1)
        {
            int c = (number % (long) pow(10, i)) / (long) pow(10, i - 1);
            check = check + c; 
        }        
    }
 
    // Calculate of the two leading digits of the number. 
    int dec = 0;
    int i = 16;
    do
    {
        dec = number / (long) pow(10, i);
        if (dec != 0)
        {
            int unit = number % (long) pow(10, i) / (long) pow(10, i - 1);
            front = dec * 10 + unit; 
            break;         
        }
        i--;
    }
    while (dec == 0);

    // Perform the 10module of the checknum.
    check = check % 10;
    
    // Check if the module of is 0 and the characteristics of all different cards.
    if (check == 0 && number > pow(10, 14) && number < pow(10, 15) && (front == 34 || front == 37))
    {
            printf("AMEX\n");
    }
    else if (check == 0 && number > pow(10, 15) && number < pow(10, 16) && front >= 51 && front <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (check == 0  && number > pow(10, 12) && number < pow(10, 16) && front >= 40 && front < 50)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }  
}
    

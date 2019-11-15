#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Ask for the amount of change that must be given
    // by the cashier until it is greater or equal than 0.
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    
    // Convert the amount of money from dollars to cents.
    int cents = round(change*100);
 
    // Calculate the minimum number of coins to represent this amount.
    int n = cents/25;
    if (cents % 25 != 0)
    {
        n = n + (cents % 25)/10;
    }
    if ((cents % 25)%10 != 0)
    {
        n = n + ((cents % 25) % 10)/5;
    }
    if (((cents % 25) % 10)%5 != 0) 
    {
        n = n + (((cents % 25) % 10) % 5);
    }
    
    // Print this number of coins.  
    printf("%i \n",n);
}

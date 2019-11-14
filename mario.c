#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;
    // Ask for the pyramid's height until the value = [1,8]
    do
    {
        Height = get_int("Height: ");
    }
    while (Height < 1 || Height > 8);
    // Print the pyramid
    for(int i = 1; i <= Height; i++)
    {
        for(int j = Height; j >= i + 1; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

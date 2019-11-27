#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    int n = strlen(argv[argc -1]);
    // Key validation.
    // Check if the number of inputs is not 1.
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    // Check if the input is alphabetical. 
    else
    {   
        for (int i = 0; i <= n - 1; i++)
        {
            int az_09 = isalpha(argv[argc - 1][i]);
            if (az_09 == 0)
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
            else
            {
                if (i >= n - 1)
                {
                    printf("Success\n"); 
                }
                continue;
            }
        }
    }
  
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int j = 0;
    for (int i = 0, m = strlen(plaintext); i < m; i++)
    {
    int key = shift(argv[1][j]);
    // For uppercase
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            if ((plaintext[i] + key) <= 90)
            {
                printf("%c", plaintext[i] + key);
            }
            else
            {
                int loop = (plaintext[i] + key) % 90;
                printf("%c", 64 + loop);  
            }
        }
        // For lower case
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            if ((plaintext[i] + key) >= 122)
            {
                int loop = (plaintext[i] + key) % 122;
                printf("%c", 96 + loop);
            }
            else 
            {
                printf("%c", plaintext[i] + key);
            }
        }         
        else
        {
            printf("%c", plaintext[i]);
        }
        if (isalpha(plaintext[i]) == 0)
        {
            j += 0;    
        }
        else
        {    
            if (j < n - 1)
            {
                j++;
            }
            else
            {
                j = 0;    
            }
        }
    }

    printf("\n");
}

int shift(char c)
{
    // if c is uppercase
    if (islower(c) == 0)
    {
        return c - 65;   
    }
    // if c is lowercase
    else
    {
        return c - 97;
    }
}

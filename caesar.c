#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Key validation.
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
    }
    
    int key = atoi(argv[argc - 1]);    
    if (argc == 2 && key > 0)
    {
        key %= 26;
        printf("Success\n%i\n", key);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // Ask for the original message.
    string plaintext = get_string("plaintext:  ");
    
    // Ciphering the message.
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
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
    }
    printf("\n");
}
    

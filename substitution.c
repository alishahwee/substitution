#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void encrypt_text(string plaintext, string key);

int main(int argc, string argv[]) // argv[1] should be the input key (case-insensitive).
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n"); // CLI should only have two arguments.
        return 1;
    }

    string key = argv[1];

    if (strlen(key) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int count = 0; // Count should be strlen(key) (26) after completed iteration.

    for (int i = 0; i < strlen(key); i++) // Loops 26 times.
    {

        for (int j = 0; j < strlen(key); j++) // Loop will count twice if there is a repeated char.
        {
            if (key[j] == key[i])
            {
                count++;
            }
        }

        if (isalpha(key[i]) == 0) // Key can only  have alphabetic characters.
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (count != strlen(key)) // If there is a repeated char, count will be more than strlen(key) (26).
    {
        printf("Key cannot contain duplicate characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    encrypt_text(plaintext, key);

    return 0;
}

void encrypt_text(string plaintext, string key)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        for (int j = 0; j < strlen(key); j++)
        {
            if (plaintext[i] == j + 'A') // First letter of key represented by 'A'.
            {
                printf("%c", toupper(key[j])); // If the position matches, print that corresponding letter in uppercase.
            }
            else if (plaintext[i] == j + 'A' + 32) // Convert key into lowercase for position matching.
            {
                printf("%c", tolower(key[j])); // Print the lowercase version if it matches.
            }
        }

        if (isalpha(plaintext[i]) == 0)
        {
            printf("%c", plaintext[i]); // Print commas, spaces, etc.
        }
    }

    printf("\n"); // New line before function ends.
}
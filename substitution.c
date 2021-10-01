#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //printf("%s", argv[0]);

    if (argc != 2)  //if command line argument is not equal to 2
    {
        printf("Usage: ./substitution key\n"); //print error message "Usage ./substitution" is commnand is not equal to 2
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    string plain;
    plain = get_string("plaintext:");
    printf("ciphertext:");
    for (int a = 0; a < strlen(plain); a++)
    {
        if (isupper(plain[a]))
        {
            int cq = plain[a] - 'A';
            char cipher = argv[1][cq];
            printf("%c", toupper(cipher));
        }
        else if (islower(plain[a]))
        {
            int cq = plain[a] - 'a';
            char cipher = argv[1][cq];
            printf("%c", tolower(cipher));
        }
        else
        {
            printf("%c", plain[a]);
        }
    }
    printf("\n");
}

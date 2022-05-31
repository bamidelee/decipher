#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sub(string text, string arg);

int main(int argc, string argv[])
{
    if (argc != 2) //checking if input not more than 2
    {
        printf("substitution key is just 1\n");
        return 1;
    }

    if (argv[1][26]) // checking if key is not more than 26
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++) // checking if keys are letters only
    {
        if ((argv[1][i] < 'a' || argv[1][i] > 'z') && (argv[1][i] < 'A' || argv[1][i] > 'Z'))
        {
            printf("Not all alphabet\n");
            return 1;
        }
    }
    for (int i = 0, b = 1; i < 25; i++, b++) // checking if letter not repeated in key
    {
        for (int j = i + 1; j < 26; j++) // looping thorugh the text to see if a  letter in the text is repeated in the rest of the text
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("letter repeated\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: "); // codllecting plain test to be encrypted
    printf("ciphertext: ");
    sub(plaintext, argv[1]); // printing ciphered text;
    return 0;
}

void sub(string text, string arg) // function to convert plaint text with key
{
    for (int i = 0; i < strlen(text); i++)
    {
        int l = 0;
        if (islower(text[i])) //checking if input is in lowercase so it can be converted in lower case with key
        {
            l += text[i] - 97;
            printf("%c", tolower(arg[l]));
        }
        else if (isupper(text[i])) // checking if input is higher case;
        {
            l += text[i] - 65;
            printf("%c", toupper(arg[l]));
        }
        else
        {
            printf("%c", text[i]); // printing back the text without encryprion if it is not an alphabet
        }
    }
    printf("\n");
}






//boiler plate
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //get key
    //must be 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //must be 26 length
    if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //must be all letters
    //no letters can be used twice
    string enteredString = argv[1];
    char key[26];

    bool alreadyUsed[26];
    for (int i = 0; i < 26; i++)
    {
        alreadyUsed[i] = false;
    }

    //checks that only letters are being used
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(enteredString[i]))
        {
            if (isupper(enteredString[i]))
            {
                if (alreadyUsed[enteredString[i] - 'A'] == true) //checks for duplicate letters
                {
                    printf("Key must not contain duplicate letters: %c\n", enteredString[i]); //prints the duplicate letter
                    return 1;
                }
                else
                {
                    alreadyUsed[enteredString[i] - 'A'] = true;
                    key[i] = enteredString[i] - 'A';
                }
            }
            else
            {
                //same as above but with  lower case letters
                if (alreadyUsed[enteredString[i] - 'a'] == true)
                {
                    printf("Key must not contain duplicate lettesr: %c\n", enteredString[i]);
                    return 1;
                }
                else
                {
                    alreadyUsed[enteredString[i] - 'a'] = true;
                    key[i] = enteredString[i] - 'a';
                }
            }
        }
        else
        {
            printf("Please use only letters\n");
            return 1;
        }
    }

    //now on to the cool part
    string plainText = get_string("plaintext: ");

    string cipherText = plainText;

    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                cipherText[i] = (key[plainText[i] - 'A'] + 'A');
            }
            else
            {
                cipherText[i] = (key[plainText[i] - 'a'] + 'a');
            }
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    printf("ciphertext: %s\n", cipherText);
    return 0;
}
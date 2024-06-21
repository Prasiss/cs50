#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool onlydigits(string name);
char rotatechar(char i, int k);

int main(int argc, string argv[])
{
    // Check for proper number of arguments
    if (argc != 2)
    {
        printf("Usage: ./cesar key\n");
        return 1;
    }

    bool result = onlydigits(argv[1]);
    if (result == false)
    {
        printf("Usage: ./cesar key\n");
        return 1;
    }

    string PlainText = get_string("Plain Text: ");
    int len = strlen(PlainText);
    char final[len + 1]; // +1 for the null terminator
    final[len] = '\0'; // Ensure the string is null-terminated

    int key = atoi(argv[1]);
    for (int i = 0; i < len; i++)
    {
        final[i] = rotatechar(PlainText[i], key);
    }

    printf("Cyphertext: %s\n", final);

    return 0;
}

bool onlydigits(string name)
{
    for (int l = 0, j = strlen(name); l < j; l++)
    {
        if (!isdigit(name[l]))
        {
            return false;
        }
    }
    return true;
}

char rotatechar(char c, int k)
{
    if (isupper(c))
    {
        return 'A' + (c - 'A' + k) % 26;
    }
    else if (islower(c))
    {
        return 'a' + (c - 'a' + k) % 26;
    }
    return c; // Non-alphabetic characters are returned unchanged
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool onlydigits(string name);
char rotatechar(char i, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    bool result = onlydigits(argv[1]);
    if (result == false)
    {
        printf("Usage: ./cesar key\n");
        return 1;
    }
    string PlainText = get_string("Plain Text: ");
    int j = strlen(PlainText);
    char final[j + 1];
    final[j] = '\0';
    int key = atoi(argv[1]);
    for (int i = 0; i < j; i++)
    {
        final[i] = rotatechar(PlainText[i], key);
    }

    printf("ciphertext: %s\n", final);
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
    return c;
}

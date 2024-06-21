#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
void spaces(int height);

int main(void)
{
    int height = get_int("Enter  a number: ");

    for (int j = 0; j < height; j++)
    {
        spaces(height - j - 1);
        pyramid(j + 1);
        printf(" ");
        pyramid(j + 1);
        printf("\n");
    }
}
void spaces(int height)
{
    for (int k = height; k > 0; k--)
    {
        printf(" ");
    }
}
void pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
}

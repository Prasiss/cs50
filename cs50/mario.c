#include <cs50.h>
#include <stdio.h>

void mainprymid(int height);
void leftprymid(int height, int line);
void rightprymid(int height, int line);

int main(void)
{
    int height;
    do {
        height = get_int("Enter the height of prymid: ");
    }
    while (height <= 0 || height > 8);
    mainprymid(height);

}

void mainprymid(int height)
{
    for (int i = 0; i < height; i++)
    {
        leftprymid(height, i);

        printf("  ");

        rightprymid(height, i);
    }
}

void rightprymid(int height, int line)
{
    for (int j = 0; j <= line; j++)
    {
        printf("#");
    }
    printf("\n");
}
void leftprymid(int height, int line)
{
    for (int k = line; k < height - 1; k++)
    {
        printf(" ");
    }
    for (int j = 0; j <= line; j++)
    {
        printf("#");
    }
}

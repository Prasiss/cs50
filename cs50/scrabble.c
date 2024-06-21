#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int pointcounter(string s);

int main(void)
{
    string word1 = get_string("Enter name: ");
    string word2 = get_string("Enter another name: ");

    int score1 = pointcounter(word1);
    int score2 = pointcounter(word2);

    if (score1 > score2)
    {
        printf(" Player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie\n");
    }
}

int pointcounter(string s)
{
    int score = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isupper(s[i]))
        {
            score += Points[s[i] - 'A'];
        }
        else if (islower(s[i]))
        {
            score += Points[s[i] - 'a'];
        }
    }
    return score;
}

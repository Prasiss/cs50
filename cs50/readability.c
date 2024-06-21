#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int countletters(string text);
int countword(string text);
int countsentence(string text);
int gradevalue(int totalletter, int totalwords, int totalsentence);
int main(void)
{
    string text = get_string("Enter a string of varaibale length: ");
    int totalletter = countletters(text);
    int totalwords = countword(text);
    int totalsentence = countsentence(text);
    // printf("%i\n",totalletter);
    // printf("%i\n",totalwords);
    // printf("%i\n",totalsentence);
    int grade = gradevalue(totalletter, totalwords, totalsentence);
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 3)
    {
        printf("Grade 2\n");
    }
    else if(grade <= 5)
    {
        printf("Grade 5\n");
    }
    else if (grade <=7)
    {
        printf("Grade 7\n");
    }
    else if (grade <= 8)
    {
        printf("Grade 8\n");
    }
    else if (grade <=9)
    {
        printf("Grade 9\n");
    }
    else if (grade <= 10)
    {
        printf("Grade 10\n");
    }

}

int gradevalue(int totalletter, int totalwords, int totalsentence)
{
    float l = ((float) totalletter / totalwords) * 100;
    float s = ((float) totalsentence / totalwords) * 100;
    int index = 0.0588 * l - 0.296 * s - 15.8;
    return index;
}
int countletters(string text)
{
    int count = 0;
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] != ' ')
        {
            count = count + 1;
        }
    }
    return count;
}
int countword(string text)
{
    int word = 0;
    int a = 0;
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] == ' ')
        {
            a++;
        }
    }
    word = a + 1;
    return word;
}
int countsentence(string text)
{
    int sentence = 0;
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentence++;
        }
    }
    return sentence;
}

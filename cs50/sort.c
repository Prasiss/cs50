#include <stdio.h>
#include<cs50.h>
int main (void)
{
    int number[]={20,500,10,5,100,1,50};
    int search=get_int("Enetr a number to search in array: ");

    for (int i= 0;i<7;i++)
    {
        if(number[i] == search )
        {
            printf("number found\n");
            return 0;
        }

    }
    printf("num not found\n");
    return 1;
    
}


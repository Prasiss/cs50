#include <stdio.h>
#include<cs50.h>



int calculate_quaters(int cents);
int calculate_dec(int cents);
int calculate_five(int cents);
int calculate_one(int cents);


int main(void)
{
    int cents;
    do {
        cents=get_int("Enter cents: ");
    }
    while(cents < 0);

    int quaters = calculate_quaters(cents);
    cents = cents-(quaters*25);

    int dec = calculate_dec(cents);
    cents= cents-(dec*10);

    int five = calculate_five(cents);
    cents = cents-(five *5);
    int one = calculate_one(cents);
    cents = cents -(one*1);

    int total= quaters + five+ dec +one ;
    printf("the total change is: %d\n",total);
}

int calculate_quaters(int cents){
    int quaters=0;
    while (cents >=25){
        quaters++;
        cents = cents - 25;
    }
    return quaters;

}
int calculate_dec(int cents){
    int dec=0;
    while (cents >= 10){
        dec++;
        cents = cents -10;
    }
    return dec;

}
int calculate_five(int cents){
    int five=0;
    while (cents >= 5){
        five++;
        cents = cents -5;

    }
    return five;
}

int calculate_one(int cents){
    int one=0;
    while (cents >= 1){
        one++;
        cents =cents -1;

    }
    return one;

}

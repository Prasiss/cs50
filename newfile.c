#include <stdio.h>
#include<cs50.h>


void rightprymid();
void space();

int main(void){
    int height=get_int("Enter  a number: ");

        for (int j =0; j < height;j++){
            rightprymid(j+1);
    }
}
void space(int height){
    for (int k=height; k > 0; k-- ){
        printf(" ");
    }
    printf("\n");
}
void rightprymid(int height){
    for (int i = 0; i < height; i++){
        printf("#");

    }
    printf("\n");
}

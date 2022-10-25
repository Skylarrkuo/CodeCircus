#include <stdio.h>
//*
int main(){
    int i,j,x;

    for (i = 1; i <= 5;i++){

        for (j = 1; j <= 6-i;j++){
            printf(" ");
        }

        for (x = 0; x < i * 2 - 1;x++){
            printf("*");
        } 
        printf("\n");
    }
}
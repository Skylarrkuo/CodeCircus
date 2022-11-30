#include <stdio.h>

int main(){
    int a[4] = {9, 8, 7, 6};
    int min, i, j, t;
    min = 0;
    for (i = 0; i < 4;i++){
        min = i;
        for (j = i; j < 4;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
    for (i = 0; i < 4;i++){
        printf("%d ", a[i]);
    }
}
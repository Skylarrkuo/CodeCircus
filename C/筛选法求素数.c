#include <stdio.h>

int main(){
    int a[101];
    int i;
    for (i = 1; i <= 100;i++){
        a[i] = i;
    }
    a[1] = 0;
    for (i = 2; i <= 10;i++){
        for (int j = 1; j <= 100;j++){
            if(a[j] % i == 0) a[j] = 0;
        }
    }
  
        for (i = 1; i <= 100; i++)
        {
            if (a[i] != 0)
                printf("%d ", a[i]);
        }
}
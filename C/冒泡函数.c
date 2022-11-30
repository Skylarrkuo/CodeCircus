#include <stdio.h>

void mp(int s[],int n);
int main()
{
    int i;
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    mp(array,10);
    for (i = 0; i < 10;i++){
        printf("%d ", array[i]);
    }
}

void mp(int s[],int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n -1 - i;j++){
            if(s[j]>s[j+1]){
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

}
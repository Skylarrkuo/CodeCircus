#include <stdio.h>
#include <string.h>
int main()
{
    int sum, i, j, s = 0;
    char a[1000][1000];
    scanf("%d", &sum);
    for (i = 0; i <= sum; i++)
    {
        while ((a[i][s] = getchar()) != '\n')
        {
            s++;
        }
        a[i][s++] = '\0';
        s = 0;
    }

    for (i = 0; i < sum; i++)
    {
        for (j = i + 1; j <= sum;j++){
            if(a[i][0]!='\0'&& strcmp(a[i],a[j])==0)
                a[j][0] = '\0';
        }
    }
    for (i = 0; i <= sum;i++){
        if(a[i][0]!='\0') puts(a[i]);
    }
        return 0;
}
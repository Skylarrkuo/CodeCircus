#include <stdio.h>

int main()
{
    int i;
    char s1[100], s2[100];
    gets(s2);
    printf("s1=%s\ns2=%s\n", s1, s2);
    for (i = 0; i < 100; i++)
    {
        s1[i] = s2[i];
        if (s1[i] == '\0')
            break;
    }
    printf("复制后s1为:%s", s1);
}
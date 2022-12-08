#include <stdio.h>

int main()
{
    int i;
    char s1[80], s2[80];
    char space = ' ';
    gets(s2);
    printf("s1=%s\ns2=%s\n", s1, s2);
    for (i = 0; i < 80; i++)
    {
        s1[i] = s2[i];
        if (s1[i] == '\0')
            break;
    }
    printf("复制后s1为:%s", s1);
    return 0;
}
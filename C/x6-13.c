#include <stdio.h>

int main()
{
    int i, j = 0;
    char str1[200], str2[80];
    gets(str1);
    gets(str2);
    for (i = 0; i < 200; i++)
    {
        if (str1[i] == '\0')
        {
            while (i)
            {
                str1[i++] = str2[j];
                if (str1[j++] == '\0') break;
            }
            if (str1[i] == '\0') break;
        }
    }
    puts(str1);
}
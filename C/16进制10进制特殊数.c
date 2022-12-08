#include <stdio.h>
#include <math.h>
int jz(int s, int w);
int main()
{
    int s = 10;
    int w = 2;
    while (w)
    {
        if ((s + 1) != pow(10, w))
        {
            if (jz(s, w) % s == 0)
            {
                printf("%d", s);
                break;
            }
            s++;
        }
        else
        {
            w++;
            s++;
            continue;
        }
    }
}

int jz(int s, int w)
{
    int r = 0, q = 0;
    do
    {
        r += (s % 10) * pow(16, q);
        s /= 10;
        q++;
    } while (--w);
    return r;
}
#include <iostream>
#include <math.h>
using namespace std;

int gys(int a, int b)
{
    int t, max = 0;
    if (a > b)
    {
        t = a;
        a = b;
        b = a;
    }
    for (int i = 1; i <= a; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            if (max < i)
                max = i;
        }
    }
    return max;
}

int main()
{
    cout << gys(2, 4);
    return 0;
}

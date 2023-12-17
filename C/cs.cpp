#include <iostream>
using namespace std;
int p[100000];
int l;
long pow_x(long n)
{
    if (n == 0)
        return 1;
    return pow_x(--n) * 16;
}
void C16_8()
{
    int i = 0, k = 0, n = 0;
    long sum = 0;
    char c[100000];
    int j[10];
    do
    {
        c[i++] = getchar();
    } while (c[i - 1] != '\n');
    n = i - 1;
    for (i = 0; i < n; i++)
    {
        if (c[i] < 65)
        {
            sum = sum + int(c[i] - 48) * pow_x(n - 1 - i);
        }
        else
        {
            sum = sum + int(c[i] - 55) * pow_x((n - 1 - i));
        }
    }
    while (sum > 8)
    {
        j[k] = sum % 8;
        k++;
        sum = sum / 8;
    }
    j[k] = sum;
    for (i = k; i >= 0; i--)
    {
        p[l] = j[i];
        l++;
    }
    p[l] = 8;
    l++;
}
int main()
{
    int i, n = 0;
    cin >> n;
    getchar();
    for (i = 1; i <= n; i++)
        C16_8();
    for (i = 0; i < l; i++)
        if (p[i] == 8)
            cout << endl;
        else
            cout << p[i];
    return 0;
}
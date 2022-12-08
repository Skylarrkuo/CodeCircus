#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2100;

int n = 307, m = 2022;
int cnt = 0;
int primes[N];
bool st[N];
int f[310][N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[++cnt] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

int main()
{
    get_primes(2022);

    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++)
        {
            if (primes[i] <= j)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - primes[i]] + primes[i]);
            }
            else
                f[i][j] = f[i - 1][j];
        }

    int j = m, res = 0;
    for (int i = n; i; i--)
        if (f[i][j] != f[i - 1][j])
        {
            j -= primes[i];
            res++;
            cout << primes[i] << ' ';
        }

    puts("");
    // cout << f[n][m] << endl;
    cout << res << endl;

    return 0;
}
/**
问题描述
　　有一个N x N的方格,每一个格子都有一些金币,只要站在格子里就能拿到里面的金币.你站在最左上角的格子里,每次可以从一个格子走到它右边或下边的格子里.请问如何走才能拿到最多的金币.
输入格式
　　第一行输入一个正整数n.
　　以下n行描述该方格.金币数保证是不超过1000的正整数.
输出格式
　　最多能拿金币数量.
样例输入
3
1 3 3
2 2 2
3 1 2
样例输出
11
数据规模和约定
　　n<=1000
*/

#include <iostream>

using namespace std;

int arr[1000][1000];
int n;
int sum = 0;

int Chi(int x, int y)
{
    sum += arr[x][y];
    // printf("(%d,%d)\n", x, y);
    if (x == 0 && y == 0)
        return arr[x][y]; // exti
    else if (x == 0)
        Chi(x, y - 1);
    else if (y == 0)
        Chi(x - 1, y);
    else if (arr[x][y - 1] > arr[x - 1][y])
        Chi(x, y - 1);
    else
        Chi(x - 1, y);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    Chi(n - 1, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //printf("(%d,%d)\n", i, j);
            if (i == 0 && j == 0)
                arr[i][j] = arr[i][j];
            else if (i == 0)
                arr[i][j] += arr[i ][j- 1];
            else if (j == 0)
                arr[i][j] += arr[i- 1][j ];
            else if (arr[i][j - 1] > arr[i - 1][j])
                arr[i][j] += arr[i][j - 1];
            else
                arr[i][j] += arr[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << arr[n - 1][n - 1] << endl;
    cout << sum << endl;

    return 0;
}
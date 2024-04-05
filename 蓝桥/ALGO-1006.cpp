/**
��������
������һ��N x N�ķ���,ÿһ�����Ӷ���һЩ���,ֻҪվ�ڸ���������õ�����Ľ��.��վ�������Ͻǵĸ�����,ÿ�ο��Դ�һ�������ߵ����ұ߻��±ߵĸ�����.��������߲����õ����Ľ��.
�����ʽ
������һ������һ��������n.
��������n�������÷���.�������֤�ǲ�����1000��������.
�����ʽ
����������ý������.
��������
3
1 3 3
2 2 2
3 1 2
�������
11
���ݹ�ģ��Լ��
����n<=1000
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
#include <stdio.h>
int main()
{
    int n;
    int t;
    printf("请输入数组大小");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("请输入数组%d", &arr[i]);
    }
    if (n == 1)
    {
        printf("数组只有一个元素，无法计算最接近数");
        return 0;
    }
    int min = arr[0] - arr[1];
    if (min > 0)
    {
        min = min;
    }
    else
    {
        min = -min;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min1 = arr[i + 1] - arr[i];
        if (min1 < min)
        {
            min = min1;
        }
    }
    printf("%d", min);
    return 0;
}
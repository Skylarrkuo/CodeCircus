#include <stdio.h>

int main()
{
    int min,i, j;
    //放置一个矩阵
    int a[3][4] = {{-1, 2, -3, 4}, {4, 0, -6, -5}, {6, 5, 6, 9}};
    //输出该矩阵
    printf("有三行四列矩阵为：\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    min = a[0][0];
    //对矩阵中的元素进行遍历输出
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (min > a[i][j])
                min = a[i][j];
        }
    }
    printf("其中最小的元素为:%d", min);
}
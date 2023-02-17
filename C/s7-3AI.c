#include <stdio.h>

// 冒泡排序函数
void sort(int *arr, int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    { // 外层循环控制排序轮数
        for (j = 0; j < len - 1 - i; j++)
        { // 内层循环控制每轮比较次数
            if (arr[j] > arr[j + 1])
            { // 如果前一个数大于后一个数，则交换它们的位置
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[10], i;
    printf("请输入10个整数：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]); // 输入10个整数
    }
    sort(arr, 10); // 调用冒泡排序函数对数组进行排序
    printf("排序后的数组为：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(arr + i)); // 指针法输出排序后的数组
    }
    printf("\n");
    return 0;
}

#include <stdio.h>

// 交换两个整数的值
void swap(int* a, int* b) {
    int temp;
    if (*a > *b) {  // 如果a比b大，就交换a和b
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int a, b;
    printf("请输入两个整数：\n");
    scanf("%d %d", &a, &b);

    swap(&a, &b);  // 调用函数处理a和b

    printf("按先大后小的顺序输出：%d %d\n", a, b);
    return 0;
}

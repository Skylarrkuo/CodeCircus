#include <stdio.h>

int main(){
    int i,sum,a;
    sum = 0;

    for (i = 1; i <= 30;i++){
        printf("�����%d���˵ĳɼ���", i);
        scanf("%d", &a);
        sum += a;
    }
    printf("30��ͬѧ��ƽ���ɼ�Ϊ��%d", sum/30);
}
/*
����ӽ�����
����Ŀ������
�������������arr������ÿ��Ԫ�ض�����ͬ��
�����ҵ����о�����С���Բ��Ԫ�ضԣ����Ұ������˳�򷵻ء�
�������ʽ��
����n������������ÿ��Ԫ�ض�����ͬ��
�������ʽ��
�ҵ����о�����С���Բ��Ԫ�ضԣ����Ұ������˳�򷵻ء�
������ʾ����
3 8 -10 23 19 -4 -14 27
�����ʾ����
-14 -10
19 23
23 27
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXNUM 100
using namespace std;

// �������ڼ�����������С��Ԫ�ز�ֵ
int MinEDAs(int arr[], int n)
{
    sort(arr, arr + n);    // ������������򣬼��ٱȽϴ���,ϵͳĬ�Ͽ���
    int minNum = 99999999; // ��ʼ����С��ֵΪһ���ϴ����
    for (int i = 0; i < n - 1; i++)
    {
        minNum = min(minNum, abs(arr[i] - arr[i + 1])); // ������С��ֵΪ����Ԫ��֮�����Сֵ
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (minNum == abs(arr[i] - arr[i + 1]))
        {
            cout << "[" << arr[i] << "," << arr[i + 1] << "]" << endl;
        } // �Ƚ������С��ֵΪ����Ԫ��֮�����Сֵ������
    }
    return minNum;
}

int main()
{
    int arr[MAXNUM], n;
    cout << "���������С��";
    cin >> n;
    cout << "����Ԫ�أ�";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "������С���Բ��Ԫ�ضԣ�" << endl; // ���ú������㲢������
    MinEDAs(arr, n);
    return 0;
}

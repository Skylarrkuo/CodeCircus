#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXNUM 100
using namespace std;

// �������ڼ�����������С��Ԫ�ز�ֵ
int MinED(int arr[], int n)
{
    sort(arr, arr + n); // ������������򣬼��ٱȽϴ���
    int ED = 99999999; // ��ʼ����С��ֵΪһ���ϴ����
    for (int i = 0; i < n - 1; i++)
    {
        ED = min(ED, abs(arr[i] - arr[i+1])); // ������С��ֵΪ����Ԫ��֮�����Сֵ
    }
    return ED;
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
    cout << "��������С��Ԫ�ز�Ϊ��" << MinED(arr, n); // ���ú������㲢������
    return 0;
}

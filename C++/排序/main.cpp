#include <iostream>
#include "sort.h"
using namespace std;

int main()
{
    int n, i;
    ElemType b[MAXSIZE];
    ElemType a[8] = {0, 49, 38, 65, 97, 76, 13, 27};
    SqList L, back;
    back.elem = b;
    int ZhuangTai = true; // ����״̬��־
    while (ZhuangTai)
    {
        cout << "==========================" << endl;
        cout << "|1.ʹ��Ĭ�����ݴ������Ա�|" << endl;
        cout << "|2.�ֶ��������ݴ������Ա�|" << endl;
        cout << "|3.��������ǰ���Ա�\t |" << endl;
        cout << "==========================" << endl;
        cout << "|4.˳���ð������ \t |" << endl;
        cout << "|5.˳���ֱ�Ӳ�������\t |" << endl;
        cout << "|6.˳����۰��������\t |" << endl;
        cout << "|7.˳���ϣ����������\t |" << endl;
        cout << "|8.\t |" << endl;
        cout << "|0.�˳�����\t\t |" << endl;
        cout << "==========================" << endl;
        cout << "��������ѡ�����:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            L.elem = a;
            L.length = 7;
            cout << "������˳���Ϊ:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            BackSqList(L, back);
            break;
        case 2:
            cout << "���빲�ж�����,Ȼ���Կո�������:";
            cin >> n;
            CreatSqList(L, n);
            system("cls");
            cout << "������˳���Ϊ:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 3:
            BackP(L, back);
            cout << "�ָ����˳���Ϊ:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 4:
            BubbleSort(L);
            cout << "������˳���Ϊ:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 5:
            InsertSort(L);
            cout << "������˳���Ϊ:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 6:
            BInsertSort(L);
            cout << "������˳���Ϊ:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 7:

            break;

        case 8:
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

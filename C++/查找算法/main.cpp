#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    int ZhuangTai = true;
    while (ZhuangTai)
    {
        cout << "1.�����ն���������" << endl;
        cout << "2.����˳���" << endl;
        cout << "3.˳�����" << endl;
        cout << "4.����(�۰�)����" << endl;
        cout << "5.�����������ĵݹ����" << endl;
        cout << "6.�����������Ĳ���" << endl;
        cout << "7.�����������Ĵ���" << endl;
        cout << "0.�˳�" << endl;
        cout << "============================" << endl;
        cout << "��������ѡ�����:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            BSTree T;
            InitBSTree(T);
            system("pause");
            break;``
        case 2:
            int n;
            SSTable *ST;
            cout << "���빲�ж�����,Ȼ�󰴴�С����˳����������:" ;
            cin >> n;
            CreatSStable(*ST, n);
            cout << "������˳���Ϊ:" ;
            for (int i = 0; i < n; i++)
            {
                cout << ST->R[i].key<< " ";
            }
            cout << endl;
            system("pause");
            break;
        case 3:

            system("pause");
            break;
        case 4:

            system("pause");
            break;
        case 5:

            system("pause");
            break;
        case 6:

            system("pause");
            break;
        case 7:
            break;
        }
        system("cls");
    }
    return 0;
}

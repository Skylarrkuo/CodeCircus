#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    ElemType e;
    int ZhuangTai = true;
    int n, key;
    while (ZhuangTai)
    {
        cout << "========================" << endl;
        cout << "1.����˳���" << endl;
        cout << "2.�����ն���������" << endl;
        cout << "3.�����������Ĵ���" << endl;
        cout << "4.�����������Ĳ���" << endl;
        cout << "========================" << endl;
        cout << "5.˳�����" << endl;
        cout << "6.����(�۰�)����" << endl;
        cout << "7.�����������ĵݹ����" << endl;
        cout << "0.�˳�" << endl;
        cout << "========================" << endl;
        cout << "Input >>:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1: // ����˳���
            SSTable ST;
            cout << "���빲�ж�����,Ȼ�󰴴�С����˳����������:";
            cin >> n;
            CreatSStable(ST, n);
            cout << "������˳���Ϊ:";
            for (int i = 0; i < n; i++)
            {
                cout << ST.R[i].key << " ";
            }
            cout << endl;
            system("pause");
            break;
        case 2: // �����ն���������
            BSTree T;
            InitBSTree(T);
            system("pause");
            break;
        case 3: // ��������������
            cout << "��˳������Ԫ�أ��ÿո��������#����������" << endl;
            cout << ">>:";
            CreatBST(T);
            cout << "����������������" << endl;
            InOrderTraverse(T);
            system("pause");
            break;
        case 4:
            cout << "����һ��Ԫ���Բ��������������";
            cin >> e.key;
            InsertBST(T, e);
            system("pause");
            break;
        case 5:
            cout << "����Ҫ���ҵĹؼ��֣�";
            cin >> key;
            n = Search_Seq(ST, key);
            if (n == 0)
                cout << "����ʧ�ܣ���" << endl;
            else
                cout << "���ҳɹ����ڵ�" << n + 1 << "��λ��" << endl;
            system("pause");
            break;
        case 6:
            cout << "����Ҫ���ҵĹؼ��֣�";
            cin >> key;
            n = Search_Bin(ST, key);
            if (n == -1)
                cout << "����ʧ�ܣ���" << endl;
            else
                cout << "���ҳɹ����ڵ�" << n + 1 << "��λ��" << endl;
            system("pause");
            break;
        case 7:
            cout << "����Ҫ���ҵĹؼ��֣�";
            cin >> key;
            if (!SearchBST(T, key))
                cout << "����ʧ�ܣ���" << endl;
            else
                cout << "���ҳɹ�~�����ݴ���" << endl;
            system("pause");
            break;
        }
        system("cls");
    }
    return 0;
}

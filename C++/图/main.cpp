#include <iostream>
#define OK 1;
#define MVNum 100
#define MaxInt 32767
#define ERROR 0
#include "AMGraph.h"
#include "ALGraph.h"
using namespace std;

int main()
{
   
    ALGraph alGraph;//�ڽӱ�
    AMGraph amGraph;//�ڽӾ���
    int ZhuangTai = true;//����״̬��־
    while (ZhuangTai)
    {
        cout << "============================" << endl;
        cout << "1.�ڽӾ��󴴽�����ͼ" << endl;
        cout << "2.�ڽӱ�������ͼ" << endl;
        cout << "3.����ڽӾ�������ͼ" << endl;
        cout << "4.����ڽӱ�����ͼ" << endl;
        cout << "5.������ȱ���" << endl;
        cout << "6.������ȱ���" << endl;
        cout << "7.��С������" << endl;
        cout << "8.���·��" << endl;
        cout << "9.��������" << endl;
        cout << "10.�ؼ�·��" << endl;
        cout << "0.�˳�����" << endl;
        cout << "============================" << endl;
        cout << "��������ѡ�������" ;
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            system("cls");
            CreateUDN(amGraph);
            system("pause");
            break;
        case 2:
            CreateUDG(alGraph);
            system("pause");
            break;
        case 3:
            system("cls");
            if (amGraph.arcnum)
                InputAMGraph(amGraph);
            else
                cout << "ͼ��δ����!" << endl;
            system("pause");
            break;
        case 4:
            InputALGraph(alGraph);
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            system("pause");
            break;
        case 7:
            system("pause");
            break;
        }
        system("cls");
    }
    return 0;
}

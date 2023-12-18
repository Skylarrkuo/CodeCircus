#include <iostream>
using namespace std;
#define OK 1;
#define MVNum 100
#define MaxInt 32767
#define MAXSIZE 100
#define ERROR 0
#include "SQueue.h"
#include "AMGraph.h"
#include "ALGraph.h"

int main()
{
    ALGraph alGraph;      // �ڽӱ�
    AMGraph amGraph;      // �ڽӾ���
    int ZhuangTai = true; // ����״̬��־
    while (ZhuangTai)
    {
        cout << "==========================" << endl;
        cout << "|1.�ڽӾ��󴴽�����ͼ\t|" << endl;
        cout << "|2.�ڽӱ�������ͼ\t|" << endl;
        cout << "==========================" << endl;
        cout << "|3.����ڽӾ�������ͼ\t|" << endl;
        cout << "|4.����ڽӱ�����ͼ\t|" << endl;
        cout << "|5.�ڽӾ���������ȱ���\t|" << endl;
        cout << "|6.�ڽӱ�������ȱ���\t|" << endl;
        cout << "|7.�ڽӾ��������ȱ���\t|" << endl;
        cout << "|8.�ڽӱ������ȱ���\t|" << endl;
        cout << "|0.�˳�����\t\t|" << endl;
        cout << "==========================" << endl;
        cout << "��������ѡ�����:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            CreateUDN(amGraph); // �����ڽӾ��󴴽�����ͼ����
            break;
        case 2:
            CreateUDG(alGraph); // �����ڽӱ�������ͼ����
            break;
        case 3:
            if (amGraph.vexnum)
                InputAMGraph(amGraph); // ����ڽӾ�������ͼ
            else
                cout << "�ڽӾ���Ϊ��!!" << endl;
            break;
        case 4:
            if (alGraph.vexnum)
                InputALGraph(alGraph); // ����ڽӱ�����ͼ
            else
                cout << "�ڽӱ�Ϊ��!!" << endl;
            break;
        case 5:
            system("cls");
            cout << "�ڽӾ���������ȱ�������Ϊ:" << endl;
            ClearAMvisited(amGraph); // ����ڽӾ��󶥵���ʱ�־
            DFS_AM(amGraph, 1);      // �����ڽӾ���������ȱ�������
            cout << endl;
            break;
        case 6:
            system("cls");
            cout << "�ڽӱ�������ȱ�������Ϊ:" << endl;
            ClearALvisited(alGraph); // ����ڽӱ�����ʱ�־
            DFS_AL(alGraph, 0);      // �����ڽӱ�������ȱ�������
            cout << endl;
            break;
        case 7:
            system("cls");
            cout << "�ڽӾ��������ȱ�������Ϊ:" << endl;
            ClearAMvisited(amGraph); // ����ڽӾ��󶥵���ʱ�־
            BFS_AM(amGraph, 1);      // �����ڽӾ��������ȱ�������
            cout << endl;
            break;
        case 8:
            system("cls");
            cout << "�ڽӱ������ȱ�������Ϊ:" << endl;
            ClearALvisited(alGraph); // ����ڽӱ�����ʱ�־
            BFS_AL(alGraph, 0);      // �����ڽӱ������ȱ�������
            cout << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

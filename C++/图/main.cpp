#include <iostream>
using namespace std;
#define OK 1;
#define MVNum 100
#define MaxInt 32767
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
        cout << "============================" << endl;
        cout << "1.�ڽӾ��󴴽�����ͼ" << endl;
        cout << "2.�ڽӱ�������ͼ" << endl;
        cout << "3.����ڽӾ�������ͼ" << endl;
        cout << "4.����ڽӱ�����ͼ" << endl;
        cout << "============================" << endl;
        cout << "5.�ڽӾ���������ȱ���" << endl;
        cout << "6.�ڽӱ�������ȱ���" << endl;
        cout << "7.�ڽӾ��������ȱ���" << endl;
        cout << "8.�ڽӱ������ȱ���" << endl;
        cout << "0.�˳�����" << endl;
        cout << "============================" << endl;
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
            InputAMGraph(amGraph); // ����ڽӾ�������ͼ
            break;
        case 4:
            InputALGraph(alGraph); // ����ڽӱ�����ͼ
            break;
        case 5:
            ClearAMvisited(amGraph); // ����ڽӾ��󶥵���ʱ�־
            DFS_AM(amGraph, 1);      // �����ڽӾ���������ȱ�������
            break;
        case 6:
            ClearALvisited(alGraph); // ����ڽӱ�����ʱ�־
            DFS_AL(alGraph, 0);      // �����ڽӱ�������ȱ�������
            break;
        case 7:
            ClearAMvisited(amGraph); // ����ڽӾ��󶥵���ʱ�־
            BFS_AM(amGraph, 1);      // �����ڽӾ��������ȱ�������
            break;
        case 8:
            ClearALvisited(alGraph); // ����ڽӱ�����ʱ�־
            BFS_AL(alGraph, 0);      // �����ڽӱ������ȱ�������
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

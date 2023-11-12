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
    ALGraph alGraph;
    AMGraph amGraph;
    int ZhuangTai = true;
    while (ZhuangTai)
    {
        cout << "============================" << endl;
        cout << "1.�ڽӾ��󴴽�����ͼ" << endl;
        cout << "2.�ڽӱ�������ͼ" << endl;
        cout << "3.����ڽӾ�������ͼ" << endl;
        cout << "4.����ڽӱ�����ͼ" << endl;
        cout << "5." << endl;
        cout << "6." << endl;
        cout << "7." << endl;
        cout << "0." << endl;
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
            Display(alGraph);
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

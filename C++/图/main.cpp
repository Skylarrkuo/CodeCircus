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
   
    ALGraph alGraph;//邻接表
    AMGraph amGraph;//邻接矩阵
    int ZhuangTai = true;//运行状态标志
    while (ZhuangTai)
    {
        cout << "============================" << endl;
        cout << "1.邻接矩阵创建无向图" << endl;
        cout << "2.邻接表创建无向图" << endl;
        cout << "3.输出邻接矩阵无向图" << endl;
        cout << "4.输出邻接表无向图" << endl;
        cout << "5.深度优先遍历" << endl;
        cout << "6.广度优先遍历" << endl;
        cout << "7.最小生成树" << endl;
        cout << "8.最短路径" << endl;
        cout << "9.拓扑排序" << endl;
        cout << "10.关键路径" << endl;
        cout << "0.退出程序" << endl;
        cout << "============================" << endl;
        cout << "输入数子选择操作：" ;
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
                cout << "图还未创建!" << endl;
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

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
    ALGraph alGraph;      // 邻接表
    AMGraph amGraph;      // 邻接矩阵
    int ZhuangTai = true; // 运行状态标志
    while (ZhuangTai)
    {
        cout << "============================" << endl;
        cout << "1.邻接矩阵创建无向图" << endl;
        cout << "2.邻接表创建无向图" << endl;
        cout << "3.输出邻接矩阵无向图" << endl;
        cout << "4.输出邻接表无向图" << endl;
        cout << "============================" << endl;
        cout << "5.邻接矩阵深度优先遍历" << endl;
        cout << "6.邻接表深度优先遍历" << endl;
        cout << "7.邻接矩阵广度优先遍历" << endl;
        cout << "8.邻接表广度优先遍历" << endl;
        cout << "0.退出程序" << endl;
        cout << "============================" << endl;
        cout << "输入数字选择操作:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            CreateUDN(amGraph); // 调用邻接矩阵创建无向图函数
            break;
        case 2:
            CreateUDG(alGraph); // 调用邻接表创建无向图函数
            break;
        case 3:
            InputAMGraph(amGraph); // 输出邻接矩阵无向图
            break;
        case 4:
            InputALGraph(alGraph); // 输出邻接表无向图
            break;
        case 5:
            ClearAMvisited(amGraph); // 清空邻接矩阵顶点访问标志
            DFS_AM(amGraph, 1);      // 调用邻接矩阵深度优先遍历函数
            break;
        case 6:
            ClearALvisited(alGraph); // 清空邻接表顶点访问标志
            DFS_AL(alGraph, 0);      // 调用邻接表深度优先遍历函数
            break;
        case 7:
            ClearAMvisited(amGraph); // 清空邻接矩阵顶点访问标志
            BFS_AM(amGraph, 1);      // 调用邻接矩阵广度优先遍历函数
            break;
        case 8:
            ClearALvisited(alGraph); // 清空邻接表顶点访问标志
            BFS_AL(alGraph, 0);      // 调用邻接表广度优先遍历函数
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

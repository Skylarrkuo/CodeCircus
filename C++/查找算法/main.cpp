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
        cout << "1.创建顺序表" << endl;
        cout << "2.创建空二叉排序树" << endl;
        cout << "3.二叉排序树的创建" << endl;
        cout << "4.二叉排序树的插入" << endl;
        cout << "========================" << endl;
        cout << "5.顺序查找" << endl;
        cout << "6.二分(折半)查找" << endl;
        cout << "7.二叉排序树的递归查找" << endl;
        cout << "0.退出" << endl;
        cout << "========================" << endl;
        cout << "Input >>:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1: // 创建顺序表
            SSTable ST;
            cout << "输入共有多少项,然后按从小到大顺序依次输入:";
            cin >> n;
            CreatSStable(ST, n);
            cout << "创建的顺序表为:";
            for (int i = 0; i < n; i++)
            {
                cout << ST.R[i].key << " ";
            }
            cout << endl;
            system("pause");
            break;
        case 2: // 创建空二叉排序树
            BSTree T;
            InitBSTree(T);
            system("pause");
            break;
        case 3: // 创建二叉排序数
            cout << "按顺序输入元素,用空格隔开,以0结束创建:" << endl;
            cout << ">>:";
            CreatBST(T);
            cout << "中序输出创建结果:" << endl;
            InOrderTraverse(T);
            system("pause");
            break;
        case 4:
            cout << "输入一个元素以插入二叉排序树:";
            cin >> e.key;
            InsertBST(T, e);
            system("pause");
            break;
        case 5:
            cout << "输入要查找的关键字:";
            cin >> key;
            n = Search_Seq(ST, key);
            if (n == 0)
                cout << "查找失败!!" << endl;
            else
                cout << "查找成功,在第" << n + 1 << "个位置" << endl;
            system("pause");
            break;
        case 6:
            cout << "输入要查找的关键字:";
            cin >> key;
            n = Search_Bin(ST, key);
            if (n == -1)
                cout << "查找失败!!" << endl;
            else
                cout << "查找成功,在第" << n + 1 << "个位置" << endl;
            system("pause");
            break;
        case 7:
            cout << "输入要查找的关键字:";
            cin >> key;
            if (!SearchBST(T, key))
                cout << "查找失败!!" << endl;
            else
                cout << "查找成功~该数据存在" << endl;
            system("pause");
            break;
        }
        system("cls");
    }
    return 0;
}
/*
①已经包含11个数据元素的有序表(5 16 20 27 30 36 44 55 60 67 71),请给出查找关键字为60,70的顺序查找和折半查找的结果;
②设定关键字的输入序列为(45 24 53 12 90),请创建一棵二叉排序树并完成查找99是否在其中.

*/
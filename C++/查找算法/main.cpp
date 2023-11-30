#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    int ZhuangTai = true;
    while (ZhuangTai)
    {
        cout << "1.创建空二叉排序树" << endl;
        cout << "2.创建顺序表" << endl;
        cout << "3.顺序查找" << endl;
        cout << "4.二分(折半)查找" << endl;
        cout << "5.二叉排序树的递归查找" << endl;
        cout << "6.二叉排序树的插入" << endl;
        cout << "7.二叉排序树的创建" << endl;
        cout << "0.退出" << endl;
        cout << "============================" << endl;
        cout << "输入数子选择操作:";
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
            cout << "输入共有多少项,然后按从小到大顺序依次输入:" ;
            cin >> n;
            CreatSStable(*ST, n);
            cout << "创建的顺序表为:" ;
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

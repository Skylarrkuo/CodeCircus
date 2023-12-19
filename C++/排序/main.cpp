#include <iostream>
#include "sort.h"
using namespace std;

int main()
{
    int n, i;
    ElemType b[MAXSIZE];
    ElemType a[8] = {0, 49, 38, 65, 97, 76, 13, 27};
    SqList L, back;
    back.elem = b;
    int ZhuangTai = true; // 运行状态标志
    while (ZhuangTai)
    {
        cout << "==========================" << endl;
        cout << "|1.使用默认数据创建线性表|" << endl;
        cout << "|2.手动输入数据创建线性表|" << endl;
        cout << "|3.重置排序前线性表\t |" << endl;
        cout << "==========================" << endl;
        cout << "|4.顺序表冒泡排序 \t |" << endl;
        cout << "|5.顺序表直接插入排序\t |" << endl;
        cout << "|6.顺序表折半插入排序\t |" << endl;
        cout << "|7.顺序表希尔增量排序\t |" << endl;
        cout << "|8.\t |" << endl;
        cout << "|0.退出程序\t\t |" << endl;
        cout << "==========================" << endl;
        cout << "输入数字选择操作:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            L.elem = a;
            L.length = 7;
            cout << "创建的顺序表为:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            BackSqList(L, back);
            break;
        case 2:
            cout << "输入共有多少项,然后以空格间隔输入:";
            cin >> n;
            CreatSqList(L, n);
            system("cls");
            cout << "创建的顺序表为:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 3:
            BackP(L, back);
            cout << "恢复后的顺序表为:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 4:
            BubbleSort(L);
            cout << "排序后的顺序表为:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 5:
            InsertSort(L);
            cout << "排序后的顺序表为:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 6:
            BInsertSort(L);
            cout << "排序后的顺序表为:";
            for (i = 1; i <= L.length; i++)
                cout << L.elem[i].data << " ";
            cout << endl;
            break;
        case 7:

            break;

        case 8:
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

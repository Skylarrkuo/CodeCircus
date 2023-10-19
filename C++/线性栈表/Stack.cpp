#define MAXSIZE 100 // 栈最大容量
#define ERROR 0
#define OK 1
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
typedef int Status;

typedef struct SElemType
{ // 数据元素
    int data;
} SElemType;

typedef struct
{ // 线性栈
    SElemType *base;
    SElemType *top;
    int stacksize;
} sqStack;

// 线性栈初始化
Status InitStack(sqStack &s)
{
    if (!s.base)
        return OVERFLOW; // 分配失败
    s.base = new SElemType[MAXSIZE];
    s.top = s.base;
    return OK; // 分配成功
}

// 入栈
Status Push(sqStack &s, SElemType e)
{
    if (!s.base)
        return ERROR; // 栈不存在
    if (s.top - s.base == s.stacksize)
        return OVERFLOW; // 栈已满
    *s.top++ = e;
    return OK;
}

// 出栈
Status Pop(sqStack &s, SElemType &e)
{
    if (s.base == NULL)
        return ERROR; // 栈不存在
    if (s.top == s.base)
        return OVERFLOW; // 栈空
    e = *--s.top;
    return OK;
}

// 取栈顶元素
Status GetTop(sqStack s)
{
    if (!s.base)
        return ERROR; // 栈不存在
    if (s.top == s.base)
        return OVERFLOW; // 栈空
    return (s.top - 1)->data;
}

// 栈的判空
Status ListEmpty(sqStack s)
{
    if (!s.base)
        return ERROR; // 栈不存在
    if (s.top != s.base)
        return false; // 栈不空
    else if (s.top == s.base)
        return true;
}

int HOB(sqStack &s, int n, int m)
{ // 递归进制转换2-10进制
    SElemType e;
    if (n == 0)
        return 0;
    else
    {
        e.data = n % m;
        Push(s, e);
        HOB(s, n / m, m);
    }
}

int main()
{
    sqStack S;
    SElemType e;
    int next = true;
    int i, n, m, m1, t;

    while (next)
    {
        system("cls");
        cout << "选择进入模式(1.线性栈操作/2.基于栈的进制转换):";
        cin >> m;
        switch (m)
        {
        case 1: // 线性栈操作8
            while (next)
            {
                system("cls");
                cout << "================线性栈表的操作=============" << endl;
                cout << "\t1.建立线性栈\t7.遍历线性栈" << endl;
                cout << "\t2.入栈操作\t8.取栈顶元素" << endl;
                cout << "\t3.出栈操作\t9.取栈长操作" << endl;
                cout << "\t4.判空操作\t10.退出" << endl;
                cout << "\t5.清空栈\t" << endl;
                cout << "\t6.销毁栈\t" << endl;
                cout << "===========输入对应数字进行操作============\n>>:";
                cin >> m1;
                switch (m1)
                {
                case 1:
                    system("cls");
                    if (InitStack(S))
                        cout << "初始化成功！" << endl;
                    sleep(1);
                    break;
                case 2:
                    system("cls");
                    cout << "输入要入栈的个数：";
                    cin >> n;
                    cout << "\n输入数据，用空格或回车隔开:\n";
                    for (i = 0; i < n; i++)
                    {
                        cin >> e.data;
                        if (Push(S, e) != OK)
                        {
                            cout << "\n错误！栈已满";
                            break;
                        }
                    }
                    if (i != n)
                        cout << "\n未完成入栈操作！栈不存在或已满" << endl;
                    else if (i == n)
                        cout << "\n入栈操作完成！" << endl;
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    system("cls");
                    cout << "输入要出栈的个数：";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {

                        if (Pop(S, e) == OVERFLOW)
                        {
                            cout << "\n错误！栈已空";
                            break;
                        }
                        cout << e.data << endl;
                    }
                    if (i != n)
                        cout << "\n未完成出栈操作！栈不存在或已空" << endl;
                    else if (i == n)
                        cout << "\n出栈操作完成！" << endl;
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if (ListEmpty(S))
                        cout << "栈为空！" << endl;
                    else
                        cout << "栈不存在或不空!" << endl;
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    while (ListEmpty(S))
                    {
                        Pop(S, e);
                    }
                    S.base = NULL;
                    cout << "清空完成" << endl;
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    while (ListEmpty(S))
                    {
                        Pop(S, e);
                    }
                    delete S.base;
                    cout << "销毁栈完成" << endl;
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    break;
                case 8:
                    system("cls");
                    if (!ListEmpty(S))
                        cout << "栈顶元素为:" << GetTop(S) << endl;
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    cout << "感谢使用" << endl;
                    sleep(3);
                    next = false;
                    break;
                default:
                    cout << "输入错误！" << endl;
                    sleep(1);
                    break;
                }
            }
            next = true;
            break;
        case 2: // 进制转换
            system("cls");
            cout << "输入要转换成为的进制(2-9)：";
            cin >> n;
            cout << "输入要转换的十进制数字:";
            cin >> t;
            cout << "转换后表示为:" << endl;
            InitStack(S);
            HOB(S, t, n);
            while (!ListEmpty(S))
            {
                Pop(S, e);
                cout << e.data << " ";
            }
            cout << endl;
            delete[] S.base;
            system("pause");
            break;

        default:
            cout << "输入错误!";
            system("pause");
            break;
        }
    }
}
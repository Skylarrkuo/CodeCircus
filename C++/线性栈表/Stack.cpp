#define MAXSIZE 100 // ջ�������
#define ERROR 0
#define OK 1
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
typedef int Status;

typedef struct SElemType
{ // ����Ԫ��
    int data;
} SElemType;

typedef struct
{ // ����ջ
    SElemType *base;
    SElemType *top;
    int stacksize;
} sqStack;

// ����ջ��ʼ��
Status InitStack(sqStack &s)
{
    if (!s.base)
        return OVERFLOW; // ����ʧ��
    s.base = new SElemType[MAXSIZE];
    s.top = s.base;
    return OK; // ����ɹ�
}

// ��ջ
Status Push(sqStack &s, SElemType e)
{
    if (!s.base)
        return ERROR; // ջ������
    if (s.top - s.base == s.stacksize)
        return OVERFLOW; // ջ����
    *s.top++ = e;
    return OK;
}

// ��ջ
Status Pop(sqStack &s, SElemType &e)
{
    if (s.base == NULL)
        return ERROR; // ջ������
    if (s.top == s.base)
        return OVERFLOW; // ջ��
    e = *--s.top;
    return OK;
}

// ȡջ��Ԫ��
Status GetTop(sqStack s)
{
    if (!s.base)
        return ERROR; // ջ������
    if (s.top == s.base)
        return OVERFLOW; // ջ��
    return (s.top - 1)->data;
}

// ջ���п�
Status ListEmpty(sqStack s)
{
    if (!s.base)
        return ERROR; // ջ������
    if (s.top != s.base)
        return false; // ջ����
    else if (s.top == s.base)
        return true;
}

int HOB(sqStack &s, int n, int m)
{ // �ݹ����ת��2-10����
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
        cout << "ѡ�����ģʽ(1.����ջ����/2.����ջ�Ľ���ת��):";
        cin >> m;
        switch (m)
        {
        case 1: // ����ջ����8
            while (next)
            {
                system("cls");
                cout << "================����ջ��Ĳ���=============" << endl;
                cout << "\t1.��������ջ\t7.��������ջ" << endl;
                cout << "\t2.��ջ����\t8.ȡջ��Ԫ��" << endl;
                cout << "\t3.��ջ����\t9.ȡջ������" << endl;
                cout << "\t4.�пղ���\t10.�˳�" << endl;
                cout << "\t5.���ջ\t" << endl;
                cout << "\t6.����ջ\t" << endl;
                cout << "===========�����Ӧ���ֽ��в���============\n>>:";
                cin >> m1;
                switch (m1)
                {
                case 1:
                    system("cls");
                    if (InitStack(S))
                        cout << "��ʼ���ɹ���" << endl;
                    sleep(1);
                    break;
                case 2:
                    system("cls");
                    cout << "����Ҫ��ջ�ĸ�����";
                    cin >> n;
                    cout << "\n�������ݣ��ÿո��س�����:\n";
                    for (i = 0; i < n; i++)
                    {
                        cin >> e.data;
                        if (Push(S, e) != OK)
                        {
                            cout << "\n����ջ����";
                            break;
                        }
                    }
                    if (i != n)
                        cout << "\nδ�����ջ������ջ�����ڻ�����" << endl;
                    else if (i == n)
                        cout << "\n��ջ������ɣ�" << endl;
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    system("cls");
                    cout << "����Ҫ��ջ�ĸ�����";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {

                        if (Pop(S, e) == OVERFLOW)
                        {
                            cout << "\n����ջ�ѿ�";
                            break;
                        }
                        cout << e.data << endl;
                    }
                    if (i != n)
                        cout << "\nδ��ɳ�ջ������ջ�����ڻ��ѿ�" << endl;
                    else if (i == n)
                        cout << "\n��ջ������ɣ�" << endl;
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if (ListEmpty(S))
                        cout << "ջΪ�գ�" << endl;
                    else
                        cout << "ջ�����ڻ򲻿�!" << endl;
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    while (ListEmpty(S))
                    {
                        Pop(S, e);
                    }
                    S.base = NULL;
                    cout << "������" << endl;
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    while (ListEmpty(S))
                    {
                        Pop(S, e);
                    }
                    delete S.base;
                    cout << "����ջ���" << endl;
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    break;
                case 8:
                    system("cls");
                    if (!ListEmpty(S))
                        cout << "ջ��Ԫ��Ϊ:" << GetTop(S) << endl;
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    cout << "��лʹ��" << endl;
                    sleep(3);
                    next = false;
                    break;
                default:
                    cout << "�������" << endl;
                    sleep(1);
                    break;
                }
            }
            next = true;
            break;
        case 2: // ����ת��
            system("cls");
            cout << "����Ҫת����Ϊ�Ľ���(2-9)��";
            cin >> n;
            cout << "����Ҫת����ʮ��������:";
            cin >> t;
            cout << "ת�����ʾΪ:" << endl;
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
            cout << "�������!";
            system("pause");
            break;
        }
    }
}
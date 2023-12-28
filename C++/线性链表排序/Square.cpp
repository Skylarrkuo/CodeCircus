#define MAXSIZE 100 // 最大容量
#define ERROR 0
#define OK 1
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
typedef int Status;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

void CreateList(LinkList &L, int n)
{
    LinkList p,q;
    p = L;
    for (int i = 1; i <= n; i++)
    {
        q = new LNode;
        q->data = 100 - i * 10;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }
}

void PrintList(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    cout << endl;
}

// 单链表的简单选择排序
void Sort(LinkList &L)
{
    LinkList p, q, min;
    for (p = L->next; p != NULL; p = p->next)
    {
        min = p;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (q->data < min->data)
            {
                min = q;
            }
        }
        if (min != p)
        {
            int temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
    }
}

int main()
{
    int n, t;
    LinkList Head;
    Head->next = NULL; // 头结点无后继结点
    cout << "输入数据个数:";
    cin >> n;

    CreateList(Head, n);

    PrintList(Head);
    Sort(Head);
    PrintList(Head);
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;


void print(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    LinkList Head = NULL;
    head->next = NULL;//头结点无后继结点
    int n,t;
    cont >> "输入人数，和丢弃位置：";
    cin << n << t;
    CreateList(int n);
    printf(" \n");
    print(Head);

    printf("\n\n");
    system("pause");
    return 0;
}

LinkList CreateList(LinkList &L,int n)
{
    LinkList  p, q;
    int i;
    if (!L)
        return 0;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p->data = i;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return OK;
}

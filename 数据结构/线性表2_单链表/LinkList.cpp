#define MAXSIZE 100 // 最大容量
#define ERROR 0
#define OK 1
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Status;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化单链表
Status InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
        return OVERFLOW;
    L->next = NULL;
    return OK;
}

// 创建单链表（尾插法）
void CreateList_Tail(LinkList &L, int n)
{
    if (L->next != NULL)
    {
        cout << "链表已存在，请先清空或销毁链表！" << endl;
        return;
    }
    
    LinkList r = L;
    cout << "请依次输入" << n << "个数据：" << endl;
    for (int i = 1; i <= n; i++)
    {
        LinkList p = new LNode;
        cout << "第" << i << "个数据: ";
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    cout << "链表创建成功！" << endl;
}

// 获取链表长度
int ListLength(LinkList L)
{
    int length = 0;
    LinkList p = L->next;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 按位置获取元素
Status GetElem(LinkList L, int i, int &e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

// 按值查找位置
int LocateElem(LinkList L, int e)
{
    LinkList p = L->next;
    int position = 1;
    while (p != NULL)
    {
        if (p->data == e)
            return position;
        p = p->next;
        position++;
    }
    return 0; // 未找到返回0
}

// 在指定位置插入元素
Status ListInsert(LinkList &L, int i, int e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    LinkList s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除指定位置元素
Status ListDelete(LinkList &L, int i, int &e)
{
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return ERROR;
    LinkList q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return OK;
}

// 清空链表
void ClearList(LinkList &L)
{
    LinkList p, q;
    p = L->next;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    L->next = NULL;
}

// 判断链表是否为空
bool ListEmpty(LinkList L)
{
    return L->next == NULL;
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

// 链表逆置
void ReverseList(LinkList &L)
{
    if (L->next == NULL || L->next->next == NULL)
        return;
    
    LinkList pre = NULL;
    LinkList cur = L->next;
    LinkList next = NULL;
    
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    L->next = pre;
}

// 打印链表
void PrintList(LinkList L)
{
    if (L->next == NULL)
    {
        cout << "链表为空！" << endl;
        return;
    }
    LinkList p = L->next;
    cout << "链表内容: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 显示菜单
void ShowMenu()
{
    cout << "\n========== 单链表操作菜单 ==========" << endl;
    cout << "1. 创建链表" << endl;
    cout << "2. 插入元素" << endl;
    cout << "3. 删除元素" << endl;
    cout << "4. 查找元素（按值）" << endl;
    cout << "5. 获取元素（按位置）" << endl;
    cout << "6. 获取链表长度" << endl;
    cout << "7. 打印链表" << endl;
    cout << "8. 排序链表" << endl;
    cout << "9. 逆置链表" << endl;
    cout << "10. 清空链表" << endl;
    cout << "11. 判断链表是否为空" << endl;
    cout << "0. 退出程序" << endl;
    cout << "====================================" << endl;

}

int main()
{
    LinkList Head;
    InitList(Head);
    
    int choice, n, position, elem;
    Status result;
    ShowMenu(); //显示菜单

    while (true)
    {
        cout << "请选择操作: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // 创建链表
            cout << "请输入要创建的链表长度: ";
            cin >> n;
            if (n <= 0)
            {
                cout << "长度必须大于0！" << endl;
                break;
            }
            CreateList_Tail(Head, n);
            break;
            
        case 2: // 插入元素
            cout << "请输入插入位置: ";
            cin >> position;
            cout << "请输入插入的元素值: ";
            cin >> elem;
            result = ListInsert(Head, position, elem);
            if (result == OK)
                cout << "插入成功！" << endl;
            else
                cout << "插入失败！位置不合法。" << endl;
            break;
            
        case 3: // 删除元素
            cout << "请输入要删除的位置: ";
            cin >> position;
            result = ListDelete(Head, position, elem);
            if (result == OK)
                cout << "删除成功！删除的元素为: " << elem << endl;
            else
                cout << "删除失败！位置不合法。" << endl;
            break;
            
        case 4: // 查找元素
            cout << "请输入要查找的元素值: ";
            cin >> elem;
            position = LocateElem(Head, elem);
            if (position != 0)
                cout << "元素 " << elem << " 在第 " << position << " 个位置" << endl;
            else
                cout << "未找到元素 " << elem << endl;
            break;
            
        case 5: // 获取元素
            cout << "请输入要获取的位置: ";
            cin >> position;
            result = GetElem(Head, position, elem);
            if (result == OK)
                cout << "第 " << position << " 个位置的元素为: " << elem << endl;
            else
                cout << "获取失败！位置不合法。" << endl;
            break;
            
        case 6: // 获取长度
            cout << "链表长度为: " << ListLength(Head) << endl;
            break;
            
        case 7: // 打印链表
            PrintList(Head);
            break;
            
        case 8: // 排序
            if (ListEmpty(Head))
            {
                cout << "链表为空，无法排序！" << endl;
            }
            else
            {
                Sort(Head);
                cout << "排序完成！" << endl;
                PrintList(Head);
            }
            break;
            
        case 9: // 逆置
            if (ListEmpty(Head))
            {
                cout << "链表为空，无法逆置！" << endl;
            }
            else
            {
                ReverseList(Head);
                cout << "逆置完成！" << endl;
                PrintList(Head);
            }
            break;
            
        case 10: // 清空链表
            ClearList(Head);
            cout << "链表已清空！" << endl;
            break;
            
        case 11: // 判断是否为空
            if (ListEmpty(Head))
                cout << "链表为空" << endl;
            else
                cout << "链表不为空，长度为: " << ListLength(Head) << endl;
            break;
            
        case 0: // 退出
            ClearList(Head);
            delete Head;
            cout << "程序已退出，感谢使用！" << endl;
            return 0;
            
        default:
            cout << "无效的选择，请重新输入！" << endl;
            break;
        }
    }
    
    return 0;
}

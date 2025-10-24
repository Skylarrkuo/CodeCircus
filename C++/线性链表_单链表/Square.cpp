#define MAXSIZE 100 // �������
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

// ��ʼ��������
Status InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
        return OVERFLOW;
    L->next = NULL;
    return OK;
}

// ����������β�巨��
void CreateList_Tail(LinkList &L, int n)
{
    if (L->next != NULL)
    {
        cout << "�����Ѵ��ڣ�������ջ���������" << endl;
        return;
    }
    
    LinkList r = L;
    cout << "����������" << n << "�����ݣ�" << endl;
    for (int i = 1; i <= n; i++)
    {
        LinkList p = new LNode;
        cout << "��" << i << "������: ";
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    cout << "�������ɹ���" << endl;
}

// ��ȡ������
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

// ��λ�û�ȡԪ��
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

// ��ֵ����λ��
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
    return 0; // δ�ҵ�����0
}

// ��ָ��λ�ò���Ԫ��
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

// ɾ��ָ��λ��Ԫ��
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

// �������
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

// �ж������Ƿ�Ϊ��
bool ListEmpty(LinkList L)
{
    return L->next == NULL;
}

// ������ļ�ѡ������
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

// ��������
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

// ��ӡ����
void PrintList(LinkList L)
{
    if (L->next == NULL)
    {
        cout << "����Ϊ�գ�" << endl;
        return;
    }
    LinkList p = L->next;
    cout << "��������: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// ��ʾ�˵�
void ShowMenu()
{
    cout << "\n========== ����������˵� ==========" << endl;
    cout << "1. ��������" << endl;
    cout << "2. ����Ԫ��" << endl;
    cout << "3. ɾ��Ԫ��" << endl;
    cout << "4. ����Ԫ�أ���ֵ��" << endl;
    cout << "5. ��ȡԪ�أ���λ�ã�" << endl;
    cout << "6. ��ȡ������" << endl;
    cout << "7. ��ӡ����" << endl;
    cout << "8. ��������" << endl;
    cout << "9. ��������" << endl;
    cout << "10. �������" << endl;
    cout << "11. �ж������Ƿ�Ϊ��" << endl;
    cout << "0. �˳�����" << endl;
    cout << "====================================" << endl;

}

int main()
{
    LinkList Head;
    InitList(Head);
    
    int choice, n, position, elem;
    Status result;
    ShowMenu(); //��ʾ�˵�

    while (true)
    {
        cout << "��ѡ�����: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // ��������
            cout << "������Ҫ������������: ";
            cin >> n;
            if (n <= 0)
            {
                cout << "���ȱ������0��" << endl;
                break;
            }
            CreateList_Tail(Head, n);
            break;
            
        case 2: // ����Ԫ��
            cout << "���������λ��: ";
            cin >> position;
            cout << "����������Ԫ��ֵ: ";
            cin >> elem;
            result = ListInsert(Head, position, elem);
            if (result == OK)
                cout << "����ɹ���" << endl;
            else
                cout << "����ʧ�ܣ�λ�ò��Ϸ���" << endl;
            break;
            
        case 3: // ɾ��Ԫ��
            cout << "������Ҫɾ����λ��: ";
            cin >> position;
            result = ListDelete(Head, position, elem);
            if (result == OK)
                cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ: " << elem << endl;
            else
                cout << "ɾ��ʧ�ܣ�λ�ò��Ϸ���" << endl;
            break;
            
        case 4: // ����Ԫ��
            cout << "������Ҫ���ҵ�Ԫ��ֵ: ";
            cin >> elem;
            position = LocateElem(Head, elem);
            if (position != 0)
                cout << "Ԫ�� " << elem << " �ڵ� " << position << " ��λ��" << endl;
            else
                cout << "δ�ҵ�Ԫ�� " << elem << endl;
            break;
            
        case 5: // ��ȡԪ��
            cout << "������Ҫ��ȡ��λ��: ";
            cin >> position;
            result = GetElem(Head, position, elem);
            if (result == OK)
                cout << "�� " << position << " ��λ�õ�Ԫ��Ϊ: " << elem << endl;
            else
                cout << "��ȡʧ�ܣ�λ�ò��Ϸ���" << endl;
            break;
            
        case 6: // ��ȡ����
            cout << "������Ϊ: " << ListLength(Head) << endl;
            break;
            
        case 7: // ��ӡ����
            PrintList(Head);
            break;
            
        case 8: // ����
            if (ListEmpty(Head))
            {
                cout << "����Ϊ�գ��޷�����" << endl;
            }
            else
            {
                Sort(Head);
                cout << "������ɣ�" << endl;
                PrintList(Head);
            }
            break;
            
        case 9: // ����
            if (ListEmpty(Head))
            {
                cout << "����Ϊ�գ��޷����ã�" << endl;
            }
            else
            {
                ReverseList(Head);
                cout << "������ɣ�" << endl;
                PrintList(Head);
            }
            break;
            
        case 10: // �������
            ClearList(Head);
            cout << "��������գ�" << endl;
            break;
            
        case 11: // �ж��Ƿ�Ϊ��
            if (ListEmpty(Head))
                cout << "����Ϊ��" << endl;
            else
                cout << "����Ϊ�գ�����Ϊ: " << ListLength(Head) << endl;
            break;
            
        case 0: // �˳�
            ClearList(Head);
            delete Head;
            cout << "�������˳�����лʹ�ã�" << endl;
            return 0;
            
        default:
            cout << "��Ч��ѡ�����������룡" << endl;
            break;
        }
    }
    
    return 0;
}

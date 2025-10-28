#define MAXSIZE 100 // �������
#define ERROR 0
#define OK 1
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Status;

// ˳���ṹ����
typedef struct
{
    int *elem;     // �洢�ռ��ַ
    int length;    // ��ǰ����
    int listsize;  // ��ǰ����Ĵ洢����
} SqList;

// ��ʼ��˳���
Status InitList(SqList &L)
{
    L.elem = new int[MAXSIZE];
    if (!L.elem)
        return OVERFLOW;
    L.length = 0;
    L.listsize = MAXSIZE;
    cout << "˳����ʼ���ɹ���" << endl;
    return OK;
}

// ����˳���
void DestroyList(SqList &L)
{
    if (L.elem)
    {
        delete[] L.elem;
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
    }
}

// ���˳���
void ClearList(SqList &L)
{
    L.length = 0;
    cout << "˳�������գ�" << endl;
}

// �ж�˳����Ƿ�Ϊ��
bool ListEmpty(SqList L)
{
    return L.length == 0;
}

// ��ȡ˳�����
int ListLength(SqList L)
{
    return L.length;
}

// ��ȡָ��λ�õ�Ԫ��
Status GetElem(SqList L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

// ����Ԫ�أ����ص�һ��ƥ���λ�ã�
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1; // ����λ�򣨴�1��ʼ��
    }
    return 0; // δ�ҵ�
}

// ��ָ��λ�ò���Ԫ��
Status ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listsize)
    {
        cout << "˳����������޷����룡" << endl;
        return ERROR;
    }
    
    // ����i��λ�ü�֮���Ԫ�غ���
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

// ɾ��ָ��λ�õ�Ԫ��
Status ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    
    e = L.elem[i - 1];
    
    // ����i��λ��֮���Ԫ��ǰ��
    for (int j = i; j < L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;
}

// ����˳���
void CreateList(SqList &L, int n)
{
    if (n <= 0 || n > MAXSIZE)
    {
        cout << "����ĳ��Ȳ��Ϸ���" << endl;
        return;
    }
    
    cout << "����������" << n << "�����ݣ�" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "��" << (i + 1) << "������: ";
        cin >> L.elem[i];
    }
    L.length = n;
    cout << "˳������ɹ���" << endl;
}

// ��ӡ˳���
void PrintList(SqList L)
{
    if (L.length == 0)
    {
        cout << "˳���Ϊ�գ�" << endl;
        return;
    }
    
    cout << "˳�������: ";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// ˳�������ð������
void SortList(SqList &L)
{
    if (L.length <= 1)
        return;
    
    for (int i = 0; i < L.length - 1; i++)
    {
        for (int j = 0; j < L.length - 1 - i; j++)
        {
            if (L.elem[j] > L.elem[j + 1])
            {
                int temp = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = temp;
            }
        }
    }
}

// ����˳���
void ReverseList(SqList &L)
{
    if (L.length <= 1)
        return;
    
    for (int i = 0; i < L.length / 2; i++)
    {
        int temp = L.elem[i];
        L.elem[i] = L.elem[L.length - 1 - i];
        L.elem[L.length - 1 - i] = temp;
    }
}

// �������ֵ
Status FindMax(SqList L, int &max)
{
    if (L.length == 0)
        return ERROR;
    
    max = L.elem[0];
    for (int i = 1; i < L.length; i++)
    {
        if (L.elem[i] > max)
            max = L.elem[i];
    }
    return OK;
}

// ������Сֵ
Status FindMin(SqList L, int &min)
{
    if (L.length == 0)
        return ERROR;
    
    min = L.elem[0];
    for (int i = 1; i < L.length; i++)
    {
        if (L.elem[i] < min)
            min = L.elem[i];
    }
    return OK;
}

// �ϲ���������˳���
SqList MergeList(SqList La, SqList Lb)
{
    SqList Lc;
    InitList(Lc);
    
    int i = 0, j = 0, k = 0;
    
    while (i < La.length && j < Lb.length)
    {
        if (La.elem[i] <= Lb.elem[j])
        {
            Lc.elem[k++] = La.elem[i++];
        }
        else
        {
            Lc.elem[k++] = Lb.elem[j++];
        }
    }
    
    while (i < La.length)
    {
        Lc.elem[k++] = La.elem[i++];
    }
    
    while (j < Lb.length)
    {
        Lc.elem[k++] = Lb.elem[j++];
    }
    
    Lc.length = k;
    return Lc;
}

// ȥ�أ�������һ�γ��ֵ�Ԫ�أ�
void RemoveDuplicate(SqList &L)
{
    if (L.length <= 1)
        return;
    
    int newLength = 1;
    for (int i = 1; i < L.length; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < newLength; j++)
        {
            if (L.elem[i] == L.elem[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            L.elem[newLength++] = L.elem[i];
        }
    }
    L.length = newLength;
}

// ��ʾ�˵�
void ShowMenu()
{
    cout << "\n========== ˳�������˵� ==========" << endl;
    cout << "1.  ����˳���" << endl;
    cout << "2.  ����Ԫ��" << endl;
    cout << "3.  ɾ��Ԫ��" << endl;
    cout << "4.  ����Ԫ�أ���ֵ��" << endl;
    cout << "5.  ��ȡԪ�أ���λ�ã�" << endl;
    cout << "6.  ��ȡ˳�����" << endl;
    cout << "7.  ��ӡ˳���" << endl;
    cout << "8.  ����˳���" << endl;
    cout << "9.  ����˳���" << endl;
    cout << "10. ���˳���" << endl;
    cout << "11. �ж�˳����Ƿ�Ϊ��" << endl;
    cout << "12. �������ֵ" << endl;
    cout << "13. ������Сֵ" << endl;
    cout << "14. ȥ���ظ�Ԫ��" << endl;
    cout << "15. �ϲ���������˳���" << endl;
    cout << "0.  �˳�����" << endl;
    cout << "====================================" << endl;

}

int main()
{
    SqList L;
    InitList(L);
    
    int choice, n, position, elem;
    Status result;
    ShowMenu();
    while (true)
    {
        cout << "��ѡ�����: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1: // ����˳���
            cout << "������Ҫ������˳�����: ";
            cin >> n;
            CreateList(L, n);
            break;
            
        case 2: // ����Ԫ��
            cout << "���������λ�ã�1-" << (L.length + 1) << "��: ";
            cin >> position;
            cout << "����������Ԫ��ֵ: ";
            cin >> elem;
            result = ListInsert(L, position, elem);
            if (result == OK)
                cout << "����ɹ���" << endl;
            else
                cout << "����ʧ�ܣ�λ�ò��Ϸ���" << endl;
            break;
            
        case 3: // ɾ��Ԫ��
            cout << "������Ҫɾ����λ�ã�1-" << L.length << "��: ";
            cin >> position;
            result = ListDelete(L, position, elem);
            if (result == OK)
                cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ: " << elem << endl;
            else
                cout << "ɾ��ʧ�ܣ�λ�ò��Ϸ���" << endl;
            break;
            
        case 4: // ����Ԫ��
            cout << "������Ҫ���ҵ�Ԫ��ֵ: ";
            cin >> elem;
            position = LocateElem(L, elem);
            if (position != 0)
                cout << "Ԫ�� " << elem << " �ڵ� " << position << " ��λ��" << endl;
            else
                cout << "δ�ҵ�Ԫ�� " << elem << endl;
            break;
            
        case 5: // ��ȡԪ��
            cout << "������Ҫ��ȡ��λ�ã�1-" << L.length << "��: ";
            cin >> position;
            result = GetElem(L, position, elem);
            if (result == OK)
                cout << "�� " << position << " ��λ�õ�Ԫ��Ϊ: " << elem << endl;
            else
                cout << "��ȡʧ�ܣ�λ�ò��Ϸ���" << endl;
            break;
            
        case 6: // ��ȡ����
            cout << "˳�����Ϊ: " << ListLength(L) << endl;
            break;
            
        case 7: // ��ӡ˳���
            PrintList(L);
            break;
            
        case 8: // ����
            if (ListEmpty(L))
            {
                cout << "˳���Ϊ�գ��޷�����" << endl;
            }
            else
            {
                SortList(L);
                cout << "������ɣ�" << endl;
                PrintList(L);
            }
            break;
            
        case 9: // ����
            if (ListEmpty(L))
            {
                cout << "˳���Ϊ�գ��޷����ã�" << endl;
            }
            else
            {
                ReverseList(L);
                cout << "������ɣ�" << endl;
                PrintList(L);
            }
            break;
            
        case 10: // ���˳���
            ClearList(L);
            break;
            
        case 11: // �ж��Ƿ�Ϊ��
            if (ListEmpty(L))
                cout << "˳���Ϊ��" << endl;
            else
                cout << "˳���Ϊ�գ�����Ϊ: " << ListLength(L) << endl;
            break;
            
        case 12: // �������ֵ
            result = FindMax(L, elem);
            if (result == OK)
                cout << "˳�������ֵΪ: " << elem << endl;
            else
                cout << "˳���Ϊ�գ�" << endl;
            break;
            
        case 13: // ������Сֵ
            result = FindMin(L, elem);
            if (result == OK)
                cout << "˳������СֵΪ: " << elem << endl;
            else
                cout << "˳���Ϊ�գ�" << endl;
            break;
            
        case 14: // ȥ��
            if (ListEmpty(L))
            {
                cout << "˳���Ϊ�գ�" << endl;
            }
            else
            {
                RemoveDuplicate(L);
                cout << "ȥ����ɣ�" << endl;
                PrintList(L);
            }
            break;
            
        case 15: // �ϲ���������˳���
        {
            SqList L2;
            InitList(L2);
            cout << "������ڶ���˳���ĳ���: ";
            cin >> n;
            CreateList(L2, n);
            
            cout << "������˳����������..." << endl;
            SortList(L);
            SortList(L2);
            
            SqList L3 = MergeList(L, L2);
            cout << "�ϲ����˳���: ";
            PrintList(L3);
            
            DestroyList(L2);
            DestroyList(L3);
            break;
        }
            
        case 0: // �˳�
            DestroyList(L);
            cout << "�������˳�����лʹ�ã�" << endl;
            return 0;
            
        default:
            cout << "��Ч��ѡ�����������룡" << endl;
            break;
        }
    }
    
    return 0;
}

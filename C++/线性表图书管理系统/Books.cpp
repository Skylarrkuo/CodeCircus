#define MAXSIZE 100 // ���Ա���󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>

using namespace std;

typedef int Status;
typedef struct Book
{ // ����ͼ������Ԫ�صĽṹ��
    string id;
    string name;
    double price;
} Book;

typedef struct
{ // �������Ա������
    Book *elem;
    int length;
} SqList;

// 12�ֲ���
Status InitList(SqList *L)
{
    // �������Ա�
    L->elem = new Book[MAXSIZE];
    if (!L->elem)
        return ERROR;
    L->length = 0;
    return OK;
}

Status DestroyList(SqList *L)
{
    // �������Ա�L
    if (!L->elem)
        return ERROR;
    else
        delete[] L->elem;
    L->length = NULL;
    return OK;
}

Status ClearList(SqList &L)
{
    // �������Ա�L
    if (!L.elem)
        exit(OVERFLOW);
    else
        L.length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    // �п����Ա�L
    if (L.length == 0)
        return true;
    else
        return false;
}

Status DestroyList(SqList L)
{
    // �������Ա�LԪ�ظ���
    if (!L.elem)
        exit(OVERFLOW);
    else
        return L.length;
}

Status GetElem(SqList L, int i, Book &e)
{
    // ��e����L�е�i������Ԫ�ص�ֵ
    if (!L.elem)
        return ERROR;
    else if (i >= 1 && i <= L.length)
    {
        e = L.elem[i - 1];
        return OK;
    }
    else
        return OVERFLOW;
}

Status LocateElem(SqList L, Book &e)
{
    // �������Ա�L��Ԫ�ز�����λ��
    int i;
    if (!L.elem)
        return ERROR;
    else
        for (i = 0; i < L.length; i++)
        {
            if ((L.elem[i].id == e.id) && (L.elem[i].name == e.name) && (L.elem[i].price == e.price))
            {
                break;
            }
        }
    if (i == L.length)
        return ERROR;
    else
        return i + 1;
}

Status PriorElem(SqList L, Book cur_e, Book &Pre_e)
{
    // ȡcur_e�����Ա�L��ǰ��
    if (!L.elem)
        return ERROR;
    else if (LocateElem(L, cur_e) != 0 && LocateElem(L, cur_e) != 1)
        Pre_e = L.elem[LocateElem(L, cur_e) - 2];
    else
        return OVERFLOW;
    return OK;
}

Status NextElem(SqList L, Book cur_e, Book &Next_e)
{
    // ȡcur_e�����Ա�L�к��
    if (!L.elem)
        return ERROR;
    else if (LocateElem(L, cur_e) != 0 && LocateElem(L, cur_e) != L.length)
        Next_e = L.elem[LocateElem(L, cur_e)];
    else
        return OVERFLOW;
    return OK;
}

Status ListInsert(SqList &L, int i, Book e)
{
    // �����Ա�L��iλ��ǰ����Ԫ��e
    if (!L.elem && L.length == MAXSIZE) // �жϱ��Ƿ�����Լ��Ƿ��пռ�
        return ERROR;
    else
        for (int j = L.length - 1; j > i; j--)
            L.elem[j] = L.elem[j - 1];
    L.elem[i] = e;
    ++L.length;
    return OK;
}

Status ListDelete(SqList &L, int i)
{
    // ɾ�����Ա�L�е�i��Ԫ��
    if (!L.elem || L.length == MAXSIZE) // �жϱ��Ƿ�����Լ��Ƿ��пռ�
        return ERROR;
    else
        for (int j = i - 1; j < L.length; j++)
            L.elem[j] = L.elem[j + 1];
    --L.length;
    return OK;
}

Status TraverseList(SqList L)
{
    // �����Ա�L��ÿ���ڵ���б������
    if (!L.elem)
        exit(OVERFLOW);
    else
        for (int i = 0; i < L.length; i++)
            cout << L.elem[i].id << '\t' << L.elem[i].name << '\t' << '\t' << L.elem[i].price << endl;
    return OK;
}
// ���д���ļ�

void Output(SqList *L, const std::string &filename, string head_1, string head_2, string head_3)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << head_1 << "\t" << head_2 << "\t" << head_3 << std::endl;
        for (int i = 0; i < L->length; i++)
        {
            file << L->elem[i].id << "\t";
            file << L->elem[i].name << "\t";
            file << L->elem[i].price << std::endl;
        }
        file.close();
        std::cout << "����ɹ���" << std::endl;
    }
    else
    {
        std::cout << "����ʧ�ܣ�" << std::endl;
    }
}

int main()
{
    ifstream Read;
    int s = 1;
    string head_1, head_2, head_3, out, in;
    SqList L;
    int i, temp;
    Book e, Pre_e, Next_e;

    while (s != 0)
    {
        system("cls");
        cout << "===========��ӭʹ��ͼ�����ϵͳ=============" << endl;
        cout << "\t1.����ͼ���\t7.����ͼ���" << endl;
        cout << "\t2.����������\t8.ȡ������ǰ��" << endl;
        cout << "\t3.����������\t9.ȡ��������" << endl;
        cout << "\t4.����������\t10.���������" << endl;
        cout << "\t5.ɾ��������\t11.�鿴�������ݱ�" << endl;
        cout << "\t6.����ͼ���\t12.���Ϊ���˳�ϵͳ" << endl;
        cout << "==========�����Ӧ���ֽ��в���==========\n>>:";
        cin >> s;
        system("cls");
        switch (s)
        {
        case 1:
            SqList L;
            cout << (InitList(&L) ? "�����ɹ�" : "����ʧ��") << endl;
            sleep(1);
            break;
        case 2:
            if ((!L.elem) && L.length == NULL)
            {
                cout << "���󣡱����ڣ�" << endl;
            }
            else
            {
                i = 0;
                cout << "����Ҫ������ļ�����";
                cin >> in;
                Read.open(in);
                if (!Read)
                {
                    cout << "����δ�ҵ��ļ���" << endl;
                    sleep(1);
                    break;
                }
                Read >> head_1 >> head_2 >> head_3;
                while (!Read.eof())
                {
                    Read >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
                    i++;
                }
                L.length = i;
                cout << "����" << in << "��Ϣ���\n"
                     << endl;
                sleep(1);
                Read.close();
            }
            sleep(1);
            break;
        case 3:
            cout << "����Ҫ���ҵ�������ÿո����ÿ��Ԫ��\n"
                 << endl;
            cin >> e.id >> e.name >> e.price;
            temp = LocateElem(L, e);
            if (temp != (-1))
                cout << "����������ڱ����ǵ� " << temp << " ��\n"
                     << endl;
            else
                cout << "����������ڱ���δ�ҵ���\n"
                     << endl;
            system("pause");
            break;
        case 4:
            cout << "����Ҫ�����������ÿո����ÿ��Ԫ��\n>>:";
            cin >> e.id >> e.name >> e.price;
            cout << "\n������Ҫ����λ��\n>>:";
            cin >> i;
            temp = ListInsert(L, i, e);
            if (temp == 1)
                cout << "\n����ɹ���";
            else
                cout << "\n����ʧ�ܣ�";
            system("pause");
            break;
        case 5:
            cout << "����Ҫɾ������\n>>:";
            cin >> i;
            if (ListDelete(L, i) == OK)
                cout << "��ѡ��������ɾ����" << endl;
            else
                cout << "ͼ������ѡ��������ڣ�" << endl;
            system("pause");
            break;
        case 6:
            if (ListEmpty(L) == true)
                cout << "\nͼ����Ѿ��ǿյ��ˣ�";
            else
            {
                ClearList(L);
                cout << "\nͼ������ÿգ�" << endl;
            }
            system("pause");
            break;
        case 7:
            temp = DestroyList(&L);
            if (temp == OK)
                cout << "\n���ٳɹ���";
            else
                cout << "\n����ʧ�ܣ�";
            system("pause");
            break;
        case 8:
            cout << "����Ҫ��������\n>>:";
            cin >> i;
            system("cls");
            if (GetElem(L, i, e) != 1)
                cout << "������/������������ڣ�" << endl;
            else
            {
                cout << "��" << i << "������Ϊ\n"
                     << e.id << '\t' << e.name << '\t' << e.price << '\t' << endl;
                if (PriorElem(L, e, Pre_e) == (-1))
                    cout << "����������û��ǰ���" << endl;
                else
                    cout << "ǰ��������Ϊ\n"
                         << Pre_e.id << '\t' << Pre_e.name << '\t' << Pre_e.price << '\t' << endl;
            }
            cout << "��" << i << "������Ϊ\n"
                 << e.id << '\t' << e.name << '\t' << e.price << '\t' << endl;
            if (PriorElem(L, e, Pre_e) == (-1))
                cout << "����������û��ǰ���" << endl;
            else
                cout << "ǰ��������Ϊ\n"
                     << Pre_e.id << '\t' << Pre_e.name << '\t' << Pre_e.price << '\t' << endl;
            system("pause");
            break;
        case 9:
            cout << "����Ҫ��������\n>>:";
            cin >> i;
            system("cls");
            if (GetElem(L, i, e) != 1)
                cout << "������/������������ڣ�" << endl;
            else
            {
                cout << "��" << i << "������Ϊ\n"
                     << e.id << '\t' << e.name << '\t' << e.price << '\t' << endl;
                if (NextElem(L, e, Next_e) == (-1))
                    cout << "����������û�к���" << endl;
                else
                    cout << "���������Ϊ\n"
                         << Next_e.id << '\t' << Next_e.name << '\t' << Next_e.price << '\t' << endl;
            }
            system("pause");
            break;
        case 10:
            cout << "��ǰͼ����й���" << DestroyList(L) << "������" << endl;
            system("pause");
            break;
        case 11:
            if (ListEmpty(L) == true || L.elem)
            {
                cout << head_1 << '\t' << '\t' << head_2 << '\t' << '\t' << '\t' << head_3 << endl;
                TraverseList(L);
            }
            else
                cout << "\nͼ���Ϊ�ջ򲻴��ڣ���" << endl;
            system("pause");
            break;
        case 12:
            cout << "\n����Ҫ����Ϊ���ļ�����" << endl;
            cin >> out;
            Output(&L, out, head_1, head_2, head_3);
            cout << "\n��лʹ�ã���" << endl;
            sleep(3);
            s = 0;
            break;
        default:
            cout << "\n��Ч�����룡��" << endl;
            sleep(3);
        }
    }
    return 0;
}

#define MAXSIZE 100 // 线性表最大长度
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
{ // 声明图书数据元素的结构体
    string id;
    string name;
    double price;
} Book;

typedef struct
{ // 声明线性表操作器
    Book *elem;
    int length;
} SqList;

// 12种操作
Status InitList(SqList *L)
{
    // 构建线性表
    L->elem = new Book[MAXSIZE];
    if (!L->elem)
        return ERROR;
    L->length = 0;
    return OK;
}

Status DestroyList(SqList *L)
{
    // 销毁线性表L
    if (!L->elem)
        return ERROR;
    else
        delete[] L->elem;
    L->length = NULL;
    return OK;
}

Status ClearList(SqList &L)
{
    // 重置线性表L
    if (!L.elem)
        exit(OVERFLOW);
    else
        L.length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    // 判空线性表L
    if (L.length == 0)
        return true;
    else
        return false;
}

Status DestroyList(SqList L)
{
    // 返回线性表L元素个数
    if (!L.elem)
        exit(OVERFLOW);
    else
        return L.length;
}

Status GetElem(SqList L, int i, Book &e)
{
    // 用e返回L中第i个数据元素的值
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
    // 查找线性表L中元素并返回位置
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
    // 取cur_e在线性表L中前驱
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
    // 取cur_e在线性表L中后继
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
    // 在线性表L的i位置前插入元素e
    if (!L.elem && L.length == MAXSIZE) // 判断表是否存在以及是否有空间
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
    // 删除线性表L中第i个元素
    if (!L.elem || L.length == MAXSIZE) // 判断表是否存在以及是否有空间
        return ERROR;
    else
        for (int j = i - 1; j < L.length; j++)
            L.elem[j] = L.elem[j + 1];
    --L.length;
    return OK;
}

Status TraverseList(SqList L)
{
    // 对线性表L的每个节点进行遍历输出
    if (!L.elem)
        exit(OVERFLOW);
    else
        for (int i = 0; i < L.length; i++)
            cout << L.elem[i].id << '\t' << L.elem[i].name << '\t' << '\t' << L.elem[i].price << endl;
    return OK;
}
// 输出写入文件

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
        std::cout << "保存成功！" << std::endl;
    }
    else
    {
        std::cout << "保存失败！" << std::endl;
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
        cout << "===========欢迎使用图书管理系统=============" << endl;
        cout << "\t1.建立图书表\t7.销毁图书表" << endl;
        cout << "\t2.输入数据项\t8.取数据项前驱" << endl;
        cout << "\t3.查找数据项\t9.取数据项后继" << endl;
        cout << "\t4.插入数据项\t10.数据项个数" << endl;
        cout << "\t5.删除数据项\t11.查看完整数据表" << endl;
        cout << "\t6.重置图书表\t12.另存为并退出系统" << endl;
        cout << "==========输入对应数字进行操作==========\n>>:";
        cin >> s;
        system("cls");
        switch (s)
        {
        case 1:
            SqList L;
            cout << (InitList(&L) ? "创建成功" : "创建失败") << endl;
            sleep(1);
            break;
        case 2:
            if ((!L.elem) && L.length == NULL)
            {
                cout << "错误！表不存在！" << endl;
            }
            else
            {
                i = 0;
                cout << "输入要读入的文件名：";
                cin >> in;
                Read.open(in);
                if (!Read)
                {
                    cout << "错误！未找到文件！" << endl;
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
                cout << "输入" << in << "信息完毕\n"
                     << endl;
                sleep(1);
                Read.close();
            }
            sleep(1);
            break;
        case 3:
            cout << "输入要查找的数据项，用空格隔开每个元素\n"
                 << endl;
            cin >> e.id >> e.name >> e.price;
            temp = LocateElem(L, e);
            if (temp != (-1))
                cout << "输入的数据在表中是第 " << temp << " 项\n"
                     << endl;
            else
                cout << "输入的数据在表中未找到！\n"
                     << endl;
            system("pause");
            break;
        case 4:
            cout << "输入要插入的数据项，用空格隔开每个元素\n>>:";
            cin >> e.id >> e.name >> e.price;
            cout << "\n输入想要插入位置\n>>:";
            cin >> i;
            temp = ListInsert(L, i, e);
            if (temp == 1)
                cout << "\n插入成功！";
            else
                cout << "\n插入失败！";
            system("pause");
            break;
        case 5:
            cout << "输入要删除的项\n>>:";
            cin >> i;
            if (ListDelete(L, i) == OK)
                cout << "所选数据项已删除！" << endl;
            else
                cout << "图书表或所选数据项不存在！" << endl;
            system("pause");
            break;
        case 6:
            if (ListEmpty(L) == true)
                cout << "\n图书表已经是空的了！";
            else
            {
                ClearList(L);
                cout << "\n图书表已置空！" << endl;
            }
            system("pause");
            break;
        case 7:
            temp = DestroyList(&L);
            if (temp == OK)
                cout << "\n销毁成功！";
            else
                cout << "\n销毁失败！";
            system("pause");
            break;
        case 8:
            cout << "输入要检索的项\n>>:";
            cin >> i;
            system("cls");
            if (GetElem(L, i, e) != 1)
                cout << "表不存在/这条数据项不存在！" << endl;
            else
            {
                cout << "第" << i << "项数据为\n"
                     << e.id << '\t' << e.name << '\t' << e.price << '\t' << endl;
                if (PriorElem(L, e, Pre_e) == (-1))
                    cout << "这条数据项没有前驱项！" << endl;
                else
                    cout << "前驱数据项为\n"
                         << Pre_e.id << '\t' << Pre_e.name << '\t' << Pre_e.price << '\t' << endl;
            }
            cout << "第" << i << "项数据为\n"
                 << e.id << '\t' << e.name << '\t' << e.price << '\t' << endl;
            if (PriorElem(L, e, Pre_e) == (-1))
                cout << "这条数据项没有前驱项！" << endl;
            else
                cout << "前驱数据项为\n"
                     << Pre_e.id << '\t' << Pre_e.name << '\t' << Pre_e.price << '\t' << endl;
            system("pause");
            break;
        case 9:
            cout << "输入要检索的项\n>>:";
            cin >> i;
            system("cls");
            if (GetElem(L, i, e) != 1)
                cout << "表不存在/这条数据项不存在！" << endl;
            else
            {
                cout << "第" << i << "项数据为\n"
                     << e.id << '\t' << e.name << '\t' << e.price << '\t' << endl;
                if (NextElem(L, e, Next_e) == (-1))
                    cout << "这条数据项没有后继项！" << endl;
                else
                    cout << "后继数据项为\n"
                         << Next_e.id << '\t' << Next_e.name << '\t' << Next_e.price << '\t' << endl;
            }
            system("pause");
            break;
        case 10:
            cout << "当前图书表中共有" << DestroyList(L) << "条数据" << endl;
            system("pause");
            break;
        case 11:
            if (ListEmpty(L) == true || L.elem)
            {
                cout << head_1 << '\t' << '\t' << head_2 << '\t' << '\t' << '\t' << head_3 << endl;
                TraverseList(L);
            }
            else
                cout << "\n图书表为空或不存在！！" << endl;
            system("pause");
            break;
        case 12:
            cout << "\n输入要保存为的文件名：" << endl;
            cin >> out;
            Output(&L, out, head_1, head_2, head_3);
            cout << "\n感谢使用！！" << endl;
            sleep(3);
            s = 0;
            break;
        default:
            cout << "\n无效的输入！！" << endl;
            sleep(3);
        }
    }
    return 0;
}

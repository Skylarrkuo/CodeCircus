#define MAXSIZE 100 // 最大容量
#define ERROR 0
#define OK 1
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Status;

// 顺序表结构定义
typedef struct
{
    int *elem;     // 存储空间基址
    int length;    // 当前长度
    int listsize;  // 当前分配的存储容量
} SqList;

// 初始化顺序表
Status InitList(SqList &L)
{
    L.elem = new int[MAXSIZE];
    if (!L.elem)
        return OVERFLOW;
    L.length = 0;
    L.listsize = MAXSIZE;
    cout << "顺序表初始化成功！" << endl;
    return OK;
}

// 销毁顺序表
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

// 清空顺序表
void ClearList(SqList &L)
{
    L.length = 0;
    cout << "顺序表已清空！" << endl;
}

// 判断顺序表是否为空
bool ListEmpty(SqList L)
{
    return L.length == 0;
}

// 获取顺序表长度
int ListLength(SqList L)
{
    return L.length;
}

// 获取指定位置的元素
Status GetElem(SqList L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

// 查找元素（返回第一个匹配的位置）
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1; // 返回位序（从1开始）
    }
    return 0; // 未找到
}

// 在指定位置插入元素
Status ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listsize)
    {
        cout << "顺序表已满，无法插入！" << endl;
        return ERROR;
    }
    
    // 将第i个位置及之后的元素后移
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

// 删除指定位置的元素
Status ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    
    e = L.elem[i - 1];
    
    // 将第i个位置之后的元素前移
    for (int j = i; j < L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;
}

// 创建顺序表
void CreateList(SqList &L, int n)
{
    if (n <= 0 || n > MAXSIZE)
    {
        cout << "输入的长度不合法！" << endl;
        return;
    }
    
    cout << "请依次输入" << n << "个数据：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "第" << (i + 1) << "个数据: ";
        cin >> L.elem[i];
    }
    L.length = n;
    cout << "顺序表创建成功！" << endl;
}

// 打印顺序表
void PrintList(SqList L)
{
    if (L.length == 0)
    {
        cout << "顺序表为空！" << endl;
        return;
    }
    
    cout << "顺序表内容: ";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// 顺序表排序（冒泡排序）
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

// 逆置顺序表
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

// 查找最大值
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

// 查找最小值
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

// 合并两个有序顺序表
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

// 去重（保留第一次出现的元素）
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

// 显示菜单
void ShowMenu()
{
    cout << "\n========== 顺序表操作菜单 ==========" << endl;
    cout << "1.  创建顺序表" << endl;
    cout << "2.  插入元素" << endl;
    cout << "3.  删除元素" << endl;
    cout << "4.  查找元素（按值）" << endl;
    cout << "5.  获取元素（按位置）" << endl;
    cout << "6.  获取顺序表长度" << endl;
    cout << "7.  打印顺序表" << endl;
    cout << "8.  排序顺序表" << endl;
    cout << "9.  逆置顺序表" << endl;
    cout << "10. 清空顺序表" << endl;
    cout << "11. 判断顺序表是否为空" << endl;
    cout << "12. 查找最大值" << endl;
    cout << "13. 查找最小值" << endl;
    cout << "14. 去除重复元素" << endl;
    cout << "15. 合并两个有序顺序表" << endl;
    cout << "0.  退出程序" << endl;
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
        cout << "请选择操作: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1: // 创建顺序表
            cout << "请输入要创建的顺序表长度: ";
            cin >> n;
            CreateList(L, n);
            break;
            
        case 2: // 插入元素
            cout << "请输入插入位置（1-" << (L.length + 1) << "）: ";
            cin >> position;
            cout << "请输入插入的元素值: ";
            cin >> elem;
            result = ListInsert(L, position, elem);
            if (result == OK)
                cout << "插入成功！" << endl;
            else
                cout << "插入失败！位置不合法。" << endl;
            break;
            
        case 3: // 删除元素
            cout << "请输入要删除的位置（1-" << L.length << "）: ";
            cin >> position;
            result = ListDelete(L, position, elem);
            if (result == OK)
                cout << "删除成功！删除的元素为: " << elem << endl;
            else
                cout << "删除失败！位置不合法。" << endl;
            break;
            
        case 4: // 查找元素
            cout << "请输入要查找的元素值: ";
            cin >> elem;
            position = LocateElem(L, elem);
            if (position != 0)
                cout << "元素 " << elem << " 在第 " << position << " 个位置" << endl;
            else
                cout << "未找到元素 " << elem << endl;
            break;
            
        case 5: // 获取元素
            cout << "请输入要获取的位置（1-" << L.length << "）: ";
            cin >> position;
            result = GetElem(L, position, elem);
            if (result == OK)
                cout << "第 " << position << " 个位置的元素为: " << elem << endl;
            else
                cout << "获取失败！位置不合法。" << endl;
            break;
            
        case 6: // 获取长度
            cout << "顺序表长度为: " << ListLength(L) << endl;
            break;
            
        case 7: // 打印顺序表
            PrintList(L);
            break;
            
        case 8: // 排序
            if (ListEmpty(L))
            {
                cout << "顺序表为空，无法排序！" << endl;
            }
            else
            {
                SortList(L);
                cout << "排序完成！" << endl;
                PrintList(L);
            }
            break;
            
        case 9: // 逆置
            if (ListEmpty(L))
            {
                cout << "顺序表为空，无法逆置！" << endl;
            }
            else
            {
                ReverseList(L);
                cout << "逆置完成！" << endl;
                PrintList(L);
            }
            break;
            
        case 10: // 清空顺序表
            ClearList(L);
            break;
            
        case 11: // 判断是否为空
            if (ListEmpty(L))
                cout << "顺序表为空" << endl;
            else
                cout << "顺序表不为空，长度为: " << ListLength(L) << endl;
            break;
            
        case 12: // 查找最大值
            result = FindMax(L, elem);
            if (result == OK)
                cout << "顺序表的最大值为: " << elem << endl;
            else
                cout << "顺序表为空！" << endl;
            break;
            
        case 13: // 查找最小值
            result = FindMin(L, elem);
            if (result == OK)
                cout << "顺序表的最小值为: " << elem << endl;
            else
                cout << "顺序表为空！" << endl;
            break;
            
        case 14: // 去重
            if (ListEmpty(L))
            {
                cout << "顺序表为空！" << endl;
            }
            else
            {
                RemoveDuplicate(L);
                cout << "去重完成！" << endl;
                PrintList(L);
            }
            break;
            
        case 15: // 合并两个有序顺序表
        {
            SqList L2;
            InitList(L2);
            cout << "请输入第二个顺序表的长度: ";
            cin >> n;
            CreateList(L2, n);
            
            cout << "对两个顺序表进行排序..." << endl;
            SortList(L);
            SortList(L2);
            
            SqList L3 = MergeList(L, L2);
            cout << "合并后的顺序表: ";
            PrintList(L3);
            
            DestroyList(L2);
            DestroyList(L3);
            break;
        }
            
        case 0: // 退出
            DestroyList(L);
            cout << "程序已退出，感谢使用！" << endl;
            return 0;
            
        default:
            cout << "无效的选择，请重新输入！" << endl;
            break;
        }
    }
    
    return 0;
}

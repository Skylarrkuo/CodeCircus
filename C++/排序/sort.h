#define MAXSIZE 100 // 线性表最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW (-1)
using namespace std;

//===============存储结构================
typedef struct ElemType
{ // 声明数据元素的结构体
    int data;
} ElemType;
typedef struct
{ // 声明线性表操作器
    ElemType *elem;
    int length;
} SqList;
//====================================

//==============线性表操作===============
void CreatSqList(SqList &L, int n)
{
    // 手动创建顺序表
    L.elem = new ElemType[MAXSIZE + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> L.elem[i].data;
    }
    L.length = n;
}
void BackSqList(SqList &L,SqList &back){
    //备份线性表
    for (int i = 0; i <= L.length;++i){
        back.elem[i].data = L.elem[i].data;
    }
}
void BackP(SqList &L,SqList &back){
    //恢复备份线性表
    for (int i = 0; i <= L.length;++i){
         L.elem[i].data=back.elem[i].data;
    }
}
//====================================

//=============排序算法================
typedef int Status;
Status InsertSort(SqList &L)
{
    // 对顺序表L做直接插入排序
    int i, j;
    for (i = 2; i <= L.length; ++i)
    {
        if (L.elem[i].data < L.elem[i - 1].data)
        {
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[i - 1];
            for (j = i - 2; L.elem[0].data < L.elem[j].data; --j)
                L.elem[j + 1] = L.elem[j];
            L.elem[j + 1] = L.elem[0];
        }
    }
    return OK;
}
Status BubbleSort(SqList &L)
{
    // 对顺序表L做冒泡排序
    int i, j;
    for (i = 1; i < L.length; ++i)
    {
        for (j = i; j <= L.length - i; ++j)
        {
            if (L.elem[j].data > L.elem[j].data)
            {
                L.elem[0].data = L.elem[j].data;
                L.elem[j].data = L.elem[j + 1].data;
                L.elem[j + 1].data = L.elem[0].data;
            }
        }
    }
    return OK;
}
Status BInsertSort(SqList &L)
{
    // 对顺序表L进行折半插入排序
    int i, j, low, high, m;
    for (i = 2; i <= L.length; ++i)
    {
        L.elem[0] = L.elem[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (L.elem[0].data < L.elem[m].data)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
            L.elem[j + 1] = L.elem[j];
        L.elem[high + 1] = L.elem[0];
    }
    return OK;
}
Status ShellInsert(SqList &L)
{
    // 对顺序表L进行一趟希尔增量排序
    return OK;
}

//====================================
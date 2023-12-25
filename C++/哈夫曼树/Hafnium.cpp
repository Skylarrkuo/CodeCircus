#include <iostream>
using namespace std;

// 定义哈夫曼树结点结构体
typedef struct
{
    int weight;                 // 权重
    int parent, lchild, rchild; // 双亲,左孩子,右孩子的索引
} HTNode, *HuffmanTree;

// 在数组HT中选择两个parent为0且权值最小的结点,其索引分别为s1和s2
void Select(HuffmanTree &HT, int end, int &s1, int &s2)
{
    int min1, min2;
    // 初始化最小和次小权重
    min1 = min2 = INT_MAX;
    // 初始化最小和次小权重对应的索引
    s1 = s2 = 0;
    for (int i = 1; i <= end; ++i)
    {
        if (HT[i].parent == 0)
        {
            if (HT[i].weight < min1)
            {
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            }
            else if (HT[i].weight < min2)
            {
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}

// 构造哈夫曼树HT
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1; // 哈夫曼树总结点数
    HT = new HTNode[m + 1];
    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> HT[i].weight; // 输入叶子结点的权值
    for (int i = n + 1; i <= m; ++i)
    { // 通过n-1次的选择,删除,合并来创建哈夫曼树
        int s1, s2;
        Select(HT, i - 1, s1, s2); // 选择权值最小和次小的两个结点
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight; // 新结点的权值为左右孩子权值之和
    }
}

int main()
{
    HuffmanTree HT;
    int n; // 假设有5个叶子节点
    cout << "输入叶子节点数:";
    cin >> n;
    cout << "输入" << n << "个叶子节点的权:";
    CreateHuffmanTree(HT, n);
    cout << "构建哈夫曼树的结果:";
        // 打印哈夫曼树的结果
        for (int i = 1; i <= 2 * n - 1; ++i)
    {
        cout << "Index: " << i << ", Weight: " << HT[i].weight << ", Parent: " << HT[i].parent << ", Left Child: " << HT[i].lchild << ", Right Child: " << HT[i].rchild << endl;
    }

    delete[] HT; // 释放内存

    return 0;
}

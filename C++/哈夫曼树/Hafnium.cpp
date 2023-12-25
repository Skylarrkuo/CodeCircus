#include <iostream>
using namespace std;

// ��������������ṹ��
typedef struct
{
    int weight;                 // Ȩ��
    int parent, lchild, rchild; // ˫��,����,�Һ��ӵ�����
} HTNode, *HuffmanTree;

// ������HT��ѡ������parentΪ0��Ȩֵ��С�Ľ��,�������ֱ�Ϊs1��s2
void Select(HuffmanTree &HT, int end, int &s1, int &s2)
{
    int min1, min2;
    // ��ʼ����С�ʹ�СȨ��
    min1 = min2 = INT_MAX;
    // ��ʼ����С�ʹ�СȨ�ض�Ӧ������
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

// �����������HT
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1; // ���������ܽ����
    HT = new HTNode[m + 1];
    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> HT[i].weight; // ����Ҷ�ӽ���Ȩֵ
    for (int i = n + 1; i <= m; ++i)
    { // ͨ��n-1�ε�ѡ��,ɾ��,�ϲ���������������
        int s1, s2;
        Select(HT, i - 1, s1, s2); // ѡ��Ȩֵ��С�ʹ�С���������
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight; // �½���ȨֵΪ���Һ���Ȩֵ֮��
    }
}

int main()
{
    HuffmanTree HT;
    int n; // ������5��Ҷ�ӽڵ�
    cout << "����Ҷ�ӽڵ���:";
    cin >> n;
    cout << "����" << n << "��Ҷ�ӽڵ��Ȩ:";
    CreateHuffmanTree(HT, n);
    cout << "�������������Ľ��:";
        // ��ӡ���������Ľ��
        for (int i = 1; i <= 2 * n - 1; ++i)
    {
        cout << "Index: " << i << ", Weight: " << HT[i].weight << ", Parent: " << HT[i].parent << ", Left Child: " << HT[i].lchild << ", Right Child: " << HT[i].rchild << endl;
    }

    delete[] HT; // �ͷ��ڴ�

    return 0;
}

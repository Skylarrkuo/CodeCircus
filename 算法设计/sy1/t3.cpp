#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1; // 定义一个int型动态数组

    for (int i = 1; i <= 5; i++)
        g1.push_back(i); // 末端插入

    cout << "Size : " << g1.size() << endl;         // 元素个数   5
    cout << "Capacity : " << g1.capacity() << endl; // 存储空间大小  6(通常比元素个数大一点)
    cout << "Max_Size : " << g1.max_size() << endl; // 容纳最大的元素数量 4611686018427387903

    return 0;
}
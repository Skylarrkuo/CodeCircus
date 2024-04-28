
#include <iostream>

int BinSearch(int r[], int n, int k)
{
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (k < r[mid])
            high = mid - 1;
        else if (k > r[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1; // 表示未找到
}


int main()
{
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 定义物品结构体，包含重量、价值和索引
struct Item {
    int weight;
    int value;
    int index;
};

// 定义节点结构体，用于分支限界法的节点
struct Node {
    int level;       // 当前节点的层次
    int profit;      // 当前节点的总价值
    int weight;      // 当前节点的总重量
    float bound;     // 当前节点的上界
    vector<int> items; // 当前节点选中的物品列表
};

// 比较函数，用于按性价比（价值/重量）排序物品
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// 计算节点的上界
float bound(Node u, int n, int W, vector<Item>& items) {
    // 如果节点重量超过背包容量，则上界为0
    if (u.weight >= W)
        return 0;
    
    // 初始上界为当前节点的总价值
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    // 尽可能地装入物品，直到背包容量用完
    while ((j < n) && (totweight + items[j].weight <= W)) {
        totweight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    // 如果还有剩余容量，装入部分物品
    if (j < n)
        profit_bound += (W - totweight) * items[j].value / (double)items[j].weight;

    return profit_bound;
}

// 分支限界法解决0/1背包问题
void knapsack(int W, vector<Item>& items, int n) {
    // 按性价比降序排序物品
    sort(items.begin(), items.end(), compare);

    // 定义队列用于广度优先搜索
    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    u.items = {};

    // 将根节点入队
    Q.push(u);

    int maxProfit = 0;
    vector<int> bestItems;

    // 进行广度优先搜索
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        // 初始化v节点，表示下一个层次
        if (u.level == -1)
            v.level = 0;

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
        v.items = u.items;
        v.items.push_back(items[v.level].index);

        // 如果当前节点重量不超过背包容量且总价值大于当前最大价值，更新最大价值和选中物品列表
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
            bestItems = v.items;
        }

        // 计算上界，如果上界大于当前最大价值，将节点入队
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            Q.push(v);

        // 不选该物品的情况
        v.weight = u.weight;
        v.profit = u.profit;
        v.items = u.items;

        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    // 输出最大价值和选中的物品编号
    cout << maxProfit << endl;
    for (int i : bestItems) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<Item> items(n);

    // 读取物品重量
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }

    // 读取物品价值，并设置物品索引
    for (int i = 0; i < n; i++) {
        cin >> items[i].value;
        items[i].index = i;
    }

    int W;
    cin >> W;

    // 调用分支限界法解决背包问题
    knapsack(W, items, n);

    return 0;
}
